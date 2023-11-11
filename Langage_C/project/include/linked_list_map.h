#ifndef LINKED_LIST_INT_H
#define LINKED_LIST_INT_H

#include <stdbool.h>

/**
 * @brief An alias for the structure representing the cells of map 
 */
typedef struct cell_map cell_map;

/**
 * @brief The structure representing the cells of the linked_list
 */
struct cell_map {
    /** the p_map stored in the cell */
    char* p_map ;
    /** the next p_map in the list */
    cell_map* p_next_map ;
    /** the direction utiliser pour avoir cette liste (cette parti sera util dans le solver) */
    char dir ;
    /** the cell contains the map from where we got the new map (cette parti sera util dans le solver) */
    cell_map* p_origin_map ;
    /** the number of maps we past by to get the p_map (cette parti sera util dans le solver) */
    int depth ;

};

/**
 * @brief An alias for the structure representing the
 *        linked list
 */
typedef cell_map* linked_list_map;

/**
 * @brief Creates an empty list
 *
 * @param p_list  a pointer to the list to be set to nil
 *
 * @post After the call, p_list points to a NULL cell.
 */
void nil(linked_list_map* p_map_list);

/**
 * @brief Append an element at the beginning of a list
 *
 * @param p_map_list  a pointer to the list to be modified
 * @param p_map  the value to be added in the list
 *
 * @post The first cell of the list is now a new cell
 *       containing the value passed as parameter. The
 *       other cells of the list are not modified and the
 *       new first cell has the previously first cell for
 *       next cell.
 */
void cons(linked_list_map* p_map_list, char* p_map);

/**
 * @brief Append a cell at the beginning of a list
 *
 * @param p_map_list  a pointer to the list to be modified
 * @param new_cell   the cell to be added in the list
 *
 * @post The first cell of the list is now the cell passed as parameter. The
 *       other cells of the list are not modified and the
 *       new first cell has the previously first cell for
 *       next cell.
 *       (Cette fonction sera utiliser dans le solver)
 */
void add_cell(linked_list_map* p_map_list, cell_map* p_new_cell);


/**
 * @brief Get an element in the list at a specified position
 *
 * @param p_map_list  a pointer to the list to be queried
 * @param pos     the position of the wanted element
 * @pre   `pos` should be comprised between 0 and the length of
 *         the list (excluded)
 *
 * @return the value stored at position `pos`
 */
char* get_element(linked_list_map* p_map_list, int pos);



/**
 * @brief Deallocate a list
 *
 * @param p_map_list  a pointer to them p_map to be deallocated
 *
 * @post After the call to `deallocate_map`, all cells composing `list`
 *       are deallocated AND the pointer representing the list is also
 *       deallocated. `p_map_list` is `NULL` after the call.
 */
void deallocate_map(linked_list_map* p_map_list);



#endif