
#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <malloc.h>
#include "ll_apps.h"


struct Node
{
    int data;
    struct Node* next;
}*first,*head,*tail,*second;


int count(struct Node *p);

#endif // MAIN_H