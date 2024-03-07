#include <stdio.h>
#include "main.h"


// Creates a linked list based on the array A[] passed as a parameter
void create(int A[], int n){
    struct Node *t,*last; //one node to add elements, other to traverse
    
    if (A == NULL)
        return;
    
    //Malloc a node
    first=(struct Node *)malloc(sizeof(struct Node));

    first->data=A[0]; //assign val of first element
    first->next=NULL; 
    last=first;

    for(int i = 1; i<n ;i++)
    {   
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t; //link to the linked list
        last=t;       //Update last
    }
}

// Creates a linked list based on the array A[] passed as a parameter
void create2(int A[], int n){
    struct Node *t,*last;

    //Malloc a node
    second=(struct Node *)malloc(sizeof(struct Node));

    second->data=A[0];
    second->next=NULL;
    last=second;

    for(int i = 1; i<n ;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}


void DisplayRecursive(struct Node *p){

    if(p!=NULL){
        DisplayRecursive(p->next);
        printf("%d\n",p->data);
    }
}

int count(struct Node *p){
    int count = 0;

    while(p != NULL){
        count++;
        p=p->next;
    }
    return count;
}

int Sum(struct Node *p){
    int sum = 0;

    while(p!=NULL){
        sum += p->data;
        p=p->next;
    }
    return sum;
}

/**
 * @brief find the node with the max element in the ll
*/
int Max(struct Node *p){
    int max = 0;

    while(p!=NULL){
        if(p->data > max){
            max = p->data;
        }
        p=p->next;
    }
    return max;
}

/**
 * @brief displays the linked list
*/
void Display(struct Node *p){
    
    //Traversing a linked List
    while(p != NULL){
        printf("%d\n",p->data);
        p = p->next;
    }
}
/**
 * @brief 
*/
struct Node* SearchTransposition(struct Node *p, int key){
    struct Node *q = NULL;

    while(p!= NULL){
        if(key == p->data){
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }

        //q follows p
        q=p;
        p=p->next;
    }
}

/**
 * @brief searches for the key in every node of the linked list returns index
*/
int Search(struct Node *p, int key){

    int index = 0;

    while(p != NULL){
        if(key == p->data)
            return index;
        index++;
        p=p->next;
    }
    return -1;
}

/**
 * @name Insert
 * 
 * @param p pointer to first node in LL
 * 
 * @param index Index to insert new node
 * 
 * @param x Data to insert into the new node
*/
void Insert(struct Node *p, int index, int x){
    //Declare a temp pointer to Node
    struct Node *t;

    //Check for validity of the index
    if(index < 0 || index > count(p))
        return;
    
    //Create and assign data
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data = x;

    //Insert at the start or particular index
    if(index == 0){
        //Change the links
        t->next = first;
        first = t;
    }
    else{
        for(int i = 0; i <index-1;i++)
            p=p->next; //Traverse upto the index

        t->next=p->next; //Change the links
        p->next=t;
    }
}

/**
 * @brief Inseting in a sorted Linked List
 * 
 * 
*/
void InsertinSortedPosition(struct Node *p,int x){

    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    //LL is empty
    if(first == NULL){
        first = t;
    }else{
        //If the first element is greater 
        if(p->data > x){
        t->next = first;
        first = t;
    }else{ 
        //Traverse the linked list till condition
        while(p->next->data < x && p->next != NULL){
            p = p->next;
        }
        //Changing the linking
        t->next = p->next;
        p->next = t;    
    }
    }
}
int Delete(struct Node *p, int index)
{
    struct Node *q; //Declare a node to follow p
    int x=-1,i;

    if(index <1 || index > count(p))
        return -1;
        
    if(index == 1){
        q=first;
        x = first->data;
        first =first->next;
        free(q);
        return x;
    }
    else{
        for(i=0;i<index-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}


int main(void){

    struct Node *t1, *t2;

    int A[] = {3,5,15};
    int B[] = {4,8,12};
    create(A,3);
    create2(B,3);

    t1=first->next->next;
    t2=first->next;
    t1->next = t2;


    //Insert(first,2,10);
    InsertinSortedPosition(first,6);
    Delete(first,8);

    Display(first);
    Display(second);
    Merge(first,second);

    Display(third);

    printf("The length of the linked list %d\n",count(first));
    printf("The sum of All elements in the LL is %d\n",Sum(first));
    printf("The max element in LL is %d\n",Max(first));
    printf("The positon of key is in %d\n",Search(first, 15));

    struct Node *temp;
    temp = SearchTransposition(first,15);
    if(temp){
        printf("Key is found %d\n", temp->data);
    }
    else
        printf("Key not found\n");

    printf("The positon of key is in %d\n",Search(first, 15));

    return 0;
}

