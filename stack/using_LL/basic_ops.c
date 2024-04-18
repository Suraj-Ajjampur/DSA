/**
 * @ref https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/#basic-operations-on-stack
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define EMPTY_ERROR INT_MIN

/**
 * @brief 
*/
struct Node
{
    int data;
    struct Node *next;
};


/**
 * @brief Creates a temp pointer of dynamically allocates, assigns val and links to top 
 * @param top - Address holding the value of the top pointer (pass by address)
 *  
*/
void push(struct Node** top,int x)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)
        printf("stack is full\n");
    else
    {
        t->data=x;
        t->next=*top; //push to the stack
        *top=t; //update the top
    }
}

/**
 * @brief creates a temp pointer and assigns top val, 
 * @param top - Address holding the value of the top pointer (pass by address)
*/
int pop(struct Node** top)
{
    struct Node *t;
    int x= EMPTY_ERROR;
    if(*top==NULL)
        printf("Stack is Empty\n");
    else
    {
        t=*top;
        *top=(*top)->next; //Reassign top
        x=t->data;  
        free(t);    //pop from the stack
    }
    return x;
}

int peek(struct Node* top){
    if(top == NULL){
        printf("Stack is empty");
        return EMPTY_ERROR;
    }
    return top->data;
}

/**
 * @brief creates a temp pointer to traverse the stack and display elements
 * @param top pass by val
*/
void Display(struct Node* top)
{
    while(top!=NULL)
    {
        printf("%d ",top->data);
        top=top->next;
    }
    printf("\n");
}

int main()
{
    struct Node *top=NULL;
    push(&top,10);
    printf("Top value is %d ",peek(top));
    push(&top,20);
    printf("Top value is %d ",peek(top));
    push(&top,30);
    printf("Top value is %d ",peek(top));
    Display(top);
    printf("Popped value is %d ",pop(&top));
    printf("Popped value is %d ",pop(&top));
    printf("Popped value is %d ",pop(&top));
    printf("Popped value is %d ",pop(&top));
    return 0;
}