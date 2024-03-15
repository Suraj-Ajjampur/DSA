// Give a fastest way to multiply any number by 9.
// How to measure the size of any variable without “sizeof” operator?
// https://www.emblogic.com/blog/12/tricky-c-interview-questions/

#include <stdio.h>
/**
 * By using the &x, we get the base address of the variable x and by adding 1 
 * to it we get the base address of next short int type. Hence the resulting address of 
 * (&x+1) will be 2 bytes more than the base address of the variable x. But if we just 
 * display the difference between the base address of x and the incremented address, 
 * then the difference will be ‘1’, means “1 block of short int type has been added” but 
 * we need the result of size of variable in terms of bytes not in terms of blocks. 
 * This can be achieved if we typecast the address into char *, because the address of char data 
 * type will always be in block of one byte, hence if the difference between the base address of x 
 * and the incremented address is displayed in terms of char type, then the difference will be displayed as 2, 
 * because the difference is actually 2 blocks or 2 bytes in terms of char type representation.
*/
#define size_of(x) ((char *)(&x+1) - (char*)&x)

#define SIZE_OF(T) (((T *)0)+1)

#define SWAP(a,b) (((a) == (b)) || (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b))))


void show(int x, int y){
    if(x<=y){
    printf("%d ",x);
    show(x+1,y);
    }
}
int main(){
    int n;

    n = 3;

    // printf("3 multiplied by 9 is %d\n",(n<<3)+n);
    // printf("size of data type long int is %ld\n",SIZE_OF(long int));
    // printf("size of variable n is %ld\n", size_of(n));
    int m = 30;

    //Write a C-program to find the smallest of three integers without using any of the comparision operators.
    int a,b,c;
    printf("Enter 3 numbers\n");
    scanf("%d %d %d", &a,&b,&c);

    //How to check endianness of the computer.
    int i = 1;

    char *char_pointer = (char *)&i;
    if(*char_pointer)
        printf("Little Endianness\n");
    else 
        printf("Big Endianness\n");
    
    int negative_bitmask = (1 << 15);
    printf("Smallest number is ");
    if((a-b) & negative_bitmask){
        if((a-c) & negative_bitmask)
            printf("%d\n", a);
        else    
            printf("%d\n", c);
    }
    else{
        if((b-c) & negative_bitmask)
            printf("%d\n", b);
        else    
            printf("%d\n", c);
    }

    //WAP to print 100 times “Hello” without using loop & goto statement.
    show(1,100);

    //Write a C-program which does the addition of two integers without using ‘+’ operator.
    printf("Result of addition with + is %d\n", m -(-n));

    SWAP(n,n);
    printf("new n val is %d and new n val is %d\n", n,n);

    return 0;
}