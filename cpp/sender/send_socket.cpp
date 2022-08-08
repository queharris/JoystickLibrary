#include <vector>
#include <string>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <iostream>
#include <cstring>
using namespace std;

#define MAXLINE 1024

void BindSocketToPort(const int sockfd, const int port, sockaddr_in& recv_addr, socklen_t &len)
{
    /*
    sockaddr_in listen_addr;
    listen_addr.sin_port = htons(port);
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    listen_addr.sin_family = AF_INET;
    const socklen_t addr_len  = sizeof(listen_addr);
    */
    bind(sockfd, (const struct sockaddr *)&recv_addr, len);
}

void SendArray(const int sockfd, sockaddr_in& recv_addr, int arraySender[5], int arraySize, socklen_t &len)
{
    sendto(sockfd, arraySender, arraySize, 0, (struct sockaddr *) &recv_addr, len);
}

void SendString(const int sockfd, sockaddr_in& recv_addr, char *hello, socklen_t &len)
{
    sendto(sockfd, hello, strlen(hello), 0, (struct sockaddr *)&recv_addr, len);
}

void ReceiveArray(const int sockfd, sockaddr_in& recv_addr, int arrayReceiver[5], int arraySize, socklen_t &len)
{
    recvfrom(sockfd, arrayReceiver, arraySize, 0, (struct sockaddr *) &recv_addr, &len);
}

void ReceiveString(const int sockfd, sockaddr_in& recv_addr, char *buffer, int maxline, socklen_t &len)
{
    recvfrom(sockfd, (char *)buffer, maxline, MSG_WAITALL, (struct sockaddr *) &recv_addr, &len);
}

void PrintArray(int arrayReceiver[10], int arraySize)
{
        int array[10] ;

        std::cout << "\n" << "ARRAY FROM SENDER" << "\n" ;

        for (int i = 0 ; i < arraySize ; ++i) 
        {
            array[i] = ntohl(arrayReceiver[i]);
            std::cout << "Sender : " << array[i] << "\n" ;
        }
}

void PrintString(std::string buffer)
{
    std::cout << "\n" << "RECEIVER MESSAGE : " << buffer << "\n";
}

sockaddr_in SetSocketAddress(int port)
{
    sockaddr_in recv_addr;
    recv_addr.sin_port = htons(port);
    recv_addr.sin_addr.s_addr = INADDR_ANY;
    recv_addr.sin_family = AF_INET;

    return recv_addr;
}