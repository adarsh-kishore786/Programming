#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int getCalc(int num1, int num2, char op) {
    switch (op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2;
        case '%': return num1 % num2;
    }
    return num1+num2;
}

void writeMessage(int sockfd, char* buffer) {
    int n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) error("write() failed");
}

void calc(int newsockfd) {
    int num1, num2, answer;
    char choice;

    while (1) {
        writeMessage(newsockfd, "Enter number 1: ");
        read(newsockfd, &num1, sizeof(int));
        printf("Client - Number 1 is: %d\n", num1);

        writeMessage(newsockfd, "Enter number 2: ");
        read(newsockfd, &num2, sizeof(int));
        printf("Client - Number 2 is: %d\n", num2);

        writeMessage(newsockfd, "Enter operator, 'q' to quit: ");
        read(newsockfd, &choice, sizeof(char));

        if (choice == 'q')
            break;
        if (choice != '+' && choice != '-' && choice != '*' && choice != '/' && choice != '%') {
            printf("This is not a valid operator. Please try again.\n\n");
            continue;
        }
        printf("Client - operator is: %c\n\n", choice);

        answer = getCalc(num1, num2, choice);

        int n = write(newsockfd, &answer, sizeof(int));
        if (n < 0) error("write() failed");
    }
}

int connectToServer(char *argv[], int* sockfd) {
    struct sockaddr_in serv_addr, client_addr;
    socklen_t client_len;

    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0)
        error("socket() failed");

    bzero((char*)&serv_addr, sizeof(serv_addr));
    int portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno); // host to network short

    if (bind(*sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
        error("bind() failed");

    listen(*sockfd, 2); // Max two clients at a time
    client_len = sizeof(client_addr);

    int newsockfd = accept(*sockfd, (struct sockaddr*) &client_addr, &client_len);

    if (newsockfd < 0)
        error("accept() failed");

    return newsockfd;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error. Usage: %s <portno>\n", argv[0]);
        exit(1);
    }

    int sockfd;
    int newsockfd = connectToServer(argv, &sockfd);
    printf("Client and server are now connected.\n");

    calc(newsockfd);

    close(newsockfd);
    close(sockfd);

    return 0;
}
