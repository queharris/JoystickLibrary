#include <iostream>
#include "Extreme3DProService.hpp"
#include "Xbox360Service.hpp"
#include <chrono>
#include "send_socket.hpp"

using JoystickLibrary::Extreme3DProService;

Extreme3DProService& es = Extreme3DProService::GetInstance();

void CreateSocket()
{   
    // CREATE SOCKET, SET SOCKET ADDRESS
    int sockfd; 
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    sockaddr_in recv_addr = SetSocketAddress(PORT); 
    socklen_t len = sizeof(recv_addr);
}

void SendLogitechAxes(int id, const int sockfd, sockaddr_in& recv_addr, socklen_t &len)
{
    int x, y, z, slider;
    int jsValues[4];

    if (!es.GetX(id, x))
        x = 0;
    if (!es.GetY(id, y))
        y = 0;
    if (!es.GetZRot(id, z))
        z = 0;
    if (!es.GetSlider(id, slider))
        slider = 0;

    jsValues[0] = htonl(x);
    jsValues[1] = htonl(y);
    jsValues[2] = htonl(z);
    jsValues[3] = htonl(slider);

    // SEND JOYSTICK DATA TO THE RECEIVER
    SendArray(sockfd, recv_addr, jsValues, sizeof(jsValues), len);
  
}


void LogitechAxes(int id)
{
    int x, y, z, slider;

    if (!es.GetX(id, x))
        x = 0;
    if (!es.GetY(id, y))
        y = 0;
    if (!es.GetZRot(id, z))
        z = 0;
    if (!es.GetSlider(id, slider))
        slider = 0;

    std::cout << "X: " << x << " | Y: " << y << " | Z: " << z << " | Slider: " << slider << std::endl;
}

int main()
{
    bool s = es.Initialize();
    std::cout << "Waiting for js plugin" << std::endl;
    while (es.GetNumberConnected() < 1);
    //CreateSocket;

    // QUE - TEMPORARY CODE CREATING SOCKET
    int sockfd; 
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    sockaddr_in recv_addr = SetSocketAddress(PORT); 
    socklen_t len = sizeof(recv_addr);

    std::cout << "Sending joystick data..." << std::endl;
	
#if 1
    while (true)
    {

        auto& a = es.GetIDs();
        if (a.size() <= 0)
            continue;
        SendLogitechAxes(a[0], sockfd, recv_addr, len);
	
    }
#endif

    std::cin.get();

    return 0;
}
