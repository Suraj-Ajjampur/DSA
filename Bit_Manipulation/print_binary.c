#include<stdio.h>
#include <limits.h>


void printbinary(int num){

    printf("Binary representation of %d is \n", num);
    for(int i = (sizeof(int) * CHAR_BIT) - 1; i>= 0; i--){
        if((num >> i) & 1)
            printf("1");
        else    
            printf("0");

        if(i % 4 == 0)
            printf("\t");
    }
    printf("\n");
}
int main(){

    printbinary(10);
    printbinary(0xFF);
    printbinary(01);
    printbinary(0);
    printbinary(-1);
    return 0;

}