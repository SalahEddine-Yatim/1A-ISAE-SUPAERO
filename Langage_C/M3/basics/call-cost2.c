#include <stdio.h>

void fun (int i);
int j=0;

void fun (int i){

        j = j + 3*i;
}

int main(void){
    
    for (int i ; i <= 500000000 ; i++){
        fun (i);
    }
    printf("%d" , j) ;
    return 0;
}