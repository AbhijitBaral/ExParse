/*This code is intended to perform lexical analysis. A lexer converts a sequence of characters like a 
 * mathematical expression composed of variables, operators, functions, etc and converts it to a sequ
 * -ence of tokens. Tokens are meaningful character sequences.
 * The recognized tokens here are ;
 *          + Decimal Numbers
 *          + Elementary functions
 *          + Variable 'x'
 *          + Operators
 *          + Parantheses  */
#include "ExParse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/*~~~~~~~~~~~~~~~~~~~~~~~~Function to free the linked list ~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void freeList(token *head){
    token *Next=NULL;
    while(head != NULL){
        free(head->text);
        Next=head->next;
        free(head);
        head=Next;
    }
}


token* lex(char* input){
    token *tokenized=(token*)malloc(sizeof(token));
    if(tokenized==NULL){
        printf("Memory allocation for tokenized array failed");
        exit(1);
    }
    memset(tokenized,0,sizeof(token));
    token *crrnt=tokenized;
    
    while (*input !='\0'){
        if((*input)==' '){
               input++;           
               continue;
        }
        if (isdigit(*input) || (*input)=='.'){
            //recognize a number
            char* start= input;
            while (isdigit(*input)||(*input)=='.'){
                input++;
            }
            char *end=input;
            crrnt->text=(char*)malloc((end - start +1)*sizeof(char));
            strncpy (crrnt->text, start, end-start);
            crrnt->text[end-start]='\0';    //Null terminate the string
        }

        //~~~Elementary Functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if (isalpha(*input) && (*input)!='x'){
            char *start=input;
            while(isalpha(*input)&&(*input)!='x')
                input++;
            char *end=input;
            crrnt->text=(char*)malloc((end - start +1)*sizeof(char));
            strncpy( crrnt->text, start, end-start);
            crrnt->text[end-start]='\0';
        }
        
        //~~~Variable 'x'~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        else if((*input)== 'x'||(*input)=='+' ||(*input)=='-' ||(*input)=='*' ||(*input)=='/' ||(*input)=='^'||(*input)=='(' || (*input)==')'){
            crrnt->text=(char*)malloc(2*sizeof(char));
            crrnt->text[0]=*input;
            crrnt->text[1]='\0';
            input++;
        }

        else{
            printf("MALFORMED EXPRESSION");
            exit(EXIT_FAILURE);
        }
        if(*input!='\0'){
            crrnt->next=(token*)malloc(sizeof(token));
            crrnt=crrnt->next;
        }
    }
    return tokenized;
}
