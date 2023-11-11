#include <stdio.h>

int main(void){
    
    struct point {
        float x;
        float y;
    };

    struct point my_point1;

    my_point1.x = 1 ;
    my_point1.y = 2 ;

    printf("p1: (%f, %f) \n",my_point1.x,my_point1.y);

    struct point my_point2 = my_point1 ;
    printf("p2: (%f, %f) \n",my_point2.x,my_point2.y);

    my_point2.x = 5 ;

    printf("p1: (%f, %f) \n",my_point1.x,my_point1.y);
    printf("p2: (%f, %f) \n",my_point2.x,my_point2.y);

    return 0;
}