#include "defs.h"

/*
 * function : initServerTCP
 * purposes : intialization of the server socket listener
 * input    : int port - the port that the server will be listening on    
 * output   : struct socket_in *socket - the server socket to be initialized
 * return   : a file descriptor that refers to that endpoint ( socket id )
 */
int initServerTCP (struct sockaddr_in *socket, unsigned int port){
    int socketDescriptor, returnCode;
    int numberOfConnections = 5;

    /* file descriptor that refers to the endpint */
    socketDescriptor = initSocketTCP(socket,port,WAIT,""); 


    /* bind to port */
    returnCode = bind(socketDescriptor,(struct sockaddr *) socket,sizeof(*socket));

    if( returnCode < 0){
        printf("Could Not Bind To Port. Error %d \n",returnCode);
        exit(1);
    }

    /* listen to port */
    returnCode = listen(socketDescriptor,numberOfConnections);

    /* error code */
    if(returnCode < 0){
        printf("Could not listen on port \n");
        exit(1);
    }

    return socketDescriptor;
}


/* function : server 
 * purposes : server for the communication end, binds to port and accepts connections 
 * reutrn   : C_OK
 */
int server(){
    /* init vars */
	struct   sockaddr_in listenSocket;        //listening socket
	unsigned int         port = DEFAULT_PORT; //port of listening socket
		 int         listenSocketDesc,    //Descriptin of listening socket
		             socket,              //socket received
		             addrSize;            //size of listening socket

	printf("Initializing Server\n\n");

	listenSocketDesc = initServerTCP(&listenSocket,port); //initialize servers listening socket
	
	printf("Waiting for connection...\n");

    /* accept a connection to the server */
	addrSize = sizeof(listenSocket);
	socket   = accept(listenSocketDesc, (struct sockaddr *) &listenSocket, &addrSize);

    /* error */
	if(socket < 0)
	{
		printf("Could not accept the connection.\n");
		exit(-1);
	}

	printf("Connected\n");

    /* enter the chat mode */
	chatMode(socket, WAIT);
	
    /* clean up */
	close(socket);
	close(listenSocketDesc);
    /* initialize a socket for the client and accept, on accept enter chat mode */

    return C_OK;
}
