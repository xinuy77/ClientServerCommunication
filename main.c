#include "defs.h"


int main(){

    /* instantiation */
    char command[MAX_STR]     = "",    //command entered by user
         currentMode[MAX_STR] = "";    //current mode in String
    enum MODE mode            = IDLE;  //current mode

    printf("Please enter 'talk' to send a message to a waiting server\n");
    printf("Please enter 'wait' to get  a message from a client\n");
    printf("Enter 'exit' to quit the program\n");


    /* get current mode of the server */
    while(mode == IDLE){

        enumToString(currentMode,mode);
        printf("%s : ",currentMode); 

        readString(command);
        if(strcmp("talk",command) == 0 ){
            client();
        }
        else if(strcmp("wait",command ) == 0 ){
            server();
            system("fuser -k -n tcp 60002");
        }
        else if(strcmp("exit",command ) == 0 ){
            exit(1);
        }
        else{
            printf("INVALID OPTION\n");
        }

    }
    return C_OK;
}
