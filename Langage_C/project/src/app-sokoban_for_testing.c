/**
 * @file app-sokoban_for_testing.c
 * 
 * @brief A simple program to try all function load move print and replay on a file 
 *
 * Ex. of usage:
 *
 * ./app-sokoban_for_testing ./data/soko1.in
 * 
 * @author Salah-Eddine Yatim
 */



#include <stdio.h>
#include <stdlib.h>
#include "move.h"
#include "loader.h"
#include "sokoban.h"
#include "replay_function.h"


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


    /////Print the p_map using pointer to p_map 
    char *p_map = load(width , height , p_file);

    print_map(p_map, height , width);

    // /////move player then print the new p_map 
    char *p_new_map = move_function( 'W' , p_map , height , width );

    print_map(p_new_map, height , width);

    //Si mvmt impossible on a pas d'espace a liberer on a pas utiliser malloc dans move ona tjrs la meme p_map donc cond reste 0
    int cond=0;
    if(p_new_map != p_map){
        cond = 1;
    }

    //Si on a utiliser malloc dans move cond==1 il faut liberer l'espace 
    if(cond == 1){
        free(p_new_map);
    }

    ////move with a plan 

    char* p_new_map2=replay(p_map , height ,width , 10, "NNNNNWEESNESSW");

    print_map(p_new_map2, height , width);

    free(p_map);
    free(p_new_map2);
    fclose(p_file);
    return EXIT_SUCCESS;
}

