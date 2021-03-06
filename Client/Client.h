#ifndef _SERVER_H_
#define _SERVER_H_

//#define __DEBUG__

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <pthread.h>

#include <stdint.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_BUF_SIZE 1000
#define MAX_USERS 100

#define DELIM ":"

// flags returned by server for sent message request status
#define SUCCESS "success"
#define BSUCCESS "b_success"
#define OFFLINE "offline"
#define SEND_ERR "e_send"

// flags for user input for actions
#define EXIT "exit"
#define WHO "who"
#define HELP "help"


extern std::string myname;
extern int socketDescriptor;
extern std::vector<std::string> usersList;

extern char buffer[MAX_BUF_SIZE];
extern std::vector<std::string> bufferTokens;

extern std::string cmdInput;
extern std::vector<std::string> cmdTokens;


int setupConnection(in_port_t serverPort, char* serverIP);


void *Sender(void*);
void *Receiver(void*);

int sendMessage(int sockfd, const char* data);
int receiveMessage(int sockfd, char*buffer);

void splitCharStream(char* stream, const char* delim, int count, std::vector<std::string>* result);
void trim(std::string& s, const char tchar);

void displayOnlineUsers(std::vector<std::string> &usersList);
void giveInstructions();

#endif