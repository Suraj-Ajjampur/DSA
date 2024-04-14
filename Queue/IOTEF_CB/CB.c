#include <stdio.h>
#include <stdint.h>

//Come back to this
#define QUEUE_DEPTH (32)  

int my_array[QUEUE_DEPTH];

int wptr, rptr;

uint32_t nextPtr(uint32_t ptr){

    if(ptr +1 == QUEUE_DEPTH)
        return 0; //wrap back to 0
    else
        return ptr+1;
}

//Enqueue function
int enqueue(int x){
    //Check for full
    if((wptr+1) % QUEUE_DEPTH == rptr){
        printf("FIFO Full\n");
        return -1;
    }
    else{
        my_array[wptr] = x;
    }
}

int dequeue(){
    int x;
    if(rptr == wptr){
        x = my_array[rptr];
        //increment read pointer
        rptr = (rptr+1) % QUEUE_DEPTH;
        //Dequeue from head

    }
}



int main(){

    printf("Hello World! \n");
    return 0;
}