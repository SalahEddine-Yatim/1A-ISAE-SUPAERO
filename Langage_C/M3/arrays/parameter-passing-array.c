#include <stdio.h>

void mult_array(int size , int array[size]);

void mult_array(int size , int array[size]){

    for(int i=0; i<size; i++){

        array[i] = array[i]*2;
    }
}

int main(void){

    int my_array[5] = {1,2,3,4,5};
    mult_array(5,my_array);
    
    printf("[");
    for (int i=0 ; i<5 ; i++){
        printf(" %d," , my_array[i]);
    }

    printf("]\n");
         

    return 0;
}