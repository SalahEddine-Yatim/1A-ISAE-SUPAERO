#include <stdbool.h>
#include <math.h>
#include <stdio.h>

int main(void){
    long n;
    printf("Entrer n ");
    scanf("%ld", &n);

    long double pi=0.0 ;
    for (long i=0; i<=n;i++) {
        if (i%2 == 0){
            pi=pi+(1.0)/(2*i+1);
        } else{
            pi=pi+(-1.0)/(2*i+1);
        }
    }
    pi=pi*4.0;
    printf("la valeur de pi est %Lf",pi);

    return 0;
}