/**
 * @file linked_list_map.c
 * 
 * @brief A simple program to use linked list structure 
 * 
 * @author Salah-Eddine Yatim
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list_map.h"

// utilitary functions goes here
cell_map* go_to_position(const linked_list_map* p_map_list, int pos) {
    cell_map* p_current_cell = *p_map_list;

    for (int i = 0; i < pos; i++) {
        p_current_cell = p_current_cell->p_next_map;
    }

    return p_current_cell;
}

void nil(linked_list_map *p_map_list) {
    *p_map_list = NULL;
}

void cons(linked_list_map *p_map_list, char* p_map) {
    
    cell_map *p_new_cell = malloc(sizeof(cell_map));

    if (p_new_cell == NULL) {
        printf("problem with creating cell in cons!\n");
    }

    p_new_cell->p_map = p_map;
    p_new_cell->p_next_map  = *p_map_list;

    *p_map_list = p_new_cell;
}

//Cette fonction sera utiliser dans le solver
void add_cell(linked_list_map* p_map_list, cell_map* p_new_cell){

    p_new_cell->p_next_map  = *p_map_list;

    *p_map_list = p_new_cell;
}


char* get_element(linked_list_map *p_map_list, int pos) {
    
    // go to position
    cell_map *p_cell = go_to_position(p_map_list, pos);

    return p_cell->p_map;
}


void deallocate_map(linked_list_map *p_map_list) {
    cell_map *p_temp_cell    = NULL;
    cell_map *p_current_cell = *p_map_list;

    while (p_current_cell != NULL) {
        p_temp_cell    = p_current_cell;
        p_current_cell = p_current_cell->p_next_map;
        
        free(p_temp_cell->p_map);
        free(p_temp_cell);
    }
}

