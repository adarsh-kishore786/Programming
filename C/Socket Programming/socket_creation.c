#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "Practical.h"

void sockExists(int sock)
{
    if (sock < 0)
        DieWithSystemMessage("Failed to create socket");
}

int main()
{
    int family = AF_INET;
    int type = SOCK_STREAM;
    int protocol = IPPROTO_TCP;

    int sock = socket(family, type, protocol);
    sockExists(sock);

    printf("Created socket: %d\n", sock);
    printf("Family  : %d\n", family);
    printf("Type    : %d\n", type);
    printf("Protocol: %d\n", protocol);

    int status = close(sock);
    printf("Socket closed.\n");
    return 0;
}
