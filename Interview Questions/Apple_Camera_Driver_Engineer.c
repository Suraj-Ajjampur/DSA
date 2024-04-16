#include <stdio.h>
#include <stdlib.h>


//typedef struct
typedef struct node{
    int val;
    struct node* next;
}NODE;

NODE *head;

//write a program to find the middle element of the linked list
int find_middle(NODE* head){
    
    if(head == NULL)
        return -1;
    
    NODE *slow, *fast;

    slow = head;
    fast = head->next;

    while(fast!= NULL && fast->next!= NULL){
        fast = fast->next->next;
        slow = slow->next;
    } 

    return slow->val;
}

//write a program to create a linked list
NODE* create_linked_list(int num_ele){

    NODE *prev, *temp; //one to create other to traverse

    temp = (NODE *)malloc(sizeof(NODE));
    temp->val = 1;
    temp->next = NULL;
    head = temp;

    for(int i=2; i<=num_ele; i++){
        prev = temp;
        temp = temp->next;//traverse
        temp = (NODE*)malloc(sizeof(NODE)); //malloc a new node
        //form the link to prev
        temp->val = i;//assign val
        prev->next = temp;
    }

    return head;
}

int main(void){

    printf("%d\n",find_middle(create_linked_list(3)));
    printf("%d\n",find_middle(create_linked_list(4)));
    printf("%d\n",find_middle(create_linked_list(7)));
    printf("%d\n",find_middle(create_linked_list(8)));
    return 0;
}