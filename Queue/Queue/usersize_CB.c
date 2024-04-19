#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <malloc.h>


//Circular Buffer implementation with Dynamic Memory
typedef struct Queue{
    int rptr;
    int wptr;
    int size;
    int *Array_Dynamic; //Pointer to store elements
}CB;


void create(CB *queue, int size){
    queue->size = size;
    queue->rptr =0; queue->wptr=0;
    
    queue->Array_Dynamic = (int *)malloc(sizeof(queue->Array_Dynamic) * queue->size);
    if(queue->Array_Dynamic == NULL){
        printf("Failed to dynamically allocate data");
    }
}

void enqueue(CB* queue, int x){
    if(((queue->wptr+1)%queue->size) == queue->rptr){
        printf("Queue is full");
    }
    else{
        queue->Array_Dynamic[queue->wptr] = x;
        queue->wptr = (queue->wptr+1)%queue->size; //update
    }
}

int dequeue(CB* queue){
    int val =-1;
    if(queue->rptr == queue->wptr){ 
        printf("Queue is empty");
    }
    else{
        val = queue->Array_Dynamic[queue->rptr];
        queue->rptr = (queue->rptr+1)%queue->size;
    }
    return val;
}

int main(void){
    printf("User defines Size FIFO\n");
    CB queue;

    create(&queue, 10);
    for(int i=0; i<10; i++){
        enqueue(&queue, i);
    }
    
    for(int i=0;i<6;i++){
        printf("Value Dequeued is %d\n",dequeue(&queue));
    }

    for(int i=0;i<10;i++){
        enqueue(&queue, i);
    }

    //Dequeue till empty
    while(queue.rptr != queue.wptr){
        printf("Value Dequeued is %d\n",dequeue(&queue));
    }

    return 0;
}