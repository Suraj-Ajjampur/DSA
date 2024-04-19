#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}NODE;


NODE* create(int size){

    if(size <=0)
        return NULL;
    
    NODE* head = (NODE*)malloc(sizeof(NODE));
    head->val = 1;
    head->next = NULL;
    NODE* tail = head;

    for(int i = 2; i<= size; i++){
        NODE* temp = (NODE*)malloc(sizeof(NODE));
        temp->val = i;
        temp->next = NULL;
        tail->next = temp; //Linking to the linked list
        tail = temp;
    }
    return head;
}

void Display_LL(NODE* head){
    
    while(head != NULL){
        printf("%d ", head->val);
        head = head->next; //traversal
    }
    printf("\n"); //New line
}

int main(){
    //Create a Linked List
    NODE* head =create(10);
    //Display a linked list
    Display_LL(head);
    Display_LL(head);
    return 0;
}