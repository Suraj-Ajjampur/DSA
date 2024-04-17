#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}NODE;


NODE* create(int A[], int size){
    if(size <= 0)
        return NULL;

    NODE* head, *tail;

    head = (NODE*)malloc(sizeof(NODE));
    head->val = A[0];
    head->next = NULL;
    tail = head;

    for(int i =1; i<size; i++){
        NODE* temp = (NODE*)malloc(sizeof(NODE));
        temp->val = A[i];
        temp->next = NULL;
        tail->next = temp; //Connect node to ll
        tail = temp; //update the tail
    }
    return head;
}


void Display(NODE * head){

    if(head == NULL)
        return;
    NODE* tmp = head;
    
    printf("The linked list diplayed here\n");
    while(tmp != NULL){
        printf("%d ",tmp->val);
        tmp = tmp->next;
    }   
    printf("\n");
}


NODE* Reverse(NODE* p){
    NODE *q = NULL, *r = NULL;

    while(p!= NULL){
        r= q;
        q =p;
        p=p->next;
        q->next = r;
    }
    return q;
}

int main(){

    int array[] = {12,23,78,19,0,0};
    int length = sizeof(array) /sizeof(array[0]);

    NODE* head = create(array,length);

    Display(head);
    //Write a function to reverse a linked list

    NODE* new_head = Reverse(head);
    Display(new_head);

    return 0;
}