/**
 * @ref https://graphics.stanford.edu/~seander/bithacks.html#DetermineIfPowerOf2
*/

//Determining if an integer is a power of 2 
#include<stdio.h>
#include<stdbool.h>

bool powerof2(int num){
    //Will only have a single bit set and hence num & num -1 will return 0 if it is power of 2
    return num && !(num & num-1);
}

bool powerof4(int num){
    if(powerof2(num) == false)
        return false;
    // 
    // 16
    // 0 0 1 0 0 0 0
    // 4
    // 0 0 0 0 1 0 0 
    // 32
    // 1 0 0 0 0 0 0  
    // 1 
    // 0 0 0 0 0 0 1

    // 5 
    // 0 0 0 0 1 0 1 
    // A 
    // 0 0 0 1 0 1 0
    if(!(num & 0xAAAAAAAA))
        return true;
    else    
        return false;
}

bool powerof8(int num){

    if(powerof2(num) == false)
        return false;

    int bitmask = 0xB6DB6DB6;
    // 0110 1101 1011 0110
    // 6    D    B    6

    if(!(num & bitmask))
        return true;
    else
        return false;
}

//Write a program to print the number in binary
void Display_bin(int num){

    printf("Binary value of %d is \n",num);
    for(int i = 31; i >=0; i--){
        if((num >> i) & 1)
            printf("1");
        else
            printf("0");
        
        if(i % 4 == 0)
            printf("\t");
    }
    printf("\n");
}

int main(void){
    int x = 8;
    for(int i =0; i<=10;i++){
        powerof2(i) == true ? printf("%d is a power of 2\n",i) : printf("%d is not Power of 2\n",i); 
    }
    printf("\n");
    for(int i =0; i<=32;i=i+4){
        powerof4(i) == true ? printf("%d is a power of 4\n",i) : printf("%d is not Power of 4\n",i); 
    }

    printf("\n");
    for(int i =0; i<=512;i=i+8){
        powerof8(i) == true ? printf("%d is a power of 8\n",i) : printf("%d is not Power of 8\n",i); 
    }

    //Print function to create a valid bitmask
    Display_bin(1);
    Display_bin(8);
    Display_bin(64);
    Display_bin(512);
    Display_bin(4096);
    Display_bin(32768);
}