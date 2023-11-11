/**
 * @file replay_function.c
 * 
 * @brief A simple program that allow u to replay a game    
 *
 * @author Salah-Eddine Yati
 */


#include <stdio.h>
#include <stdlib.h>
#include "move.h"
#include "loader.h"

//replay fonction
char* replay(char* p_map, int height , int width , int lenght ,char *plan){

    char *p_new_map ;

    p_new_map = malloc(width * height * sizeof(char));
    
    if (p_new_map == NULL) {
        printf("error");
    } 

    //Copying the old p_map to p_new_map 
    for(int i=0 ; i < height ; i++ ){
        for(int j=0 ; j < width ; j++ ){

            p_new_map [i*width + j] = p_map[i*width + j] ;
        }
    }

    for(int move=0 ; move < lenght ; move++){
        char direction = plan[move];
        //Condition pour liberer lespace  
        int cond=0;

        char *p_new_map2;
        p_new_map2= move_function( direction , p_new_map , height , width );

        //Si mvmt impossible on a pas d'espace a liberer on a pas utiliser malloc donc cond reste 0
        if(p_new_map2 != p_new_map){
            cond = 1;
        }

        // p_new_map = p_new_map2
        for(int i=0 ; i < height ; i++ ){
            for(int j=0 ; j < width ; j++ ){

                p_new_map [i*width + j] = p_new_map2[i*width + j] ;
            }
        }

        //Si on a utiliser malloc cond==1 il faut liberer l'espace 
        if(cond == 1){
            free(p_new_map2);
        }
    }

    return p_new_map;
}

