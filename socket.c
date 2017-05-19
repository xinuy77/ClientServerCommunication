#include "defs.h"

/*
 * function: initSocketTCP
 * purposes: intialization of the socket type depending on the mode
 * input   : int port - the port that the socket will be on 
 * input   : enum MODE - determine if the char* ip is used
 * input   : char* ip the ip to connect to 
 * output  : struct *socket_in - the socket that one wants to intialize
 */
int initSocketTCP(struct sockaddr_in *socket_in, unsigned int  port,  enum MODE mode, char* ip){

	int opensocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); //open socket

	//check socket, return C_NOK if err
	if(opensocket < 0) 
	{
		printf("Could not open socket\n");
		exit(1);
	}

	//setup address
	memset(socket_in, 0, sizeof(*socket_in));
	socket_in->sin_family = AF_INET;

	//set address accordingly to mode; 1 = TALK 2 = WAIT
	if(mode == TALK)
		socket_in->sin_addr.s_addr = inet_addr(ip);
	else if(mode == WAIT)
		socket_in->sin_addr.s_addr = htonl(INADDR_ANY);

    //setup the port 
	socket_in->sin_port = htons((unsigned short) 60002);

	return opensocket;
}

