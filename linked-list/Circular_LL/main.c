#include <stdio.h>
#include <malloc.h>

struct Node{
    int data;
    struct Node *next;
}*Head;

void create(int A[],int n){
    int i; struct Node *t, *last; 
    Head = (struct Node*)malloc(sizeof(struct Node));
    Head->data=A[0];
    Head->next=Head; //Points to itself
    last = Head; //last is head itself

    for(i=1;i<n;i++){ //Run for num of nodes
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data=A[i]; 
        t->next=last->next; //Points to head
        last->next = t; //Last points to t
        last = t; //Reassign last to t
    }
}

int Length(struct Node *p){
    int len = 0;
    do //do while loop as p = Head at first
    {
        len++;
        p=p->next;
    } while (p!= Head); 
    return len;
}

void Insert(struct Node *p, int pos, int x){
    struct Node *t;
    int i;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if(pos<0 || pos > Length(p))
        return;
    if(pos == 0){ //Insert at the start
        if(Head == NULL){ //Check if List is empty
            Head = t;
            Head->next = Head; //Points to itself i.e circular
        }
        else{ //Not empty
            while(p->next != Head) //traverse till condition
                p=p->next; 
            p->next = t; // link last element to t
            t->next = Head; // link next of t to head
            Head = t; //Reassign head
        }
    }else{ //Insertion not at the start
        for(i=0;i<pos-1;i++)//Traverse till here
            p=p->next; 
        t->next = p->next; //new node linked to what p was linked to
        p->next =t; //
    }    
}
/**
 * @brief Deleting node from Circular Linked List
*/
int Delete(struct Node *p,int index){
    struct Node *q; //pointer following p
    int i,x;
    // Error checking index
    if(index < 0 || index > Length(Head))
        return -1;

    if(index == 1){
        //We need new link be last node and head
        while(p->next!= Head)
            p=p->next;
        p->next = Head->next; //points to 2nd element
        x=Head->data;
        free(Head);
        Head = p->next; //Assign head to 2nd element
    }else{ //For index != 1
        for(i=0; i<index-1;i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;//link prev node to next node
        x = p->data;
        free(p);
    }
    return x;
}

void Display(struct Node *h){
    do //do while loop as h = Head at first
    {
        printf("%d ",h->data);
        h=h->next;
    }while(h!=Head);
    printf("\n");
}
/**
 * @brief head recursive display of circular ll
*/
void RDisplay(struct Node *h){
    static int flag = 0;
    //2nd cond added so it passes first time
    if(h!= Head || flag ==0){ 
        flag=1;
        printf("%d ",h->data);
        RDisplay(h->next);
    }
    flag=0;
    printf("\n");
}

int main (){
    int A[] = {2,3,4,5,6};
    create(A,5);

    Insert(Head,6,10);
    
    RDisplay(Head);
    Delete(Head,1);
    RDisplay(Head);

    return 0;
}