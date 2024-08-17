#include "ExParse.h"

double parse(char *input){
   //Does something and writes the expression into the parser file containing a single function(eval) that returns the evaluated result. This result is then returned to the caller function by this "parse" function

    token *tokenizedList, *crntToken;
    tokenizedList=lex(input);
    crntToken=tokenizedList;

    FILE file=fopen(parser.c);
    

    while(crntToken!=NULL){

        crntToken=crntToken->next;
    }


   return(eval);
} 
