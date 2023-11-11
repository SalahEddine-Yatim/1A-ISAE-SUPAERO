#include <stdio.h>

void print_array(int size , int my_array[size]);

void swap(int size , int my_array[size], int i , int j);

void selection(int size , int my_array[size]);

int main(void){

    int array[5] = {1,2,3,4,5};

    swap(5,array,0,4);
    swap(5,array,2,3);
    selection(5,array);
    print_array(5,array);

    return 0 ;
}



void print_array(int size , int my_array[size]){

    printf("[");
    for (int e=0 ; e<size-1 ; e++){
        printf(" %d," , my_array[e]);
    }
    printf(" %d ]\n",my_array[size-1]);
}


void swap (int size , int my_array[size],int i,int j){
    
    int a = my_array[i] ;
    int b = my_array[j] ;

    my_array[i] = b ;
    my_array[j] = a ; 
}

void selection(int size , int my_array[size]){

    for(int index=0 ; index < size ;index++ ){
        
        int min=index;

        for(int i=index ; i< size ; i++){

            if (my_array[i] < my_array[min]){

                min = i ;
            }

        swap(size , my_array , min , index);
    } 
}
}