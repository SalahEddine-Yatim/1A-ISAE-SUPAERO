/**
 * @file linked_list_int.c
 *
 * @ingroup in101-labs
 *
 * @brief Simple implementation of a linked list
 *
 * The implementation of the linked list (functional version).
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list_int.h"

// functions from the signature
linked_list_int nil() {
    return NULL;
}

linked_list_int cons(linked_list_int list, int value) {
    cell_int *p_new_cell = malloc(sizeof(cell_int));

    if (p_new_cell == NULL) {
        printf("problem with creating cell in cons!\n");
    }

    p_new_cell->value  = value;
    p_new_cell->p_next = list;

    return p_new_cell;
}

int size(linked_list_int list) {
    int       length         = 0;
    cell_int *p_current_cell = list;

    while (p_current_cell != NULL) {
        p_current_cell = p_current_cell->p_next;
        length++;
    }

    return length;
}

bool is_empty(linked_list_int list) {
    return list == NULL;
}

void deallocate_list(linked_list_int list) {
    cell_int *p_temp_cell    = NULL;
    cell_int *p_current_cell = list;

    while (p_current_cell != NULL) {
        p_temp_cell    = p_current_cell;
        p_current_cell = p_current_cell->p_next;
        free(p_temp_cell);
    }
}

void print_list(linked_list_int list) {
    cell_int *p_current_cell = list;

    printf("[ ");

    while (p_current_cell != NULL) {
        printf("%d", p_current_cell->value);

        if (p_current_cell->p_next != NULL) {
            printf(", ");
        } else {
            printf(" ");
        }

        p_current_cell = p_current_cell->p_next;
    }

    printf("]");
}
