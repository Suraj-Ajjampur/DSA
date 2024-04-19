#include <stdio.h>
#include <stdint.h>

//Changes
// Use all 10 values of the array -- ?
// Where will this buffer be stored in memory -- BSS Segment as it is global memory initialized
// Use dynamic memory instead of global array -

//Write a circular Buffer using a global array
#define QUEUE_DEPTH 10

int array[QUEUE_DEPTH];
int rptr =0, wptr =0;

int nextPtr(int ptr){
    return (ptr+1)% QUEUE_DEPTH; //handles wrap around
}

int enqueue(int x){
    //Check full condition
    if(nextPtr(wptr) == rptr){
        printf("FIFO full");
        return -1;
    }
    array[wptr] = x; //assign data
    wptr = nextPtr(wptr); //increment wptr
    return 0;
}


int dequeue(int *output){
    //Check for empty condition
    if(rptr == wptr){
        printf("FIFO Empty\n");
        return -1;
    }
    *output = array[rptr];
    rptr = nextPtr(rptr);
    return 0;
}

int main(){
    printf("Hello World\n");
    int output;
    for(int i=0; i <= QUEUE_DEPTH; i++){
        if(enqueue(i) == 0){
            printf("Enqueued value %d\n",i);
        }
    }
    if(dequeue(&output) == 0){
        printf("Dequeued value is %d\n", output);
    }
    return 0;
}