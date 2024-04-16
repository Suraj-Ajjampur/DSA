#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* rptr;
    Node* wptr;
} Queue;

void create(Queue *FIFO) {
    FIFO->rptr = NULL;
    FIFO->wptr = NULL;
}

void enqueue(Queue *FIFO, int val) {
    Node *temp = (Node*) malloc(sizeof(Node));
    if(temp == NULL) {
        printf("Failed to allocate memory\n");
        return;
    }
    temp->val = val;
    temp->next = NULL;

    if(FIFO->wptr == NULL) { // First element being enqueued
        FIFO->rptr = temp;
        FIFO->wptr = temp;
    } else {
        FIFO->wptr->next = temp; // Link the new node
        FIFO->wptr = temp;       // Move the write pointer to the new node
    }
}

int dequeue(Queue *FIFO, int *output) {
    if(FIFO->rptr == NULL) {
        printf("FIFO empty\n");
        return -1; // Queue is empty
    }
    *output = FIFO->rptr->val;
    Node* temp = FIFO->rptr;
    FIFO->rptr = FIFO->rptr->next;
    if(FIFO->rptr == NULL) { // If the queue is now empty
        FIFO->wptr = NULL;
    }
    free(temp); // Free the dequeued node
    return 0;
}

int main() {
    Queue FIFO;
    create(&FIFO);
    enqueue(&FIFO, 10);
    enqueue(&FIFO, 20);

    int value;
    if(dequeue(&FIFO, &value) == 0) {
        printf("Dequeued: %d\n", value);
    }
    if(dequeue(&FIFO, &value) == 0) {
        printf("Dequeued: %d\n", value);
    }

    return 0;
}
