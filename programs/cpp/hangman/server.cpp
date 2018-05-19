#include <iostream>
#include <cstdlib>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER 1
#define PORT 1885
#define CHANCES 10

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, port;
    socklen_t clilen;
    char buffer[BUFFER];
    struct sockaddr_in serv_addr, cli_addr;
    if (argc < 2) {
        std::cout << "usage: " << argv[0] << " [solution]" << std::endl;
        exit(1);
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);
    bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    int chances = CHANCES;
    char response[BUFFER];
    while (chances > 0) {
        bzero(buffer, BUFFER);
        read(newsockfd, buffer, BUFFER);
        std::cout << "Message: " << buffer << std::endl;
        response[0] = chances;
        write(newsockfd, response, BUFFER);
        chances--;
    }
    close(newsockfd);
    close(sockfd);
    return 0;
}
