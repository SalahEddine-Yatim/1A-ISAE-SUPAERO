/**
 * @file bst_map.c
 * 
 * @brief A simple program to use bst_map  
 * 
 * @author Salah-Eddine Yatim
 */


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst_map.h"
#include "solver.h" 
#include "linked_list_map.h"
#include "queue_map.h"
#include "loader.h"
#include "move.h"

bst_map nil_tree(){

    return NULL;
}

bool is_empty_tree(bst_map tree){

    return tree == NULL ;
}

char* value(bst_map tree){

    return tree->p_map;
}

int size(bst_map tree){

    if (is_empty_tree(tree)){

        return 0 ;
    }

    else{
        return size(left_child(tree))+size(right_child(tree))+1;

    }
}   

int max(int a , int b){

    if (a<=b){
        return b ;
    }
    return a ;
}

int height(bst_map tree){
    
    if (is_empty_tree(tree)){

        return 0;
    }
    else{ 

        return max(height(right_child(tree)),height(left_child(tree)))+1;
    }
}

bst_map left_child(bst_map tree){

    return tree->left;
}

bst_map right_child(bst_map tree){

    return tree->right;
}

bool is_in_tree(bst_map tree, char* p_map, int height , int width){

    if(is_empty_tree(tree)){

        return false;
    }

    else if( strncmp(tree->p_map, p_map , height*width) < 0  ){
        is_in_tree(right_child(tree), p_map, height , width);
    }

    else if( strncmp(tree->p_map, p_map , height*width) > 0 ){
        is_in_tree(left_child(tree), p_map , height , width);
    }

    else if( strncmp(tree->p_map, p_map , height*width) == 0 ){
        return true;
    }
    
    return false;
}

void insert(bst_map tree, char* p_map, int height , int width){

    if(is_empty_tree(tree)){
        bst_node_map *p_map_nod = malloc(sizeof(bst_node_map)) ;
        p_map_nod->left = NULL ;
        p_map_nod->right = NULL ;
        p_map_nod->p_map = p_map ;
        tree = p_map_nod;
    }

    else if( strncmp(tree->p_map, p_map, height*width) < 0 ){
        insert(right_child(tree), p_map, height , width);
    }

    else if( strncmp(tree->p_map, p_map, height*width) > 0  ){
        insert(left_child(tree), p_map, height , width);
    }
    
}

void deallocate_bst(bst_map tree){

    if(is_empty_tree(tree)){
        
        return;
    }


    deallocate_bst(tree->right);
    deallocate_bst(tree->left);

    free(tree->p_map);
    free(tree);

}
char* solve_function_bst(FILE *p_file) {
    
    if (p_file == NULL) {
        fprintf(stderr, "Cannot read file !\n");
        exit(EXIT_FAILURE);
    }

    // read dimensions on first line
    int width         = 0;
    int height        = 0;
    int fscanf_result = 0;

    fscanf_result = fscanf(p_file, "%d %d\n", &width, &height);

    if (fscanf_result != 2) {
        fprintf(stderr, "First line is not syntactically correct!\n");
        exit(EXIT_FAILURE);
    }

    //STARTING THE SOLVER  (Sokoban solver algorithm)

    char* p_initial_map = load(width , height , p_file);
    cell_map* p_initial_map_cell = malloc(sizeof(cell_map));

    p_initial_map_cell->depth = 0 ;
    p_initial_map_cell->p_map = p_initial_map ;
    p_initial_map_cell->p_origin_map = NULL;
    p_initial_map_cell->p_next_map = NULL;

    queue_map* search_queue = malloc(sizeof(queue_map)); 
    queue_map* dequeued_queue = malloc(sizeof(queue_map));
    
    bst_map explored_list = nil_tree();

    nil_queue(search_queue);
    nil_queue(dequeued_queue);

    explored_list = nil_tree();

    enqueue_cell(search_queue , p_initial_map_cell);
    insert(explored_list , p_initial_map, height , width);

    cell_map*  p_current_cell ;

    while (search_queue->p_head->p_next_map != NULL){

        p_current_cell = dequeue(search_queue);
        char* p_current_map = p_current_cell->p_map ;

        enqueue_cell(dequeued_queue , p_current_cell);

        if(is_a_winnig_map(p_current_map , height , width)){

            break; 
        }  

        char directions[] = {'N', 'S', 'E' , 'W'};

        for (int i=0 ; i < 4 ; i++){

            char dir = directions[i];

            char* p_new_map = move_function(dir, p_current_map, height, width);

            //Si mvmt impossible on a pas d'espace a liberer on a pas utiliser malloc dans move
            if(p_current_map != p_new_map){

                if (is_in_tree(explored_list, p_new_map, height , width)){

                    free(p_new_map);
                }
                else{

                    cell_map* p_new_cell = malloc(sizeof(cell_map));

                    p_new_cell->dir = dir;
                    p_new_cell->p_map = p_new_map ;
                    p_new_cell->p_origin_map = p_current_cell ;
                    p_new_cell->depth = p_current_cell->depth + 1 ;
                    
                    insert(explored_list , p_new_map, height , width);
                    enqueue_cell(search_queue , p_new_cell);
                }
            }
        }

    }

    if(is_a_winnig_map(p_current_cell->p_map , height , width)){
            
            char* plan = build_plan(p_current_cell , p_initial_map_cell);

            deallocate_queue(search_queue);
            free(search_queue);
            deallocate_queue(dequeued_queue);
            free(dequeued_queue);
            deallocate_bst(explored_list);

            return plan ;
    }
    
    else{

        deallocate_queue(search_queue);
        free(search_queue);
        deallocate_queue(dequeued_queue);
        free(dequeued_queue);
        deallocate_bst(explored_list);

        printf("THIS MAP IS IMPOSSIBLE TO SOLVE \n");

        char* plan = (char*) malloc(11*sizeof(char)) ;
        plan = "IMPOSSIBLE";
        
        return plan ;
    }

}