#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 1885
#define BUFFER 1

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER];
    if (argc < 2) {
        std::cout << "usage: " << argv[0] << " [host]" << std::endl;
        exit(1);
    }
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cout << "Failed creating socket" << std::endl;
        exit(1);
    }
    if ((server = gethostbyname(argv[1])) < 0) {
        std::cout << "Failed getting host" << std::endl;
        exit(1);
    }
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_port = htons(PORT);
    if ((connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))) < 0) {
        std::cout << "Failed connecting" << std::endl;
        exit(1);
    }
    char c;
    while (1) {
        std::cout << "Enter a letter: ";
        bzero(buffer, BUFFER);
        buffer[0] = std::cin.get();
        write(sockfd, buffer, BUFFER);
        bzero(buffer, BUFFER);
        read(sockfd, buffer, BUFFER);
        printf("%d\n", *buffer);
    }
}
