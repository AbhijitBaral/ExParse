#ifndef EXPRSSN_PARSER
#define EXPRSSN_PARSER

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double eval(void);
double parse(char *input);

typedef struct token{
    char *text;
    struct token *next;
}token;

token *lex(char *input);
void freeList(token *tokenized);
#endif
