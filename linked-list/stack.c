#include "stack.h"

/**
 * @name push
 * 
 * @brief pushing new node on the last element of the linked list
 * 
 * @param p pointer the first element 
 * 
 * @param x value of the new node
*/
void push(struct Node *p, int x){

    struct Node *t;

    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    //special case
    if(head == NULL){
        head = t;
        tail = t;
    }else{
        tail->next=t;
        tail=t;
    }
}

int pop(struct Node* p){

    int x =  p->data;
    first=first->next;
    //Prevent memory leaks
    free(p);

    return x;
}