#include <stdio.h>

int inc(int i);
pretty_print(int i); //Pas de type de fonction 
void add(int i, int j) ; //";" qui manque 

int inc(int i) { // redefinition de la nature de la fonction inc 
    return i + 1;
}

pretty_print(int i) { //Pas de type de fonction 
    printf("Here is %d\n", i);
    // Pas de return
} 


void add(int i, int j) {
    printf("%d\n", i + j);
    // Pas de return
} 

int main(void) {
    int    i = 1;
    double j = 3.5;
    int    z = 0;

    pretty_print(i);

    printf("inc(%d) = %d\n", i, inc(i)); /// c'est inc(i) et non incr(i)

    pretty_print("Now, an addition!"); // la fonction pretty_print prend un int 

    z = i + j ; //z = add(i, j); // Fonction add est de type Void ( sans return )

    return 0;
}
