#ifndef SOLVER_H
#define SOLVER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list_map.h"
#include "queue_map.h"
#include "loader.h"
#include "move.h"


/**
 * @brief verifying if the map is a winnig one
 * 
 * @param p_map  a pointer to a map 
 * 
 * @param width
 * 
 * @param height 
 * 
 * @return True or False 
 */
bool is_a_winnig_map(char* p_map , int height , int width);

/**
 * @brief verifying if the map is in p_list
 * 
 * @param p_map  a pointer to a map 
 * 
 * @param p_list a pointer to a list of maps 
 * 
 * @return True or False
 */
bool is_in_list_map(linked_list_map* p_list, char* p_map, int height , int width);

/**
 * @brief building a wining plan 
 * 
 * @param p_map_cell a pointer to a cell 
 * 
 * @param p_initial_cell a pointer to the origin cell_map  
 * 
 * @return the plan to get the map in initial_cell
 */
char* build_plan(cell_map* p_map_cell , cell_map* p_initial_cell);

/**
 * @brief verifying if two maps are the same  
 * 
 * @param p_map1 a pointer to first map 
 * 
 * @param p_map2 a pointer to the second map
 *
 * @param width
 * 
 * @param height 
 * 
 * @return True or false
 */
bool equal_maps(char* p_map1 , char* p_map2 , int height , int width);

/**
 * @brief give the solvi,g plan if possible 
 * 
 * @param p_file the file contains the map to solve 
 * 
 * @return the plan to solve the map  
 */
char* solve_function(FILE *p_file);


#endif