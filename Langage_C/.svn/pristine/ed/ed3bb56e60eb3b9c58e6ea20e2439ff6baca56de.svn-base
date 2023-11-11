/**
 * @file test-loader.c
 *
 * @brief Simple test executable to show if the loader is good 
 *
 * @author Salah-Eddine Yatim
 *
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "loader.h"



void test_load_print_map(FILE *p_file) {

    // read dimensions on first line
    int width         = 0;
    int height        = 0;
    int fscanf_result = 0;

    fscanf_result = fscanf(p_file, "%d %d\n", &width, &height);

    if (fscanf_result != 2) {
        fprintf(stderr, "First line is not syntactically correct!\n");
        exit(EXIT_FAILURE);
    }

    //Starting Loader Test
    printf("  | tests for loading and printing p_map using pointer... ");

    char *p_map = load( width , height , p_file);

    //Reset the file to use fgets again

    rewind(p_file);

    // ignore the first line  
    int trash_width         = 0;
    int trash_height        = 0;
    int trash_fscanf_result = 0;
    trash_fscanf_result = fscanf(p_file, "%d %d\n", &trash_width, &trash_height);

    if (trash_fscanf_result != 2) { }
    //Done with first line 

    //Getting each line of the p_map 
    char line_buffer[width + 2];
    
    //Start comparing each char
    for(int i=0 ; i < height ; i++ ){

        fgets(line_buffer, width + 2, p_file);
        
        for(int j=0 ; j < width ; j++ ){

        //Comparing
        assert(p_map[i*width + j]==line_buffer[j]); 
       
        }
    }
    free(p_map);
    printf("OK!\n\n");
}

int main(void) {

    // open file. The filename is the first argument on the command
    FILE *p_file1 = NULL;
    FILE *p_file2 = NULL;
    FILE *p_file3 = NULL;
    FILE *p_file4 = NULL;
    
    // open file. The filename is the first argument on the command fopen 
    p_file1 = fopen("./data/soko1.in", "r");
    p_file2 = fopen("./data/soko2.in", "r");
    p_file3 = fopen("./data/soko3.in", "r");
    p_file4 = fopen("./data/soko4.in", "r");
   

    printf("* Starting sokoban tests...\n");
    
    //Starting Tests
    printf(" Loader tests for soko1.in \n");
    test_load_print_map(p_file1);

    printf(" Loader tests for soko2.in \n");
    test_load_print_map(p_file2);
    
    printf(" Loader tests for soko3.in \n");
    test_load_print_map(p_file3);
    
    printf(" Loader tests for soko4.in \n");
    test_load_print_map(p_file4);

    

    printf("  +-> OK!\n\n");

    fclose(p_file1);
    fclose(p_file2);
    fclose(p_file3);
    fclose(p_file4);

    return EXIT_SUCCESS;
}
