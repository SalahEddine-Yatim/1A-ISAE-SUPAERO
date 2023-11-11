#include <stdio.h>
#include <math.h>
int main(void){

    float my_matrix[4][4] = { [0 ... 3][0 ... 3] = 0.0 };
    int S=0;
    float epsilon = 1E-20;
    my_matrix[3][0] = 1E-10;
    for (int i=1 ; i<4 ; i++){
       int n = i-1;
       for ( int j = 0 ; j <= n ; j++){

        if ( fabs(my_matrix[i][j]) > epsilon ){
            S = 1;
        }
       }
    }
    if ( S == 1 ){
        printf("La matrice n'est pas tri-sup");
        return 0;
    }else {
        printf("La matrice est tri-sup");
        return 0;
    }
}