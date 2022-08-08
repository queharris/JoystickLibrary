#include <vector>
#include <string>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#define MAXLINE 1024

void BindSocketToPort(const int sockfd, const int port, sockaddr_in& recv_addr, socklen_t &len);
void SendArray(const int sockfd, sockaddr_in& recv_addr, int arraySender[5], int arraySize, socklen_t &len);
void SendString(const int sockfd, sockaddr_in& recv_addr, char *hello,  socklen_t &len);
void ReceiveArray(const int sockfd, sockaddr_in &recv_addr, int arrayReceiver[5], int arraySize, socklen_t &len);
void ReceiveString(const int sockfd, sockaddr_in& recv_addr, char *buffer, int maxline, socklen_t &len);
void PrintArray(int arrayReceiver[5], int arraySize);
void PrintString(std::string buffer);
sockaddr_in SetSocketAddress(int port);