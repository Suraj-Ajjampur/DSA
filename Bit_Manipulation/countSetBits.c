#include <stdio.h>
#include <limits.h>

#define BRIAN_KERNIGHAN

// Will this work for a negative number?
/**
 * @ref Done with 2 methods 
*/
int countSetBits(int num){

    unsigned int count = 0;
    while(num !=0){
#ifdef BRIAN_KERNIGHAN
        num &= (num - 1);
        count ++;
#else 
        if(num&1 == 1)
            count++;
        num >>=1;
#endif
    }
    return count;
}

// Write a program to display a set of binary numbers
void Display_Binary(int num){
    
    printf("The value of %d in Binary is :",num);
    for(int i=(sizeof(int)*CHAR_BIT)-1; i>=0 ; i--){
        if ((num >> i)&1 == 1)
            printf("1");
        else    
            printf("0");
    }
    printf("\n");
}

int main(void){
    int x= 2;
    printf("N of set bits in %d is %d\n", x, countSetBits(x));
    printf("N of set bits in 0 is %d\n", countSetBits(0));
    printf("N of set bits in 1 is %d\n", countSetBits(1));
    printf("N of set bits in 32 is %d\n", countSetBits(32));
    printf("N of set bits in 7 is %d\n", countSetBits(7));
    printf("N of set bits in -1 is %d\n", countSetBits(-1));
    Display_Binary(-1);
    Display_Binary(32);

    return 0;
}