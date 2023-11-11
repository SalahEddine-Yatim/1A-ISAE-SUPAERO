#include <stdio.h>

struct point {
        double x;
        double y;
    };

void print_point(struct point nom_point);

void print_point(struct point nom_point){

     printf("point: (%f, %f)\n", nom_point.x, nom_point.y);
}

void translate_point(struct point p1 , struct point trans);
void translate_point(struct point p1 , struct point trans ){
    // Fonction non terminer 
    p1.x = p1.x + trans.x; 
    p1.y = p1.y + trans.y;

}


int main(void) {
    
    struct point p1;
    p1.x = 1.0;
    p1.y = 2.0;

    struct point trans;
    trans.x = 1.0;
    trans.y = 2.0;

    print_point(p1);

    struct point p2 = p1;
    printf("p2: (%f, %f)\n", p2.x, p2.y);

    printf("moving p2...\n");
    p2.x = 0.5;
    print_point(p1);
    print_point(p2);

    translate_point(p1,trans);
    print_point(p1);


    return 0;
}
