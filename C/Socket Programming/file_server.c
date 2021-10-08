#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

void error(const char* msg) {
    perror(msg);
    exit(1);
}

int connectToServer(char *argv[], int *sockfd) {
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t cli_len;

    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0)
        error("socket() failed");

    bzero((char*)&serv_addr, sizeof(serv_addr));
    int portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(*sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
        error("bind() failed");

    listen(*sockfd, 2);
    cli_len = sizeof(cli_addr);

    int newsockfd = accept(*sockfd, (struct sockaddr*) &cli_addr, &cli_len);
    if (newsockfd < 0)
        error("accept() failed");

    return newsockfd;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <portno>\n", argv[0]);
        exit(1);
    }

    int sockfd, newsockfd;
    newsockfd = connectToServer(argv, &sockfd);

    printf("Client and Server are now connected.\n");

    FILE *fp;
    int ch = 0;
    fp = fopen("glad_received.txt", "a");
    int words;
    char buffer[255];

    read(newsockfd, &words, sizeof(words));

    while ((ch != words)) {
        read(newsockfd, buffer, sizeof(buffer));
        fprintf(fp, "%s ", buffer);
        ch++;
    }
    printf("File successfully received as glad_received.txt\n");
    close(newsockfd);
    close(sockfd);

    return 0;
}
