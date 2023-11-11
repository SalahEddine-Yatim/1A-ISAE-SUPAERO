/**
 * @file sokoban.c
 * 
 * @brief A simple program to print a p_map 
 * 
 * @author Salah-Eddine Yatim
 */


#include <stdio.h>
#include <stdlib.h>


//print fonction 
void print_map(char* p_map, int height , int width){
    
    for(int i=0 ; i < height ; i++ ){

        printf(" ");
        for(int j=0 ; j < width ; j++ ){

           printf("%c" , p_map[i*width + j]);
        }
        printf("\n");
    }
}