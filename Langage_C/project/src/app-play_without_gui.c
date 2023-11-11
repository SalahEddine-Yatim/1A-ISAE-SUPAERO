/**
 * @file app-play_without_gui.c
 * 
 * @brief A simple program to play the sokoban game on terminal without the console 
 *
 * Ex. of usage:
 *
 * ./app-play_without_gui ./data/soko1.in
 * 
 * @author Salah-Eddine Yatim
 */

#include <stdio.h>
#include <stdlib.h>
#include "move.h"
#include "loader.h"
#include "sokoban.h"


int main(int argc, char *argv[]) {
    // testing if a filename has been given
    if (argc != 2) {
        fprintf(stderr, "You must provide a file name!\n");
        exit(EXIT_FAILURE);
    }
    
    // open file. The filename is the first argument on the command
    // line, hence stored in argv[1]
    FILE *p_file = NULL;

    p_file = fopen(argv[1], "r");

    if (p_file == NULL) {
        fprintf(stderr, "Cannot read file %s!\n", argv[1]);
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

    //Loading p_map from file 

    char *p_map = load(width , height , p_file);
    print_map(p_map, height , width);

    //Start playing
    printf("Start the game \n");

    char direction;
    
    //Start taking command
    while ( direction != 'q'){

        scanf("%c" , &direction);
        
        //Moving South
        if (direction == 's'){
            //Moving 
            //Condition pour liberer lespace  
            int cond=0;

            char *p_new_map;
            p_new_map= move_function( 'S' , p_map , height , width );

            //Si mvmt impossible on a pas d'espace a liberer on a pas utiliser malloc donc cond reste 0
            if(p_new_map != p_map){
                cond = 1;
            }

            // p_new_map = p_new_map2
            for(int i=0 ; i < height ; i++ ){
                for(int j=0 ; j < width ; j++ ){

                p_map [i*width + j] = p_new_map[i*width + j] ;
                }
            }

            //Si on a utiliser malloc cond==1 il faut liberer l'espace 
            if(cond == 1){
                free(p_new_map);
            }
            
            print_map(p_map , height , width);
        }
        //Moving North
        if (direction == 'n'){
            //Moving 
            //Condition pour liberer lespace  
            int cond=0;

            char *p_new_map;
            p_new_map= move_function( 'N' , p_map , height , width );

            //Si mvmt impossible on a pas d'espace a liberer on a pas utiliser malloc donc cond reste 0
            if(p_new_map != p_map){
                cond = 1;
            }

            // p_new_map = p_new_map2
            for(int i=0 ; i < height ; i++ ){
                for(int j=0 ; j < width ; j++ ){

                p_map [i*width + j] = p_new_map[i*width + j] ;
                }
            }

            //Si on a utiliser malloc cond==1 il faut liberer l'espace 
            if(cond == 1){
                free(p_new_map);
            }
            
            print_map(p_map , height , width);
        }
        //Moving West
        if (direction == 'w'){
            //Moving 
            //Condition pour liberer lespace  
            int cond=0;

            char *p_new_map;
            p_new_map= move_function( 'W' , p_map , height , width );

            //Si mvmt impossible on a pas d'espace a liberer on a pas utiliser malloc donc cond reste 0
            if(p_new_map != p_map){
                cond = 1;
            }

            // p_new_map = p_new_map2
            for(int i=0 ; i < height ; i++ ){
                for(int j=0 ; j < width ; j++ ){

                p_map [i*width + j] = p_new_map[i*width + j] ;
                }
            }

            //Si on a utiliser malloc cond==1 il faut liberer l'espace 
            if(cond == 1){
                free(p_new_map);
            }
            
            print_map(p_map , height , width);
        }
        //Moving East
        if (direction == 'e'){
            //Moving 
            //Condition pour liberer lespace  
            int cond=0;

            char *p_new_map;
            p_new_map= move_function( 'E' , p_map , height , width );

            //Si mvmt impossible on a pas d'espace a liberer on a pas utiliser malloc donc cond reste 0
            if(p_new_map != p_map){
                cond = 1;
            }

            // p_new_map = p_new_map2
            for(int i=0 ; i < height ; i++ ){
                for(int j=0 ; j < width ; j++ ){

                p_map [i*width + j] = p_new_map[i*width + j] ;
                }
            }

            //Si on a utiliser malloc cond==1 il faut liberer l'espace 
            if(cond == 1){
                free(p_new_map);
            }
            
            print_map(p_map , height , width);
        }    
    }

    printf("you give up already loser \n");
    free(p_map);
    fclose(p_file);
    return EXIT_SUCCESS;

}
