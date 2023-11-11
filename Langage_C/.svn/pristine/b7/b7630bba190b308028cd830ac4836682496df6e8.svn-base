/**
 * @file ring_list.c
 *
 * @author S. Yatim 
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "ring_list.h"


ring_list cons(int value);

ring_list cons(int value){

    cell_int *p_new_cell = malloc(sizeof(cell_int));
    p_new_cell->value = value;

    p_new_cell->p_next = p_new_cell ;

    return p_new_cell;
}


ring_list create_empty_ring(){

    return NULL ;
}

bool is_empty(ring_list list){

    return list ==  NULL;
}

ring_list insert(ring_list list, int value){

    cell_int *p_new_cell = malloc(sizeof(cell_int));
    cell_int *p_current_cell = list;

    p_new_cell->value = value;

    if (is_empty(list)){

        ring_list new_list = cons(value);
        return new_list;

    }
    else {

        p_new_cell->p_next = p_current_cell->p_next;
        p_current_cell->p_next = p_new_cell;
        return list ;
    }
}

ring_list rotate(ring_list list, int n){

    if (is_empty(list)){
        return list ;
    }

    cell_int *p_current_cell = list;

    for ( int i = 0 ; i < n ; i++ ){

        list = p_current_cell->p_next ; 
    }

    return list;
}

int size(ring_list list){

    if (is_empty(list)){
        return 0 ;
    }

    else { 

        cell_int current_cell = *list;
        int size = 0;

        if (current_cell.p_next == list){
            return 1;
        }

        while (current_cell.p_next != list)
        {
        size++;
        current_cell = *current_cell.p_next;
        }

    return size+1 ;
    }
}

ring_list append(ring_list list_1, ring_list list_2){
    
    if (is_empty(list_1) & is_empty(list_2)){
        return NULL ;
    }

    else{

        if (is_empty(list_1)){
            return list_2 ;
        }

        if (is_empty(list_2)){
            return list_1 ;
        }

        list_1->p_next = list_2;
        list_2->p_next = list_1;

        return list_2;
    }
}