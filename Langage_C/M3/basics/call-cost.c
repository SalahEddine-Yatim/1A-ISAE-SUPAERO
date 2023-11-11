#include <stdio.h>

int main(void){
    int j=0;
    
    for (int i ; i <= 500000000 ; i++){
        j = j + 3*i;
    }

    printf("%d" , j);
    return 0;
}