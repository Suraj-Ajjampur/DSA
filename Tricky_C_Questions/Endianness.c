#include <stdio.h>


//Show the memory representation of a number
void show_mem_rep(char *start, int n){

    for(int i =0; i < n;i++){
        printf("%.2x ", start[i]);
    }
    printf("\n");
}

void check_endianess(void){
    int i = 0x01;

    char *char_ptr = (char*)&i;

    printf("Mutibyte data stored in this machine is in \n");
    //Copies the MSB if it's little endian
    if(*char_ptr == 1){ 
        printf("Little Endian\n");
    }
    else
        printf("Big Endian\n");
}

int main(){
    int i = 0x01234567;
    show_mem_rep((char*)&i, sizeof(i));
    check_endianess();
    return 0;
}


