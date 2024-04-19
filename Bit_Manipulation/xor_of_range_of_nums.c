#include<stdio.h>

// 1 to N
int computeXOR(int n){

    if(n % 4 == 0)
        return n;

    else if(n % 4 == 1)
        return 1;

    else if(n %4 == 2)
        return n+1; 

    // n %4 == 3 
    return 0;  
}

// From L to R -> fro m 2 to 4
int XOR_range(int L, int R){

    return (computeXOR(L-1) ^ computeXOR(R));
}


int main()
{

    XOR_range(2,4) == 5 ? printf("Pass \n") : printf("fail\n");
    return 0;
}

