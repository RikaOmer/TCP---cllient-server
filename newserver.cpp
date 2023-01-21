#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <cstring>
#include <string.h>
#include <string>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "Knn.h"
#include <cctype>
#include <thread>
#include "CLI.h"
#include "DefaultIO.h"

using namespace std;
 
int main(int length,char** args)
{
    const int server_port = atoi(args[1]); // get port as a argument
    // Create a socket
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening < 0)
    {
        perror("Can't create a socket! Quitting");
        return -1;
    }
 
    // Bind the ip address and port to a socket
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(server_port); 
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);
    if(bind(listening, (sockaddr*)&hint, sizeof(hint)) < 0)
    {
        perror("error binding socket");
        return -1;
    }
    if (listen(listening, 5) < 0)
    {
        perror("error listening to a socket");
        return -1;
    }
 
    listen(listening, SOMAXCONN); // Tell Winsock the socket is for listening
    while (true)
    {
        
    }
}

int newClient(int listening){
    // create new thread
    // Wait for a connection
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);
    int clientSocket = accept(listening, (sockaddr*)&client, &clientSize);
    if (clientSocket < 0)
    {
        perror("error accepting client");
        return -1;
    }
    SocketIO socketIO(clientSocket);
    CLI *cliClient = new CLI(&socketIO);
    cliClient->start(); /// run till enter 8
    close(clientSocket);
    return 0;
    }
    