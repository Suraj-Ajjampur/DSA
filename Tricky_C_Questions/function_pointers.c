//What are function pointers? Where/why are they used? Declare a function pointer 

#include <stdio.h>

int fun(int x){
    printf("Value of x is %d\n", x);
    return x +5;
}

int sum(int a,int b){
    return a+b;
}

int subtract(int a, int b){
    return a-b;
}

int mult(int a,int b){
    return a*b;
}


int main(){   

    //declare a function pointer
    int (*ptr)(int) = fun;
    printf("Returned value is %d\n", (*ptr)(10));

    //Declare an array of function pointers
    int (*fun_ptr[])(int,int) = {sum,subtract,mult};
    int ch, a =15,b=10;

    for(ch=0;ch<3;ch++){
        printf("Result of operation fun_ptr[%d] is %d\n", ch,(*fun_ptr[ch])(a,b));
    }
    
    return 1;
}