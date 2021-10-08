#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

void error(const char* msg) {
    perror(msg);
    exit(1);
}

int connectToClient(char *argv[]) {
    struct sockaddr_in serv_addr;
    struct hostent *server;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("socket() failed");

    server = gethostbyname(argv[1]);
    int portno = atoi(argv[2]);
    if (server == NULL)
        error("gethostbyname() failed");

    bzero((char*) &serv_addr, sizeof(serv_addr));

    // The three attributes
    serv_addr.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
        error("connect() failed");
    return sockfd;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <hostname> <portno>\n", argv[0]);
        exit(1);
    }

    int sockfd = connectToClient(argv);
    printf("Server and client are now connected.\n");

    FILE *f;
    int words = 0;
    char c;
    char buffer[255];

    f = fopen("glad.txt", "r");
    while((c = fgetc(f)) != EOF) {
        // fscanf(f, "%s", buffer);
        if (c == ' ' || c == '\t')
            words++;
    }
    words++;
    write(sockfd, &words, sizeof(int));
    rewind(f);

    char ch;
    while (ch != EOF) {
        fscanf(f, "%s", buffer);
        write(sockfd, buffer, sizeof(buffer));
        ch = fgetc(f);
    }
    printf("The file has been sent successfully\n");

    close(sockfd);
    return 0;
}
