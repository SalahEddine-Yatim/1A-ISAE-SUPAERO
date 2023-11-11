/**
 * @file pascal.h
 *
 * @brief Building Pascal's triangle using C arrays
 *
 * @author Christophe Garion
 *
 */

#ifndef PASCAL_H
#define PASCAL_H

/**
 * @brief Create Pascal's triangle
 *
 * @param size the size of Pascal's triangle
 * @param array the multidimensional array to be filled
 *        with Pascal's triangle
 */
void create_pascal_triangle(int size, int *array[size]);

/**
 * @brief Print Pascal's triangle
 *
 * @param size the size of Pascal's triangle
 * @param array the multidimensional array to be printed
 */
void print_pascal_triangle(int size, int *array[size]);

int* create_single_row(int size);

int** create_pointers_array(int size);

int** create_pascal_triangle_iliffe(int size);

#endif
