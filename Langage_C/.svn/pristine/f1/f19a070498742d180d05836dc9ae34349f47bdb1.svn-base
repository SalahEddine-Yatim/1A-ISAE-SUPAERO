#include <stdbool.h>
#include <stdio.h>

int fibo(int n);
int n;

int fibo(int n){
    
    if (n==1 || n==2){
        return  1;
    }
    else{
        return fibo(n-1)+fibo(n-2);
    }
}

int main(void){

    printf("Entrer un entier positif n \n");
    scanf("%d" , &n);

    printf("Fibo de %d est %d\n",n,fibo(n));
    return 0;
}