#ifndef ARRAY_OPS_H
#define ARRAY_OPS_H

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <malloc.h>

struct Array{
    int A[10];
    int Size;
    int Length;
};

void Display(struct Array arr);
void Insert_element(struct Array *arr,int index,int x);
int Delete_element(struct Array* s, int index);
int LinearSearch(struct Array *arr, int key);
int BinarySearch(struct Array *arr, int key);

#endif // ARRAY_OPS_H