#include "ExParse.h"

double parse(char *input){
   //Does something and writes the expression into the parser file containing a single function(eval) that returns the evaluated result. This result is then returned to the caller function by this "parse" function

    token *tokenizedList, *crntToken;
    tokenizedList=lex(input);
    crntToken=tokenizedList;

    FILE *file=fopen(parser.c);
    if(file==NULL){
      perror("Could not open file for editing");
      return;
    }
    

    while(crntToken!=NULL){

        crntToken=crntToken->next;
    }


   return(eval);
} 
