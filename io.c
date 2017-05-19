#include "defs.h"

/*
 *     Function:  readString
 *     Purpose:   reads a string from standard input
 *     out:   string read in from the user
 *     (must be allocated in calling function)
 */
void readString(char *str)
{
  char tmpStr[MAX_STR];

  fgets(tmpStr, sizeof(tmpStr), stdin);
  tmpStr[strlen(tmpStr)-1] = '\0';
  strcpy(str, tmpStr);
}



/*
 *  function    : enumToString
 *  purposes    : gets the string meaning of the enum
 *  input       : enum MODE mode
 *  output      : cha *str
 */
void enumToString(char *str, enum MODE mode){
    switch(mode){
        case IDLE:
            strcpy(str,"<Idle>");
            break;
        case TALK:
            strcpy(str,"<Talk>");
            break;
        case WAIT:
            strcpy(str,"<Wait>");
            break;
        default:
            strcpy(str,"");
    }
}
