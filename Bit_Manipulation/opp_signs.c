/**
 * @ref https://graphics.stanford.edu/~seander/bithacks.html#DetectOppositeSigns
*/

#include <stdio.h>
#include <stdbool.h>

//Detect if two integers have opposite signs 
int main(void){
    int x = 20, y = 1; //input values to compare signs

    bool f = ((x^y) < 0); //true if x and y have opp signes

    printf("%d\n", f);
}