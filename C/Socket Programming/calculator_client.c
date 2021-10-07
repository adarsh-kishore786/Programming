#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int connectClient(char *argv[]) {
    struct sockaddr_in serv_addr;
    struct hostent *server;

    int portno = atoi(argv[2]);
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
        error("socket() failed");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Invalid host name.\n");
        exit(1);
    }

    bzero((char*)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;

    bcopy((char*) server->h_addr, (char*) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
        error("connect() failed");
    return sockfd;
}

void readMessage(int sockfd) {
    char buffer[255];
    bzero(buffer, sizeof(buffer));
    read(sockfd, &buffer, sizeof(buffer));
    printf("%s", buffer);
}

void writeMessage(int sockfd, int num) {
    int n = write(sockfd, &num, sizeof(int));
    if (n < 0) error("write() failed");
}

void calc(int sockfd) {
    int num1, num2;
    char choice;
    char buffer[255];

    while (1) {
        readMessage(sockfd);

        bzero(buffer, sizeof(buffer));
        sscanf(fgets(buffer, sizeof(buffer), stdin), "%d", &num1);

        writeMessage(sockfd, num1);
        readMessage(sockfd);

        bzero(buffer, sizeof(buffer));
        sscanf(fgets(buffer, sizeof(buffer), stdin), "%d", &num2);

        writeMessage(sockfd, num2);
        readMessage(sockfd);

        bzero(buffer, sizeof(buffer));
        sscanf(fgets(buffer, sizeof(buffer), stdin), "%c", &choice);

        int n = write(sockfd, &choice, sizeof(char));
        if (n < 0) error("write() failed");

        if (choice == 'q')
            break;
        if (choice != '+' && choice != '-' && choice != '*' && choice != '/' && choice != '%') {
            printf("This is not a valid operator. Please try again.\n\n");
            continue;
        }

        int answer;
        read(sockfd, &answer, sizeof(int));
        printf("%d %c %d = %d\n\n", num1, choice, num2, answer);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Error. Usage: %s <hostname> <portno>\n", argv[0]);
        exit(1);
    }

    int sockfd = connectClient(argv);
    printf("Client and server are now connected.\n");
    calc(sockfd);

    close(sockfd);
}
