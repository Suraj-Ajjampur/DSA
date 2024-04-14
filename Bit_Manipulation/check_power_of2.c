/**
 * @ref https://graphics.stanford.edu/~seander/bithacks.html#DetermineIfPowerOf2
*/

//Determining if an integer is a power of 2 
#include<stdio.h>
#include<stdbool.h>

bool powerof2(int num){

    //1000 or 100
    //only 1 bit is set
    bool ans = num && !(num & (num -1));
    return ans;
}

int main(void){
    int x = 8;

    powerof2(x) == true ? printf("Power of 2\n") : printf("Not Power of 2\n"); 
    powerof2(9) == true  ? printf("Power of 2\n") : printf("Not Power of 2\n"); 
    powerof2(18) == true  ? printf("Power of 2\n") : printf("Not Power of 2\n"); 
    powerof2(64) == true  ? printf("Power of 2\n") : printf("Not Power of 2\n"); 
    powerof2(2) == true  ? printf("Power of 2\n") : printf("Not Power of 2\n"); 
    powerof2(0) == true  ? printf("Power of 2\n") : printf("Not Power of 2\n"); 
    powerof2(1) == true  ? printf("Power of 2\n") : printf("Not Power of 2\n"); 
}