/**
 * @file move.c
 * 
 * @brief A simple program to move the a player   
 *
 * @author Salah-Eddine Yatim
 */

#include <stdio.h>
#include <stdlib.h>

char* move_function(char direction , char* p_map , int height , int width){

    //Search for the player emplacement ligne et colonne 
    int ligne;
    int coln;

    for(int i=0 ; i < height ; i++ ){

        for(int j=0 ; j < width ; j++ ){

            if( p_map[i*width + j] == '@' || p_map[i*width + j] == '+' ){
                ligne = i  ;
                coln = j;
                break; 
                }
        }
    }
     
    /// Trying to move north  
    if( direction == 'N'){

        //Player against wall 
        if(p_map[(ligne-1)*width + coln] == '#'){
            return p_map;
        }

        //Player against box 
        if(p_map[(ligne-1)*width + coln] == '$' || p_map[(ligne-1)*width + coln] == '*'){

            //Player against 2 boxs or box then wall 
            if(p_map[(ligne-2)*width + coln] == '#' || p_map[(ligne-2)*width + coln] == '$' || p_map[(ligne-2)*width + coln] == '*'){
                return p_map;
            }

            //Creating the result p_map because the mvmt is possibl pusshing box 
            else{
                char *p_new_map ;

                p_new_map = malloc(width * height * sizeof(char));
    
                if (p_new_map == NULL) {
                      printf("error");
                }

                // p_new_map = p_map;
                for(int i=0 ; i < height ; i++ ){

                    for(int j=0 ; j < width ; j++ ){

                        p_new_map [i*width + j] = p_map[i*width + j] ;
                    }
                }
                //Apply modification on the new p_map 

                if(p_map[(ligne-2)*width + coln] == '.'){
                    p_new_map[(ligne-2)*width + coln] = '*';
                }  
                else{
                    p_new_map[(ligne-2)*width + coln] = '$';
                } 

                if(p_map[(ligne-1)*width + coln] == '$'){
                    p_new_map[(ligne-1)*width + coln] = '@';
                }  
                else{
                    p_new_map[(ligne-1)*width + coln] = '+';
                }

                if(p_map[(ligne)*width + coln] == '@'){
                    p_new_map[(ligne)*width + coln] = ' ';
                }  
                else{
                    p_new_map[(ligne)*width + coln] = '.';
                }

            return p_new_map;
            }
        }
        //Creating the result p_map because the mvmt is possibl
        else{
            char *p_new_map ;

            p_new_map = malloc(width * height * sizeof(char));
    
            if (p_new_map == NULL) {
                printf("error");
            }
            
            // p_new_map = p_map;
            for(int i=0 ; i < height ; i++ ){

                    for(int j=0 ; j < width ; j++ ){

                        p_new_map [i*width + j] = p_map[i*width + j] ;
                    }
                }
            //Apply modification on the new p_map 

            if(p_map[(ligne-1)*width + coln] == ' '){
                p_new_map[(ligne-1)*width + coln] = '@';
            }  
            else{
                p_new_map[(ligne-1)*width + coln] = '+';
            }

            if(p_map[(ligne)*width + coln] == '@'){
                p_new_map[(ligne)*width + coln] = ' ';
            }  
            else{
                p_new_map[(ligne)*width + coln] = '.';
            }

        return p_new_map;     
        }   
    }
    /// Trying to move south
    if( direction == 'S'){

        //Player against wall 
        if(p_map[(ligne+1)*width + coln] == '#'){
            return p_map;
        }

        //Player against box 
        if(p_map[(ligne+1)*width + coln] == '$' || p_map[(ligne+1)*width + coln] == '*'){

            //Player against 2 boxs or box then wall 
            if(p_map[(ligne+2)*width + coln] == '#' || p_map[(ligne+2)*width + coln] == '$' || p_map[(ligne+2)*width + coln] == '*'){
                return p_map;
            }

            //Creating the result p_map because the mvmt is possibl pusshing box 
            else{
                char *p_new_map ;

                p_new_map = malloc(width * height * sizeof(char));
    
                if (p_new_map == NULL) {
                      printf("error");
                }

                // p_new_map = p_map;
                for(int i=0 ; i < height ; i++ ){

                    for(int j=0 ; j < width ; j++ ){

                        p_new_map [i*width + j] = p_map[i*width + j] ;
                    }
                }
                //Apply modification on the new p_map 

                if(p_map[(ligne+2)*width + coln] == '.'){
                    p_new_map[(ligne+2)*width + coln] = '*';
                }  
                else{
                    p_new_map[(ligne+2)*width + coln] = '$';
                } 

                if(p_map[(ligne+1)*width + coln] == '$'){
                    p_new_map[(ligne+1)*width + coln] = '@';
                }  
                else{
                    p_new_map[(ligne+1)*width + coln] = '+';
                }

                if(p_map[(ligne)*width + coln] == '@'){
                    p_new_map[(ligne)*width + coln] = ' ';
                }  
                else{
                    p_new_map[(ligne)*width + coln] = '.';
                }

            return p_new_map;  
            }
        }

        //Creating the result p_map because the mvmt is possibl
        else{
            char *p_new_map ;

            p_new_map = malloc(width * height * sizeof(char));
    
            if (p_new_map == NULL) {
                printf("error");
            }
            
            // p_new_map = p_map;
            for(int i=0 ; i < height ; i++ ){

                    for(int j=0 ; j < width ; j++ ){

                        p_new_map [i*width + j] = p_map[i*width + j] ;
                    }
                }
            //Apply modification on the new p_map 

            if(p_map[(ligne+1)*width + coln] == ' '){
                p_new_map[(ligne+1)*width + coln] = '@';
            }  
            else{
                p_new_map[(ligne+1)*width + coln] = '+';
            }

            if(p_map[(ligne)*width + coln] == '@'){
                p_new_map[(ligne)*width + coln] = ' ';
            }  
            else{
                p_new_map[(ligne)*width + coln] = '.';
            }
        
        return p_new_map;
        }
    }
    /// Trying to move east
    if( direction == 'E'){

        //Player against wall 
        if(p_map[ligne*width +(coln+1)] == '#'){
            return p_map;
        }

        //Player against box
        if(p_map[ligne*width +(coln+1)] == '$' || p_map[ligne*width +(coln+1)] == '*'){

            //Player against 2 boxs or box then wall 
            if(p_map[ligne*width +(coln+2)] == '#' || p_map[ligne*width +(coln+2)] == '$' || p_map[ligne*width +(coln+2)] == '*'){
                return p_map;
            }

            //Creating the result p_map because the mvmt is possibl pusshing box 
            else{
                char *p_new_map ;

                p_new_map = malloc(width * height * sizeof(char));
    
                if (p_new_map == NULL) {
                      printf("error");
                }

                // p_new_map = p_map
                for(int i=0 ; i < height ; i++ ){

                    for(int j=0 ; j < width ; j++ ){

                        p_new_map [i*width + j] = p_map[i*width + j] ;
                    }
                }
                //Apply modification on the new p_map 

                if(p_map[(ligne)*width + (coln+2)] == '.'){
                    p_new_map[(ligne)*width + (coln+2)] = '*';
                }  
                else{
                    p_new_map[(ligne)*width + (coln+2)] = '$';
                } 

                if(p_map[(ligne)*width + (coln+1)] == '$'){
                    p_new_map[(ligne)*width + (coln+1)] = '@';
                }  
                else{
                    p_new_map[(ligne)*width + (coln+1)] = '+';
                }

                if(p_map[(ligne)*width + coln] == '@'){
                    p_new_map[(ligne)*width + coln] = ' ';
                }  
                else{
                    p_new_map[(ligne)*width + coln] = '.';
                }

            return p_new_map;  
            }
        }

        //Creating the result p_map because the mvmt is possibl
        else{
            char *p_new_map ;

            p_new_map = malloc(width * height * sizeof(char));
    
            if (p_new_map == NULL) {
                printf("error");
            }
            
            // p_new_map = p_map;
            for(int i=0 ; i < height ; i++ ){

                    for(int j=0 ; j < width ; j++ ){

                        p_new_map [i*width + j] = p_map[i*width + j] ;
                    }
                }
            //Apply modification on the new p_map 

            if(p_map[(ligne)*width + (coln+1)] == ' '){
                p_new_map[(ligne)*width + (coln+1)] = '@';
            }  
            else{
                p_new_map[(ligne)*width + (coln+1)] = '+';
            }

            if(p_map[(ligne)*width + coln] == '@'){
                p_new_map[(ligne)*width + coln] = ' ';
            }  
            else{
                p_new_map[(ligne)*width + coln] = '.';
            }

        return p_new_map;
        }
    }
    /// Trying to move west 
    if( direction == 'W'){

        //Player against wall 
        if(p_map[ligne*width +(coln-1)] == '#'){
            return p_map;
        }

        //Player against box
        if(p_map[ligne*width +(coln-1)] == '$' || p_map[ligne*width +(coln-1)] == '*'){

            //Player against 2 boxs or box then wall 
            if(p_map[ligne*width +(coln-2)] == '#' || p_map[ligne*width +(coln-2)] == '$' || p_map[ligne*width +(coln-2)] == '*'){
                return p_map;
            }

            //Creating the result p_map because the mvmt is possibl pusshing box 
            else{
                char *p_new_map ;

                p_new_map = malloc(width * height * sizeof(char));
    
                if (p_new_map == NULL) {
                      printf("error");
                }

                // p_new_map = p_map;
                for(int i=0 ; i < height ; i++ ){

                    for(int j=0 ; j < width ; j++ ){

                        p_new_map [i*width + j] = p_map[i*width + j] ;
                    }
                }

                //Apply modification on the new p_map 

                if(p_map[(ligne)*width + (coln-2)] == '.'){
                    p_new_map[(ligne)*width + (coln-2)] = '*';
                }  
                else{
                    p_new_map[(ligne)*width + (coln-2)] = '$';
                } 

                if(p_map[(ligne)*width + (coln-1)] == '$'){
                    p_new_map[(ligne)*width + (coln-1)] = '@';
                }  
                else{
                    p_new_map[(ligne)*width + (coln-1)] = '+';
                }

                if(p_map[(ligne)*width + coln] == '@'){
                    p_new_map[(ligne)*width + coln] = ' ';
                }  
                else{
                    p_new_map[(ligne)*width + coln] = '.';
                }

            return p_new_map;  
            }
        }

        //Creating the result p_map because the mvmt is possibl
        else{
            char *p_new_map ;

            p_new_map = malloc(width * height * sizeof(char));
    
            if (p_new_map == NULL) {
                printf("error");
            }

            // p_new_map = p_map

            for(int i=0 ; i < height ; i++ ){

                    for(int j=0 ; j < width ; j++ ){

                        p_new_map [i*width + j] = p_map[i*width + j] ;
                    }
                }
            //Apply modification on the new p_map 

            if(p_map[(ligne)*width + (coln-1)] == ' '){
                p_new_map[(ligne)*width + (coln-1)] = '@';
            }  
            else{
                p_new_map[(ligne)*width + (coln-1)] = '+';
            }

            if(p_map[(ligne)*width + coln] == '@'){
                p_new_map[(ligne)*width + coln] = ' ';
            }  
            else{
                p_new_map[(ligne)*width + coln] = '.';
            }

        return p_new_map; 
        }
    }
    
printf("You must check the parametres \n");
exit(EXIT_FAILURE);    
}
