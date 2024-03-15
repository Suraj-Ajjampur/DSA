#include "ll_apps.h"


void RemoveDuplicate(struct Node *p){
    struct Node *q;
    if(p == NULL)
        return;

    q = p->next; // p folows q

    while(q!= NULL){ //run till p->next is not null

        if(p->data!=q->data){ //Duplicate not found then simply traverse
            p=q;
            q=p->next; 
        } 
        else{ // Duplicate found 
            p->next = q->next;
            free(q);
            q=p->next;
        }
    }
}


void Reverse1(struct Node*p){
    
    //Auxillary Array
    int *A,i=0;
    A = (int*)malloc(sizeof(int)*count(p));

    struct Node *q;
    while(q!=NULL){
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL){
        q->data=A[i];
        q=q->next;
        i--;
    }
}

/**
 * @brief reversing a linked list using sliding pointers
*/
void Reverse_2(struct Node *p){
    //Sliding pointers 
    struct Node *q,*r;
    q= NULL;
    r= NULL;
    while (p!=NULL)
    {
        //Sliding 3 pointers
        r = q;
        q = p;
        p = p->next;
        q->next = r; //Link change
    }
    first = q;
}

/**
 * @brief Reverses a linked list using 2 sliding pointers and tail recursion
*/
void Reverse_3(struct Node *q, struct Node *p){
    if(p!=NULL){
        Reverse_3(p,p->next);
        p->next=q;
    }
    else
        first = q;
}

/**
 * @brief Merges 2 sorted lists
 * 
*/
void Merge(struct Node *p, struct Node *q){
    
    //points to first and last node of the 3rd LL
    struct Node *last;

    //Compare te first elements
    if(p->data < q->data){
        third = p;
        last = p;
        p = p->next;
        third->next = NULL;
    }else{
        third = q;
        last = q;
        q= q->next;
        third->next = NULL;
    }
    while(p && q){
        if(p->data < q->data){
            last->next=p; last=p; p=p->next; last->next=NULL;
        }
        else{
            last->next = q; last=q; q=q->next; last->next=NULL;
        }
    }
    if(p)
        last->next=p;
    if(q)
        last->next=q;
}

/**
 * @brief Checks if a Linked list is a loop 
 * 
 * p traverses by 1 and q traverses by 2
*/
bool isLoop(struct Node* f){
    struct Node *p, *q;
    p=q=f;

    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && q && p!= q);

    if(p==q){
        return true;
    }
    else
        return false;
}