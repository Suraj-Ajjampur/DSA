#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n){
    struct Node *t,*last;
    int i;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;

    for(i=1 ;i<n ;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data = A[i]; 
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p){
    while(p)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
}

int Length(struct Node *p){
    
    int len=0;

    while(p){
        len++;
        p=p->next;
    }
    return len;
}

/**
 * @brief Adding a node on doubly LL
 * 
*/
void Insert(struct Node *p, int index, int val){

    if(index < 0 || index > Length(p))
        return;

    struct Node *t,*q;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = val;

    //Adding on the first node
    if(index == 0){
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }else{
        for(int i = 1; i<index; i++){
            p=p->next;
        }
        t->prev = p;
        t->next = p->next;
        if(p->next)
            p->next->prev = t;
        p->next = t;
    }
}

void Reverse(struct Node *p){
    struct Node *temp;
    while(p!=NULL){
        temp=p->next;
        p->next=p->prev;
        p->prev = temp;
        p= p->prev; // As we did this p->next=p->prev;
        //We check if p reached last node
        if(p!= NULL && p->next == NULL) 
            first = p;
    }
}

int Delete(struct Node *p, int index){

    if(index <= 0 || index > Length(p))
        return -1;

    int val;
    struct Node *q;
    //first element
    if(index == 1){
        val = p->data;
        if(p->next){
            p->next->prev = NULL;
            first = first->next;
        }
        free(p);
    }else{
        for(int i = 0; i<index-1;i++){
            q = p;
            p = p->next;
        }
        val=p->data;
        q->next=p->next;
        if(p->next)
            p->next->prev = q;
        free(p);
    }

    return val;
}
int main(){
    int A[] = {1,2,3,4,5};
    create(A,5);
    Display(first);
    Insert(first,5,0);
    Display(first);
    Delete(first,3);
    Display(first);
    Reverse(first);
    Display(first);
    return 0;
}