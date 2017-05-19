#ifndef _DEF_H_
#define _DEF_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>                                               
#include <sys/socket.h>         
#include <netinet/in.h>                                               
#include <arpa/inet.h> 

#define MAX_ARR              64
#define MAX_STR              64

#define C_OK                 0
#define C_NOK               -1
#define CONNECTION_LOST     -2
#define CONNECTION_GAIN      1

#define DEFAULT_PORT         60002



enum MODE{
    IDLE,
    TALK,
    WAIT
};

/* io                   */
void readString(char *str);
void enumToString(char *str, enum MODE mode);

/* server */
int initServerTCP (struct sockaddr_in *socket, unsigned  int port);
int server();

/* client */
int initClientTCP(struct sockaddr_in *socket, unsigned int port, char* ip);
int client();
int chatMode(int socket, enum MODE mode);

/* socket */
int initSocketTCP(struct sockaddr_in *socket_in, unsigned  int port,  enum MODE mode, char* ip);

#endif
