#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
}*head,*tail;


void enqueue(int x){
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL)
        printf("Queue is Full");
    
    t->data = x;
    t->next=NULL;
    if(head==NULL) 
        head=tail=t;
    else
        tail->next =t;
        tail = t;
}

int dequeue(void){
    int x = -1;
    struct Node *p;
    if(head == NULL)
        printf("Queue is empty");
    else{
        p=head;
        head=head->next;
        x=p->data;
        free(p);
    }
    return x;
}

void display(struct Node *p){
    
    while (p != NULL){
        printf("%d ",p->data);
        p= p->next;
    }
    printf("\n");
}


int main(){
    enqueue(10);
    enqueue(20);

    dequeue();
    display(head);
}