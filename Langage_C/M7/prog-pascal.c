/**
 * @file prog-pascal.c
 *
 * @brief Test Pascal's triangle implementation
 *
 * @author Christophe Garion
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "pascal.h"

int main(void) {

    int size = 11 ;

    int** pascal_triangle = create_pascal_triangle_iliffe(size);

    create_pascal_triangle(size, pascal_triangle);
    print_pascal_triangle(size, pascal_triangle);
    for ( int i=0 ; i<size ; i++){
        free(pascal_triangle[i]);
    }
    free(pascal_triangle);

    return 0;
    return 0;
}
