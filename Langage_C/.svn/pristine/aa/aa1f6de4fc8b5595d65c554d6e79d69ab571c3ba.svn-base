/**
 * @file bst_map.h
 *
 * @brief Simple definition of BST containing `cells_map` values
 *
 * @author S.Yatim
 *
 */

#ifndef BST_MAP_H
#define BST_MAP_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "loader.h"
#include "move.h"
#include "solver.h"
#include "linked_list_map.h"
#include "queue_map.h"


/**
 * @brief An alias to the structure representing the nodes of
 *        the tree.
 */
typedef struct bst_node_map bst_node_map;

/**
 * @brief A binary tree is just a pointer to the root node
 *        of the tree.
 */
typedef bst_node_map *bst_map;

/**
 * @brief The structure representing the nodes of the
 *        binary tree.
 */
struct bst_node_map {
    /** The left subtree of the node */
    bst_map left;
    /** The cell in the node */
    char*    p_map;
    /** The right subtree of the node */
    bst_map right;
};

/**
 * @brief Create a nil binary search tree.
 *
 * @return an empty binary search tree
 */
bst_map nil_tree();

/**
 * @brief Is the binary search tree empty?
 *
 * @param tree  a the tree you want to check the emptiness
 *
 * @return `true` if `tree` is empty, `false` else
 */
bool is_empty_tree(bst_map tree);

/**
 * @brief The value in the root of the binary search tree.
 *
 * @param tree  the tree
 *
 * @pre `tree` is not empty.
 *
 * @return the value in the root of the tree
 */
char* value(bst_map tree);

/**
 * @brief The number of nodes in the binary search tree.
 *
 * @param tree the tree
 *
 * @return the number of nodes in the tree
 */
int size(bst_map tree);

/**
 * @brief The height of the binary search tree.
 *
 * @param tree the tree
 *
 * @return the height of the tree
 */
int height(bst_map tree);

/**
 * @brief The left subtree of the tree.
 *
 * @param tree the tree
 *
 * @pre `tree` is not empty.
 *
 * @return the left subtree of `tree`
 */
bst_map left_child(bst_map tree);

/**
 * @brief The right subtree of the tree.
 *
 * @param tree the tree
 *
 * @pre `tree` is not empty.
 *
 * @return the right subtree of `tree`
 */
bst_map right_child(bst_map tree);


/**
 * @brief Insert a value in the tree.
 *
 * @param tree   the tree in which the value is to be inserted
 * @param value  the value to be inserted
 *
 * @return a tree in which there is a node containing `value`.
 *         This node is correctly placed with respect to the
 *         binary search tree property. If the node was already in
 *         the tree, no new node is inserted and `tree` is returned.
 */
bool is_in_tree(bst_map tree, char* p_map, int height , int width);

/**
 * @brief Insert a value in the tree.
 *
 * @param tree   the tree in which the value is to be inserted
 * @param value  the value to be inserted
 *
 * @return a tree in which there is a node containing `value`.
 *         This node is correctly placed with respect to the
 *         binary search tree property. If the node was already in
 *         the tree, no new node is inserted and `tree` is returned.
 */
void insert(bst_map tree, char* p_map , int height , int width);

/**
 * @brief Deallocate a binary search tree.
 *
 * @param tree  the tree to be deallocated
 *
 * @post After the call, all memory regions used for the nodes
 *       are deallocated
 */
void deallocate_bst(bst_map tree);


/**
 * @brief building a wining plan 
 * 
 * @param p_map_cell a pointer to a cell 
 * 
 * @param p_initial_map a pointer to the origin map  
 * 
 * @return the plan frm where how got this map 
 */
char* solve_function_bst(FILE *p_file);

#endif