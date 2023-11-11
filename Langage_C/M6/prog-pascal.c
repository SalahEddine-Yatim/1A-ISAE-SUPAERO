#include <stdio.h>

#include "pascal.h"

int main(void) {
    int my_multiarray[10][10] = {0};

    creat_pascal_triangle(10 ,my_multiarray ) ;

    print_pascal_triangle_array(10,my_multiarray);

    print_pascal_triangle_pointer(10 ,my_multiarray);
}