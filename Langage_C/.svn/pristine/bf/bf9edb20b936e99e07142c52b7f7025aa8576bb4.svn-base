#include <stdbool.h>
#include <math.h>
#include <stdio.h>

int main(void){
    double epsilon=1E-15;
    double xk = 2.0;
    double xk1 = 0.5*(xk+(2/xk));

    while (xk-xk1 > epsilon){
        xk=xk1;
        xk1= 0.5*(xk+(2/xk));
        
    }
    printf("sqrt2 est %.20f",xk);

    return 0;
}