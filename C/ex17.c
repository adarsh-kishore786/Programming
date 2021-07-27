#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct Address
{
	int id;
	int set;
	char *name;
	char *email;
} Address;

typedef struct Database
{
	Address *rows;
	int MAX_DATA;
	int MAX_ROWS;
} Database;

typedef struct Connection
{
	FILE *file;
	Database *db;
} Connection;

void Database_close(Connection *conn)
{
	if (conn)
	{
		if (conn->file)
			fclose(conn->file);
		if (conn->db)
			free(conn->db);
		free(conn);
	}
}

void die(const char *message, Connection *conn)
{
	Database_close(conn);

	if (errno)
		perror(message);
	else
		printf("ERROR: %s\n", message);

	exit(1);
}

void Address_print(Address *addr)
{
	printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(Connection *conn)
{
	int rc = fread(conn->db, sizeof(Database), 1, conn->file);

	if (rc != 1)	
		die("Failed to load database.", conn);
}

Connection* Database_open(const char *filename, char mode, int argc, char *argv[])
{
	Connection *conn = malloc(sizeof(Connection));

	if (!conn)
		die("Memory error.", conn);

	conn->db = malloc(sizeof(Database));

	if (!conn->db)
		die("Memory error.", conn);	

	if (mode == 'c')
	{
		if (argc < 5)
			die("ERROR: Syntax: ex17 <dbfile> c <MAX_DATA> <MAX_ROWS>", conn);
		conn->db->MAX_DATA = atoi(argv[3]);
		conn->db->MAX_ROWS = atoi(argv[4]);

		conn->file = fopen(filename, "w");
	}
	else
	{
		conn->file = fopen(filename, "rb+");
		if (conn->file)
			Database_load(conn);
	}
	if (!conn->file)
		die("Failed to load the file.", conn);

	return conn;
}

void Database_write(Connection *conn)
{
	rewind(conn->file);

	int rc = fwrite(conn->db, sizeof(Database), 1, conn->file);

	if (rc != 1)
		die("Failed to write database.", conn);

	rc = fflush(conn->file);
	if (rc == -1)
		die("Cannot flush database", conn);
}

void Database_create(Connection *conn)
{
	for (int i = 0; i < conn->db->MAX_ROWS; i++)
	{
		// Make a prototype to initialize it
		Address addr = {.id = i, .set = 0};
		addr.name = malloc(conn->db->MAX_DATA * sizeof(char));
		addr.email = malloc(conn->db->MAX_DATA * sizeof(char));
		// then just assign it
		conn->db->rows[i] = addr;
	}
}

void Database_set(Connection *conn, int id, const char *name,
					const char *email)
{
	Address *addr = &conn->db->rows[id];
	if (addr->set)
		die("Already set, delete it first.", conn);

	addr->set = 1;

	char *res = strncpy(addr->name, name, conn->db->MAX_DATA);
	res[strlen(res)] = '\0'; 

	if (!res)
		die("Name copy failed.", conn);

	res = strncpy(addr->email, email, conn->db->MAX_DATA);
	if (!res)
		die("Email copy failed.", conn);
}

void Database_get(Connection *conn, int id)
{
	Address *addr = &conn->db->rows[id];

	if (addr->set)
		Address_print(addr);
	else
		die("ID is not set.", conn);
}

void Database_delete(Connection *conn, int id)
{
	Address addr = {.id = id, .set = 0};
	conn->db->rows[id] = addr;
}

void Database_list(Connection *conn)
{
	Database *db = conn->db;
	for (int i = 0; i < db->MAX_ROWS; i++)
	{
		Address *cur = &(db->rows[i]);

		if (cur->set)
			Address_print(cur);
	}
}

int main(int argc, char *argv[])
{
	if (argc < 3)
		die("USAGE: ex17 <dbfile> <action> [action params]", NULL);

	char *filename = argv[1];
	char action = argv[2][0];
	Connection *conn = Database_open(filename, action, argc, argv);
	int id = 0;

	if (action != 'c')
		id = atoi(argv[3]);
	if (id >= conn->db->MAX_ROWS)
		die("There's not that many records.", conn);

	switch (action) 
	{
		case 'c': Database_create(conn);
				  Database_write(conn);
				  break;
		case 'g': if (argc != 4)
				      die("Need an id to get.", conn);
				  Database_get(conn, id);
				  break;
		case 's': if (argc != 6)
				      die("Need id, name, email to set.", conn);

				  Database_set(conn, id, argv[4], argv[5]);
				  Database_write(conn);
				  break;
		case 'd': if (argc != 4)
			  	      die("Need id to delete.", conn);

			  	  Database_delete(conn, id);
			  	  Database_write(conn);
			  	  break;
		case 'l': Database_list(conn);
		   		  break;
		default:  die("Invalid action: c = create, g = get, s = set, d = del, l = list", conn);
	}
	Database_close(conn);

	return 0;
}