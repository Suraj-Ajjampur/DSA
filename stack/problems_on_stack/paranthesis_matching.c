
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {
    false,
    true,
}bool;

struct Node
{
    char data;
    struct Node *next;
}*top=NULL;

void push(char x)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)
        printf("stack is full\n");
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}


char pop()
{
    struct Node *t;
    char x=-1;
    if(top==NULL)
        printf("Stack is Empty\n");
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

bool isEmpty(){
    if(top == NULL)
        return true;
    return false;
}


int isBalance(char *exp){

    int i;

    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i] == '(')
            push(exp[i]);
        else if(exp[i] == ')'){
            if(top == NULL)
                return 0;
            pop();
        }
    }
    if(top==NULL)
        return 1;
    else    
        return 0;
}


int main(){
    char *exp = "((a+b))";
    printf("%d\n",isBalance(exp));

    return 0;
}



