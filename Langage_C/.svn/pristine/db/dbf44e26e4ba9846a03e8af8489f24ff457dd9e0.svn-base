#ifndef QUEUE_MAP_H
#define QUEUE_MAP_H

#include "linked_list_map.h"
#include <stdbool.h>

/**
 * @brief An alias for the structure representing the queue
 *        
 */
typedef struct queue_map queue_map;

/**
 * @brief The structure representing the cells of the list
 */
struct queue_map {
    /** the head cell */
    cell_map* p_head ;
    /** the tail cell */
    cell_map* p_tail ;
    
};


/**
 * @brief Creates an empty p_queue
 *
 * @param p_queue  a p_queue be set to nil
 *
 * @post After the call, p_head and p_tail point to NULL.
 */
void nil_queue(queue_map* p_queue);


/**
 * @brief Get the head cell of the p_queue
 * @param p_queue  a p_queue 
 * 
 * @return the head cell 
 */
cell_map* dequeue(queue_map* p_queue);

/**
 * @brief adding an element at the tail of the p_queue
 * @param p_queue  a p_queue
 * 
 */
void enqueue(queue_map* p_queue , char* p_map);

/**
 * @brief adding a cell at the tail of the p_queue a this function is used in solver.c
 * 
 * @param p_queue  a p_queue
 * @param p_map_cell  the cell to add to p_queue
 * 
 */
void enqueue_cell(queue_map* p_queue , cell_map* p_map_cell);

/**
 * @brief Deallocate a p_queue
 *
 * @param p_queue  a p_queue
 *
 * @post After the call to `deallocate_queue`, all cells composing `p_queue`
 *       are deallocated and p_head and p_tail point to NULL.
 * 
 */
void deallocate_queue(queue_map* p_queue);

#endif


