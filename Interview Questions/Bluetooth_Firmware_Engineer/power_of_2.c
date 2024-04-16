#include<stdio.h>
#include<stdbool.h>

// 1000 & 0111
// 
bool powerof2(int val){
    return val && !(val & (val-1));
}

int main(){

    powerof2(2) == true ? printf("correct\n") : printf("wrong\n"); 
    powerof2(4) == true ? printf("correct\n") : printf("wrong\n"); 
    powerof2(8) == true ? printf("correct\n") : printf("wrong\n"); 
    powerof2(9) == false ? printf("correct\n") : printf("wrong\n"); 
    powerof2(0) == false ? printf("correct\n") : printf("wrong\n"); 
    powerof2(1) == true ? printf("correct\n") : printf("wrong\n"); 
}
