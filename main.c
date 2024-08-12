#include "ExParse.h"

int main(void){
    token *curr, *erase;
    char input[]="11+sin(x^2)+23*ln(x+57)+12";
    curr=lex(input);

    while(curr!=NULL){
        printf("%s\n",curr->text);
        curr=curr->next;
    }

    //freeList(erase);
    return(0);
}
