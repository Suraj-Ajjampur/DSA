#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    struct Node* next;
};


//Write 2 functions
//One to create a linked list and return the head
struct Node* create(int size){
    if(size <=0)
        return NULL;

    struct Node *head, *tail;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->val = 0;
    head->next = NULL;
    tail = head;

    for (int i = 1; i <size; i++){
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->val = i;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
    return head;
}

//One to display a linked list given the head
void Display_LL(struct Node* head){

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


//Write a function to create a linked list given an array
struct Node* create_LL_From_array(int arr[], int length){
    
    if (length <=0)
        return NULL;
    
    struct Node* head, *tail;
    head->val = arr[0];
    head->next = NULL;
    tail= head;

    for(int i=1; i<length; i++){
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->val = arr[i];
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
    return head;
}

int main(){
    printf("Creating the linked list");
    Display_LL(create(10));
    Display_LL(create(120));
    Display_LL(create(0));

    int array[] = {6,7,8,9,0,12,2};
    int length = sizeof(array)/sizeof(array[0]);
    Display_LL(create_LL_From_array(array, length));
}

