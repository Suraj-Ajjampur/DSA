//Create a stack using arrays

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Struct to represetn the stack
struct Stack{
    int top;
    unsigned capacity;
    int* array;
};

typedef enum{
    false,
    true
}bool;

//Write a function to create a stack of given capacity
struct Stack *createStack(unsigned capacity){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1; //empty stack
    stack->array = (int*)malloc(stack->capacity*sizeof(int));
    return stack;
}

//Stack is full when is equal to the last index
bool isFull(struct Stack* stack){
    return stack->top == stack->capacity-1;
}

//Stack is empty when top is equal to -1
bool isEmpty(struct Stack* stack){
    return stack->top == -1;
}

//Function to add an item to stack. It increases top by 1
void push(struct Stack *stack, int item){
    if(isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to the stack\n",item);
}

//Function to remove an tem from stack. It decreases top by 1
int pop(struct Stack* stack){
    if(isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

//Function to return the top from stack without removing it
int peek(struct Stack* stack){
    if(isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

//Driver code to test the functionality of the stack operations
int main(){

    //Creates a stack of empty values
    struct Stack *stack = createStack(20);

    //Pushes 21 values onto the stack, should fail on last attempt
    for(int i=1;i<=21;i++)
        push(stack,i);
    printf("Peeked value is %d\n",peek(stack));

    //Pops 21 values from the stack, should return empty for last attempt
    for(int i = 1; i<=21;i++){
        printf("Popped value for iteration %d is %d\n", i,pop(stack));
    }

    return 0;
}