#ifndef LINKED_LIST_INT_H
#define LINKED_LIST_INT_H

#include <stdbool.h>

typedef struct cell_int cell_int;
typedef cell_int *linked_list_int;

struct cell_int
{
    int value;
    cell_int *next;
};

linked_list_int nil();

linked_list_int cons(linked_list_int list, int elt);

int size(linked_list_int list);

bool is_empty(linked_list_int list);

int get_element(linked_list_int list, int pos);

linked_list_int insert_element(linked_list_int list, int pos, int value);

linked_list_int remove_element(linked_list_int list, int pos);

void deallocate_list(linked_list_int list);

void print_list(linked_list_int list);

#endif
