/**
 * @file linked_list_int.h
 *
 * @brief Simple definition of linked list containing `int` values
 *
 * @author Christophe Garion
 *
 * This is a simple definition of a linked list containing `int`
 * values implemented using cells linked by pointers. Warning: the cells
 * pointers should not be shared as deallocation of a linked list
 * deallocates the memory space reserved for the cells!
 *
 * This is a "functional" version of the list.
 *
 * The API of the linked list is defined as follows:
 *
 * - a function to create an empty list
 * - a function to append an element at the beginning of the list
 * - a function to return the size of a list
 * - a function to return if a list is empty of not
 * - a function to deallocate a list
 * - a function to print a list
 *
 * You should always call the deallocate function when you do not
 * need a list anymore.
 */

#ifndef LINKED_LIST_INT_FUN_H
#define LINKED_LIST_INT_FUN_H

#include <stdbool.h>

/**
 * @brief An alias for the structure representing the cells
 */
typedef struct cell_int cell_int;

/**
 * @brief The structure representing the cells of the list
 */
struct cell_int {
    /** the value in the cell */
    int      value;
    /** the next cell in the list */
    cell_int *p_next;
};

/**
 * @brief An alias for the structure representing the
 *        linked list
 */
typedef cell_int *linked_list_int;

/**
 * @brief Creates an empty list
 *
 * @return an empty list
 */
linked_list_int nil();

/**
 * @brief Append an element at the beginning of a list
 *
 * @param list    the list to which the value is to be appended
 * @param value   the value to be added in the list
 *
 * @return a list whose first cell contains the value passed as
 *         parameter. The next cells are the ones of the list
 *         passed as parameter.
 */
linked_list_int cons(linked_list_int list, int value);

/**
 * @brief The length of a list
 *
 * @param list  the list whose length is wanted
 *
 * @return the length of the list (i.e. the number of distinct cells
 *         in the list)
 */
int size(linked_list_int list);

/**
 * @brief Is the list empty?
 *
 * @param list  the list
 *
 * @return true is the list is empty, false else
 */
bool is_empty(linked_list_int list);

/**
 * @brief Deallocate a list
 *
 * @param list  the list to be deallocated
 *
 * @post After the call to `deallocate_list`, all cells composing `list`
 *       are deallocated.
 */
void deallocate_list(linked_list_int list);

/**
 * @brief Print a list
 *
 * @param list  the list to be printed
 *
 * @post After the call to `print_list`, the list is printed on the console
 *       in classical format using `[]`.
 */
void print_list(linked_list_int list);

#endif
