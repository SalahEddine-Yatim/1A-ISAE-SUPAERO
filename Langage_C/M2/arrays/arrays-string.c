#include <stdio.h>

int main(void){

    char my_string[] = "I love C";
    int i = 0;

    while (my_string[i] != '\0'){
        
        printf("%c \n", my_string[i]);

        i = i+1;
    }
    
    return 0;
}

