#include <stdio.h>
#include "selection_sort.h"


int main(void) {
    int size       = 5;
    int my_array[] = { -10, 1, 2, -7, 4 };

    printf("Array before sorting: ");
    print_array(my_array, size);
    printf("\n");

    selection_sort(my_array, size);

    printf("Array after sorting: ");
    print_array(my_array, size);
    printf("\n");

    return 0;
}