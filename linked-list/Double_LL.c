#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
    struct Node* prev;
}NODE;


NODE* create_Double_LL(int arr[], int size){

    if(size <= 0){
        return NULL;
    } 

    NODE* tail;
    NODE* head = (NODE*)malloc(sizeof(NODE));
    tail = head;
    head->prev = NULL;
    head->next = NULL;
    head->val = arr[0];

    for(int i = 1; i<size; i++){
        NODE* temp = (NODE*)malloc(sizeof(NODE));
        temp->val = arr[i];
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    return head;
}

//One to display a linked list given the head
void Display(struct Node* head){

    if(head == NULL)
        return;
    printf("Linked List values forwards\n");
    struct Node* temp = head;
    //traverse till 
    while(temp->next!= NULL){
        printf("%d ->", temp->val);
        temp = temp->next;
    }
    
    //printf("Linked List values backwards\n");
    while(temp!=NULL){
        printf("%d ->", temp->val);
        temp = temp->prev;
    }
    printf("NULL\n");
}

void Insert(NODE* p, int pos, int val){

    if(p == NULL)
        return;

    NODE* prev = NULL;
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->val = val;

    for(int i=1; i<pos; i++){
        prev = p;
        p = p->next;
    }
    prev->next = temp;
    temp->prev = prev;
    temp->next = p;
    p->prev = temp;
}


int Delete(NODE* p, int index){
    int res = -1;
    if(p == NULL){
        return res;
    }

    NODE *r = NULL;
    
    for(int i=1;i<index;i++){
        //Traverses index - 1 times
        r = p;
        p= p->next;
    }
    p->next->prev = r;
    r->next = p->next;
    res = p->val;
    free(p);
    return res;
}

//Singly linked list
NODE* Reverse(NODE* p){

    NODE *q = NULL, *r = NULL;
    while(p!= NULL){
        r = q;
        q = p;
        p = p->next;
        q->prev = p;
        q->next = r;
    }
    return q;
}

int main(){

    int array[] = {1,2,3,4,5,6};
    int length = sizeof(array)/sizeof(array[0]);
    
    //Create a doubly linked list
    NODE* head =create_Double_LL(array, length);
    Display(head);
    Insert(head,5,99);
    Display(head);
    Delete(head,5);
    Display(head);
    printf("Reversed\n");
    Display(Reverse(head));
}

