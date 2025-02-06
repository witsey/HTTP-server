#include <winsock2.h> // Winsock, library for managing network connections for [socket(), bind(), listen(), and accept()]
#include <ws2tcpip.h> // additional IP-related functions for handeling IPv4 and IPv6
#include <stdio.h> 
#include <stdlib.h> // for memory management 
#define PORT 8080

#pragma comment(lib, "Ws2_32.lib") // Link against Winsock library


int main() 
{
    WSADATA wsa; // to initialize WINSOCK later on
    SOCKET server_socket; 
    struct sockaddr_in server_addr; // initializing the socket address as a 'sockaddr_in' object
    int opt = 1;


    WSAStartup(MAKEWORD(2, 2), &wsa); // Initializing Winsoc


    server_socket = socket(AF_INET, SOCK_STREAM, 0); // creates a socket handler (uintptr_t)
    if (server_socket == INVALID_SOCKET) // Invalid socket ~= 0
    {
        printf("Failed to create socket.\n");
        return 1;
    }



    // socket configuration through the setsockopt() function 
     // Enable SO_REUSEADDR to reuse the port immediately after closing a socket

     if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt))) 
     {
        // setsockopt returns 1 when it fails to configure
        printf("setsockopt failed.\n");
        return 1; 
     }



    /*
        struct sockaddr_in {
            short            sin_family;   // e.g. AF_INET
            unsigned short   sin_port;     // e.g. htons(3490)
            struct in_addr   sin_addr;     // see struct in_addr, below
            char             sin_zero[8];  // zero this if you want to
        };
    */



    // Defining server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);


    // Bind() function assigns the address (IP and port) we defined to the socket we created
    if (bind(server_socket, (struct sockaddr*)& server_addr, sizeof(server_addr)) < 0)  
    {
        // note : Bind definition has `&server_addr` parameter as a " sockaddr " pointer that's why I cast it
        printf("Binding failed.\n");
        return 1;
    }


    // Listen for incoming connections
    if (listen(server_socket, 3) == SOCKET_ERROR) {
        printf("Listen failed.\n");
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }

    printf("Listening on port 8080...\n");


    while (1) 
    {
        // At the listening state the server indefinitely keeps running waiting for a connection
        struct sockaddr_in client_addr;
        int client_size = sizeof(client_addr);

        SOCKET client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_size);


        if (client_socket == INVALID_SOCKET) {
            printf("Accept failed.\n");
            continue;
        }

        printf("Client connected!\n");

        // send a basic HTTP response (just for testing)
        char *response = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, world!";
        send(client_socket, response, strlen(response), 0);

        closesocket(client_socket); 
    }


    // clean up
    closesocket(server_socket);
    WSACleanup();
    return 0;
}