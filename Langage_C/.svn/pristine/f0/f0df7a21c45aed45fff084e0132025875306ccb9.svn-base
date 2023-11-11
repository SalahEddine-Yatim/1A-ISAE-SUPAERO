#include <stdio.h>
#include "selection_sort.h"


void print_array(int array[], int size);
void swap(int array[], int i, int j);
int index_of_minimum(int array[], int size, int start_from);
void selection_sort(int array[], int size);

void print_array(int array[], int size) {
    printf("[ ");

    for (int i = 0; i < size; i++) {
        printf("%d%s", array[i], i == size - 1 ? " " : ", ");
    }

    printf("]");
}

void swap(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int index_of_minimum(int array[], int size, int start_from) {
    int index_min = start_from;

    for (int i = start_from + 1; i < size; i++) {
        if (array[i] < array[index_min]) {
            index_min = i;
        }
    }

    return index_min;
}

void selection_sort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        swap(array, i, index_of_minimum(array, size, i));
    }
}

//int main(void) {
  //  int size       = 6;
    //int my_array[] = { -1, 0, 14, 7, -8, 10 };

//    printf("Array before sorting: ");
  //  print_array(my_array, size);
    //printf("\n");

   // selection_sort(my_array, size);

    //printf("Array after sorting: ");
   // print_array(my_array, size);
  //  printf("\n");

    //return 0;
//}
