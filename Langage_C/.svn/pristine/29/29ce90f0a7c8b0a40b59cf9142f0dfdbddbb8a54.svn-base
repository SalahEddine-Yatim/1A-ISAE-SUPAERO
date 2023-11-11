/**
 * @file loader.c
 * 
 * @brief A simple program to load the p_map from a .in file to a pointer  
 *
 * @author Salah-Eddine Yatim
 */

#include <stdio.h>
#include <stdlib.h>


char* load(int width ,int height, FILE *p_file ) {
   
    ///////  Start building the structur pointer_map

    char *p_map ;

    p_map = malloc(width * height * sizeof(char));
    
    if (p_map == NULL) {
        printf("error");
    }  

    char line_buffer[width+2];

    for(int i=0 ; i < height ; i++ ){

        fgets(line_buffer , width+2 , p_file);

        for(int j=0 ; j < width ; j++ ){

            *(p_map + i*width + j) = line_buffer[j] ;
        }
    }
    return p_map;
}