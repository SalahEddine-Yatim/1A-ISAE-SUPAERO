#include <stdio.h>

int main(void){
    int n=0 ;

    while ( n <= 0){
        printf("Enter un entier positif n ");
        scanf( "%d" , &n);
    }

    int my_array[n];
    for (int i=0 ; i<n ; i++){
        printf("Enter le %d entier du tableau ", i+1 );
        scanf( "%d" , &my_array[i]);
        
    }
    printf("[");
    for (int e=0 ; e<n-1 ; e++){
        printf(" %d," , my_array[e]);
    }
    printf(" %d ]",my_array[n-1]);

    return 0;
}