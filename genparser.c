#include "ExParse.h"

double parse(char *input){
   //Does something and writes the expression into the parser file containing a single function(eval) that returns the evaluated result. This result is then returned to the caller function by this "parse" function

  token *tokenizedList, *crntToken;
  tokenizedList=lex(input);
  crntToken=tokenizedList;
  char fileName[]="parser.c";
  FILE *file=fopen(fileName,"w");
  if(file==NULL){
    perror("Could not open file for editing");
    return;
  }

  fprintf(file,"#include <stdio.h>\n#include <stdlib.h>\n#include <math.h>\n\ndouble eval(void){\n\tdouble val=0.0;\n\t/");

  while(crntToken!=NULL){ 
      crntToken=crntToken->next;
  }


  return(eval);
} 
