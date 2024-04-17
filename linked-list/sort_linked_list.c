#include<stdio.h>
#include<stdio.h>


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


int main(){

    int array[] = {0,1,2,3,4,5};
    int length = sizeof(array)/sizeof(array[0]);
    
    //Create a doubly linked list
    Display(create_Double_LL(array, length));
}
