#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

int leap(int year);
int year ;

int leap(int year){
    bool result = false;
    if (year % 4 == 0 && year % 100 != 0|| year % 400 == 0){
        result = true;
    }
    return result ; 
}
int main(void){

    //Test commande
    int size = 4;
    int years[] = { 1997, 1998, 2000, 2002 };
    int leaplist[] = { false, false, true, false};

    for (int i = 0; i < size; i++) {
        assert (leap(years[i]) == leaplist[i]);
    }

    printf("Enter a year ");
    scanf("%d", &year);

    if (leap(year) == true){
        printf("The year %d is a leap year: True \n",year);
    }
    else{
        printf("The year %d is not a leap year: False \n",year);
    }    
    
    return 0;
}
