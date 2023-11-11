/**
 * @file play.c
 * 
 * @brief A simple program to play the sokoban game on  console 
 *
 * Ex. of usage to play soko1.in :
 *
 * ./play ./data/soko1.in
 * 
 * @author Salah-Eddine Yatim
 */

#include <stdio.h>
#include <stdlib.h>
#include "loader.h"
#include "move.h"
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "gui.h"

//Moving fonction 
void go_dir_with_move(int width, int height, char level[height][width], char* p_map , char direction) {

    //creating a p_map with move function to replace the old p_map and matrix 
    char *p_moved_map  = move_function(direction , p_map , height ,width);

    //Copying newmap to the matrix and the  old p_map 
    for(int i=0 ; i < height ; i++ ){
        
        for(int j=0 ; j < width ; j++ ){

            //Copying
            level[i][j] = p_moved_map[ i*width + j ]; 
            p_map[ i*width + j ]= p_moved_map[ i*width + j ];
        }
    }

    //Si mvmt impossible on a pas d'espace a liberer on a pas utiliser malloc dans move ona tjrs la meme p_map donc cond reste 0
    int cond=0;
    if(p_moved_map != p_map){
        cond = 1;
    }

    //Si on a utiliser malloc dans move cond==1 il faut liberer l'espace 
    if(cond == 1){
        free(p_moved_map);
    }
}

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

    // define  level
    char level[height][width] ;
    bool stop = false;

    //Loading p_map from file 
    char *p_map = load(width , height , p_file);
    
    //Copying p_map to the matrix 
    for(int i=0 ; i < height ; i++ ){
        for(int j=0 ; j < width ; j++ ){
            //Copying
            level[i][j] = p_map[ i*width + j ]; 
        }
    }

    // initialize GUI window
    GUI_init("Sokoban", width , height );

    // display level
    GUI_show(width , height , level);

    // main loop
    while(true) {

        switch (GUI_get_key()) {
        case SDLK_UP : case 'n':
            go_dir_with_move(width , height , level, p_map , 'N');
            GUI_show(width , height , level);
            break;
        case SDLK_DOWN : case 's':
            go_dir_with_move(width , height , level , p_map  ,'S');
            GUI_show(width , height , level);
            break;
        case SDLK_LEFT : case 'w':
            go_dir_with_move(width , height , level , p_map ,'W');
            GUI_show(width , height , level);
            break;
        case SDLK_RIGHT : case 'e':
            go_dir_with_move(width , height , level , p_map , 'E');
            GUI_show(width , height , level);
            break;  
        case 'q':
            stop = true;
            break;
        case -1:
            stop = true;
            break;
        }
        if (stop) {
            break;
        }
    }

    free(p_map);

    GUI_close();

    return EXIT_SUCCESS;
}
