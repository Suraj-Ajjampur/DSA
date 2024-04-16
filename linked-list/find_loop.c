#include <stdio.h>
#include <malloc.h>
#include<stdbool.h>

// structure node
struct Node{
    int data;           
    struct Node *next;
};


//Write a function to find a loop in a linked list
bool isLoop(struct Node* head){
    struct Node* fast, *slow;

    fast = head;
    slow = head;

    while(fast != slow && fast!= NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    if(fast == slow)
        return true;
    else    
        return false;
}

//Write a circular linked list
struct Node* create_circular_LL(int size){
    if(size <= 0)
        return NULL;

    struct Node* head, *tail;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = head;
    tail = head;

    for(int i=2; i<=size; i++){
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data= i;
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
    }
}


int main(){

    printf("Loop check is %d",isLoop(create_circular_LL(10)));

    return 0;
}

