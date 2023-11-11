#include <stdio.h>
#include <stdlib.h>
#include "../include/binary_search_tree_int.h"

// auxiliary functions
void print_level(bst_int tree, int level) {
    for (int i = 0; i < level - 1; i++) {
        printf("   ");
    }

    if (is_empty(tree)) {
        printf("%snil\n", level == 0 ? "" : " +-");
        return;
    }

    printf("%s(%d)\n", level == 0 ? "" : " +-", tree->value);
    print_level(tree->left, level + 1);
    print_level(tree->right, level + 1);
}

// functions from the signature
void print_bst(bst_int tree) {
    print_level(tree, 0);
}

bst_int nil(){

    return NULL;
}

bool is_empty(bst_int tree){

    return tree == NULL ;
}

int value(bst_int tree){

    return tree->value;

}

int size(bst_int tree){

    if (is_empty(tree)){

        return 0 ;
    }

    else{
        return size(left_child(tree))+size(right_child(tree))+1;

    }
}   

int max(int a , int b){

    if (a<=b)
    {
        return b ;
    }

    return a ;

}

int height(bst_int tree){
    
    if (is_empty(tree)){

        return 0;
    }

    else{ 

        return max(height(right_child(tree)),height(left_child(tree)))+1;

    }
}

bst_int left_child(bst_int tree){

    return tree->left;

}

bst_int right_child(bst_int tree){

    return tree->right;

}

bst_int retrieve(bst_int tree, int value){

    if (is_empty(tree)){
        return NULL;
    }

    else if(tree->value == value){
        
        return tree;
    }

    else if(retrieve(right_child(tree),value)->value == value ){

        return retrieve(right_child(tree),value);

    }

    else if(retrieve(left_child(tree),value)->value == value ){

        return retrieve(left_child(tree),value);
    }

    return tree;
}

bst_int insert(bst_int tree, int value){

    if(is_empty(tree)){
        bst_node_int *p_value_nod = malloc(sizeof(bst_node_int)) ;
        p_value_nod->left = NULL ;
        p_value_nod->right = NULL ;
        p_value_nod->value = value ;
        tree = p_value_nod;
    }

    else if( tree->value < value ){
        tree->left = insert(left_child(tree), value);
    }

    else if( tree->value > value ){
        tree->right = insert(right_child(tree), value);
    }
    
    return tree;
}

//a completer
// bst_int delete(bst_int tree, int value){

//     bst_int p_value_nod = retrieve(tree , value) ;
    
//     if (p_value_nod == NULL)
//     {
//         return tree;
//     }
    
//     else{

//     }

// }

void in_order_dfs_infix(bst_int tree){


}

void deallocate_bst(bst_int tree){


}
