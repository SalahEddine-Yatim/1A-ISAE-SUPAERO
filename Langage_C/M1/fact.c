#include <stdbool.h>
#include <math.h>
#include <stdio.h>

int main(void){
    long long int f=1;
    int n ;
    printf("n1?");
    scanf("%d", &n );

    for (int i=1 ; i<= n ; i++){
        f=f*i ;
    }

    printf("%d! = %Ld",n,f);
    return 0;
}
