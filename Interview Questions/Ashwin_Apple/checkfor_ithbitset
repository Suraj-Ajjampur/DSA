#include <stdio.h>
#include <stdbool.h>

#define MASK(x) (1UL << x)
//Logic to check whether an ith bit is set or not 

bool isKthbitisset(int n,int k){

    int mask = MASK(k);

    if(k&mask){
        printf("%dth bit is set in %d",k,n);
        return true;
    }else{
        return false;
    }
}