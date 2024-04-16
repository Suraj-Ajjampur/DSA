//Write a program to find the middle element of a linked list


#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}NODE;

//One to display a linked list given the head
void Display_LL(NODE* head){

    if(head == NULL)
        return;
    printf("Linked List values\n");
    struct Node* temp = head;
    //traverse till 
    while(temp!= NULL){
        printf("%d ->", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

//One to create a linked list and return the head
NODE* create(int size){
    if(size <=0)
        return NULL;

    struct Node *head, *tail;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->val = 1;
    head->next = NULL;
    tail = head;

    for (int i = 1; i <size; i++){
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->val = i+1;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
    return head;
}

//write a program to find the middle element of the linked list
int find_middle(NODE* head){

    //Two pointers to travese the linked list   
    NODE* fast, *slow;

    slow = head;
    fast = head->next;

    while(fast!= NULL && fast->next!= NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->val;
}

int main(){
    printf("Creating the linked list\n");
    printf("%d\n",find_middle(create(3)));
    printf("%d\n",find_middle(create(4)));
    printf("%d\n",find_middle(create(7)));
    printf("%d\n",find_middle(create(8)));
}