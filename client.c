#include "defs.h"

/*
 * function : initClientTCP
 * purposes : initialization of the server soket listener
 * input    : int port - the port that the server will be connecting on
 * input    : char* ip - the address that the client will be connecting to 
 * output   : struct socket_in *socket - the socket client socket to be initialized
 * return   : a file descriptor that refers to th<t endpoint ( socket id )
 */
int initClientTCP(struct sockaddr_in *socket, unsigned int  port, char* ip){
    int socketDescriptor; 

    /* get a socekt in talk mode */
    socketDescriptor = initSocketTCP(socket, port, TALK, ip);

    return socketDescriptor;
}


/*
 * function : client
 * purposes : client communication to the server
 * return   : C_OK
 */
int client(){
    int clientSocketDescriptor = -1, returnCode = 0; 
    char ip[MAX_STR] = "", sentinel [MAX_STR] =  "";
    unsigned int port = DEFAULT_PORT;
    struct sockaddr_in client;
    
    /*get the infomation inorder to connect the server */
    printf("Client MODE selected, Creating a new Socket\n");
    printf("Input Ip : ");
    readString(ip);    
    clientSocketDescriptor = initClientTCP(&client,port,ip);

    /* try and connect to the server, if returnCode < 0 then report an error */
    returnCode = connect(clientSocketDescriptor,(struct sockaddr *) &client,sizeof(client));

    if( returnCode < 0){
        printf("Connection Error");
        exit(1);
    }
    
    /* enter chat mode in TALK mode */
    returnCode = chatMode(clientSocketDescriptor,TALK);
    close(clientSocketDescriptor);
    
    
    return C_NOK;
}


/*
 * function : chatMode 
 * purposes : communication between the clients of the connected sockets 
 * input    : int socket    - the socket that the communication is being done in
 * input    : enum MODE     - determins if it is in reciving mode or not
 * return   : C_OK - done talking , CONNECTION_LOST - close command recived/entered
 */
int chatMode(int socket, enum MODE mode){

    /* init vars */
	char buffer[MAX_STR];  //Sending/Recieving buffer
	int  bytesRcv;         //# of bytes recieved

    printf("You have now Entered Chat Mode, on talk enter 'close' to close the connection\n");

	/*Loop talk and wait mode until user enters close*/
	while(strcmp(buffer,"close") !=0 )
	{
		/*prompt message/send buffer through socket in talk mode*/
		if(mode == TALK)
		{
			mode = WAIT;
			printf("Please enter message to send: ");
			fgets(buffer, sizeof(buffer), stdin);
			buffer[strlen(buffer) - 1] = 0;
			send(socket, buffer, strlen(buffer), 0);
		}
		/*wait for recieving buffer in wait mode, print when recieved*/
		else if(mode == WAIT)
		{
			mode = TALK;
			printf("Waiting for message...\n");
			bytesRcv = recv(socket, buffer, sizeof(buffer), 0);
			buffer[bytesRcv]  = 0;
			printf("You have recieved message: %s\n", buffer);
		}
	}
	return C_OK;
}
