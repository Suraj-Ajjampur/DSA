#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <malloc.h>


struct Queue{
    int size;
    int head;
    int tail;
    int *Q; //space for storing set of elements
};

void create(struct Queue *q,int size){
    q->size=size;
    q->head = q->tail =0;
    //Create a array of given size on heap
    q->Q=(int*)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int x){
    //Check for full
    if((q->tail+1)%q->size == q->head)
        printf("Queue is full ");
    else{
        //Increment tail
        q->tail = (q->tail+1)%q->size;
        //Add element at tail
        q->Q[q->tail]=x;
    }
}

int dequeue(struct Queue *q){
    int x; //var to store dequeued element
    if(q->head == q->tail)
        printf("Queue is empty ");
    else{
        //Increment head
        q->head = (q->head+1)%q->size;
        //Dequeue from head
        x = q->Q[q->head];
        //We can free element here
        //free((void *)q->Q[q->head]);
    }
}

void Display(struct Queue q){
    int i =q.head+1;

    do{
        printf("%d ",q.Q[i]);
        i=(i+1)%q.size;

    }while(i!=(q.tail+1)%q.size);
    printf("\n");
}

int main(){
    struct Queue q;
    create(&q,5);

    enqueue(&q,10);
    enqueue(&q,20);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    Display(q);
    return 0;
}