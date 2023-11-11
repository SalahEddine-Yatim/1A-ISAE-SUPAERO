/**
 * @file test-move.c
 *
 * @brief Simple test executable to show if the move function is good 
 *
 * @author Salah-Eddine Yatim
 *
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "move.h"
#include "loader.h"



void test_move_player(FILE *p_file , char direction , FILE *rp_file) {

    printf("  | tests for moving player ... ");

    //Rest p_file because we use soko_move1 et soko_move2 multiple time
    
    rewind(p_file); 

    // read dimensions on first line
    int width         = 0;
    int height        = 0;
    int fscanf_result = 0;

    fscanf_result = fscanf(p_file, "%d %d\n", &width, &height);

    if (fscanf_result != 2) {
        fprintf(stderr, "First line is not syntactically correct!\n");
        exit(EXIT_FAILURE);
    }

    //Starting moving test 
    
    char *origin_map = load( width , height , p_file);

    //Using move function 
    char *move_origin_map = move_function( direction , origin_map , height , width);


    // ignore the first line  from result file to load the result p_map for using fgets function 
    int trash_width         = 0;
    int trash_height        = 0;
    int trash_fscanf_result = 0;
    trash_fscanf_result = fscanf(rp_file, "%d %d\n", &trash_width, &trash_height);

    if (trash_fscanf_result != 2) {
        fprintf(stderr, "First line is not syntactically correct!\n");
        exit(EXIT_FAILURE);
    }
    //Done with first line from result p_map


    //Getting result p_map 
    char *result_map = load( width , height , rp_file);
    

    //Start comparing each char from each p_map 
    for(int i=0 ; i < height ; i++ ){
        
        for(int j=0 ; j < width ; j++ ){

        //Comparing
        assert(result_map[i*width + j] == move_origin_map[i*width + j]); 
       
        }
    }


    //Si mvmt impossible on a pas d'espace a liberer on a pas utiliser malloc 
    if(move_origin_map != origin_map){
        free(move_origin_map);
    }

    free(result_map);
    free(origin_map);
    

    printf("OK!\n");
}

int main(void) {

//Origin File     
    FILE *p_file1 = NULL;
    FILE *p_file2 = NULL;
    FILE *p_file3 = NULL;
    FILE *p_file4 = NULL;
    FILE *p_file5 = NULL;
    FILE *p_file6 = NULL;
    FILE *p_file7 = NULL;
    FILE *p_file8 = NULL;
    FILE *p_file9 = NULL;
    FILE *p_file10 = NULL;
    FILE *p_file11 = NULL;
    FILE *p_file12 = NULL;
    FILE *p_file13 = NULL;
    FILE *p_file14 = NULL;
    FILE *p_file15 = NULL;
    FILE *p_file16 = NULL;
    FILE *p_file17 = NULL;
    FILE *p_file18 = NULL;
    FILE *p_file19 = NULL;
    FILE *p_file20 = NULL;
    FILE *p_file21 = NULL;
    FILE *p_file22 = NULL;
    FILE *p_file23 = NULL;
    FILE *p_file24 = NULL;
    FILE *p_file25 = NULL;
    FILE *p_file26 = NULL;
    FILE *p_file27 = NULL;
    FILE *p_file28 = NULL;
    FILE *p_file29 = NULL;
    FILE *p_file30 = NULL;


   //Result File 
    FILE *rp_file1 = NULL;
    FILE *rp_file2 = NULL;
    FILE *rp_file3 = NULL;
    FILE *rp_file4 = NULL;
    FILE *rp_file5 = NULL;
    FILE *rp_file6 = NULL;
    FILE *rp_file7 = NULL;
    FILE *rp_file8 = NULL;
    FILE *rp_file9 = NULL;
    FILE *rp_file10 = NULL;
    FILE *rp_file11 = NULL;
    FILE *rp_file12 = NULL;
    FILE *rp_file13 = NULL;
    FILE *rp_file14 = NULL;
    FILE *rp_file15 = NULL;
    FILE *rp_file16 = NULL;
    FILE *rp_file17 = NULL;
    FILE *rp_file18 = NULL;
    FILE *rp_file19 = NULL;
    FILE *rp_file20 = NULL;
    FILE *rp_file21 = NULL;
    FILE *rp_file22 = NULL;
    FILE *rp_file23 = NULL;
    FILE *rp_file24 = NULL;
    FILE *rp_file25 = NULL;
    FILE *rp_file26 = NULL;
    FILE *rp_file27 = NULL;
    FILE *rp_file28 = NULL;
    FILE *rp_file29 = NULL;
    FILE *rp_file30 = NULL;
    FILE *rp_file31 = NULL;
    FILE *rp_file32 = NULL;
    FILE *rp_file33 = NULL;
    FILE *rp_file34 = NULL;
    FILE *rp_file35 = NULL;
    FILE *rp_file36 = NULL;

    // open Origin   file. The filename is the first argument on the command fopen 
    p_file1 = fopen("./data/soko_move_1.in", "r");
    p_file2 = fopen("./data/soko_move_2.in", "r");
    p_file3 = fopen("./data/soko_move_3_1.in", "r");
    p_file4 = fopen("./data/soko_move_3_2.in", "r");
    p_file5 = fopen("./data/soko_move_3_3.in", "r");
    p_file6 = fopen("./data/soko_move_3_4.in", "r");
    p_file7 = fopen("./data/soko_move_4_1.in", "r");
    p_file8 = fopen("./data/soko_move_4_2.in", "r");
    p_file9 = fopen("./data/soko_move_4_3.in", "r");
    p_file10 = fopen("./data/soko_move_4_4.in", "r");
    p_file11 = fopen("./data/soko_move_5_1.in", "r");
    p_file12 = fopen("./data/soko_move_5_2.in", "r");
    p_file13 = fopen("./data/soko_move_5_3.in", "r");
    p_file14 = fopen("./data/soko_move_5_4.in", "r");
    p_file15 = fopen("./data/soko_move_6_1.in", "r");
    p_file16 = fopen("./data/soko_move_6_2.in", "r");
    p_file17 = fopen("./data/soko_move_6_3.in", "r");
    p_file18 = fopen("./data/soko_move_6_4.in", "r");
    p_file19 = fopen("./data/soko_move_W_E.in", "r");
    p_file20 = fopen("./data/soko_move_W_W.in", "r");
    p_file21 = fopen("./data/soko_move_W_N.in", "r");
    p_file22 = fopen("./data/soko_move_W_S.in", "r");
    p_file23 = fopen("./data/soko_move_B_W_E.in", "r");
    p_file24 = fopen("./data/soko_move_B_W_W.in", "r");
    p_file25 = fopen("./data/soko_move_B_W_N.in", "r");
    p_file26 = fopen("./data/soko_move_B_W_S.in", "r");
    p_file27 = fopen("./data/soko_move_B_B_E.in", "r");
    p_file28 = fopen("./data/soko_move_B_B_W.in", "r");
    p_file29 = fopen("./data/soko_move_B_B_N.in", "r");
    p_file30 = fopen("./data/soko_move_B_B_S.in", "r");
    

    // open Result file. The filename is the first argument on the command fopen
    rp_file1 = fopen("./data/soko_move_1_N.in", "r");
    rp_file2 = fopen("./data/soko_move_1_S.in", "r");
    rp_file3 = fopen("./data/soko_move_1_E.in", "r");
    rp_file4 = fopen("./data/soko_move_1_W.in", "r");
    rp_file5 = fopen("./data/soko_move_2_N.in", "r");
    rp_file6 = fopen("./data/soko_move_2_S.in", "r");
    rp_file7 = fopen("./data/soko_move_2_E.in", "r");
    rp_file8 = fopen("./data/soko_move_2_W.in", "r");
    rp_file9 = fopen("./data/soko_move_3_1_E.in", "r");
    rp_file10 = fopen("./data/soko_move_3_2_E.in", "r");
    rp_file11 = fopen("./data/soko_move_3_3_E.in", "r");
    rp_file12 = fopen("./data/soko_move_3_4_E.in", "r");
    rp_file13 = fopen("./data/soko_move_4_1_W.in", "r");
    rp_file14 = fopen("./data/soko_move_4_2_W.in", "r");
    rp_file15 = fopen("./data/soko_move_4_3_W.in", "r");
    rp_file16 = fopen("./data/soko_move_4_4_W.in", "r");
    rp_file17 = fopen("./data/soko_move_5_1_N.in", "r");
    rp_file18 = fopen("./data/soko_move_5_2_N.in", "r");
    rp_file19 = fopen("./data/soko_move_5_3_N.in", "r");
    rp_file20 = fopen("./data/soko_move_5_4_N.in", "r");
    rp_file21 = fopen("./data/soko_move_6_1_S.in", "r");
    rp_file22 = fopen("./data/soko_move_6_2_S.in", "r");
    rp_file23 = fopen("./data/soko_move_6_3_S.in", "r");
    rp_file24 = fopen("./data/soko_move_6_4_S.in", "r");
    rp_file25 = fopen("./data/soko_move_W_E.in", "r");
    rp_file26 = fopen("./data/soko_move_W_W.in", "r");
    rp_file27 = fopen("./data/soko_move_W_N.in", "r");
    rp_file28 = fopen("./data/soko_move_W_S.in", "r");
    rp_file29 = fopen("./data/soko_move_B_W_E.in", "r");
    rp_file30 = fopen("./data/soko_move_B_W_W.in", "r");
    rp_file31 = fopen("./data/soko_move_B_W_N.in", "r");
    rp_file32 = fopen("./data/soko_move_B_W_S.in", "r");
    rp_file33 = fopen("./data/soko_move_B_B_E.in", "r");
    rp_file34 = fopen("./data/soko_move_B_B_W.in", "r");
    rp_file35 = fopen("./data/soko_move_B_B_N.in", "r");
    rp_file36 = fopen("./data/soko_move_B_B_S.in", "r");

    
    //Starting Moving Tests

    printf("* Starting Move tests  \n");

    test_move_player(p_file1 , 'N' , rp_file1);
    test_move_player(p_file1 , 'S' , rp_file2);
    test_move_player(p_file1 , 'E' , rp_file3);
    test_move_player(p_file1 , 'W' , rp_file4);
    test_move_player(p_file2 , 'N' , rp_file5);
    test_move_player(p_file2 , 'S' , rp_file6);
    test_move_player(p_file2 , 'E' , rp_file7);
    test_move_player(p_file2 , 'W' , rp_file8);
    test_move_player(p_file3 , 'E' , rp_file9);
    test_move_player(p_file4 , 'E' , rp_file10);
    test_move_player(p_file5 , 'E' , rp_file11);
    test_move_player(p_file6 , 'E' , rp_file12);
    test_move_player(p_file7 , 'W' , rp_file13);
    test_move_player(p_file8 , 'W' , rp_file14);
    test_move_player(p_file9 , 'W' , rp_file15);
    test_move_player(p_file10 , 'W' , rp_file16);
    test_move_player(p_file11 , 'N' , rp_file17);
    test_move_player(p_file12 , 'N' , rp_file18);
    test_move_player(p_file13 , 'N' , rp_file19);
    test_move_player(p_file14 , 'N' , rp_file20);
    test_move_player(p_file15 , 'S' , rp_file21);
    test_move_player(p_file16 , 'S' , rp_file22);
    test_move_player(p_file17 , 'S' , rp_file23);
    test_move_player(p_file18 , 'S' , rp_file24);
    test_move_player(p_file19 , 'E' , rp_file25);
    test_move_player(p_file20 , 'W' , rp_file26);
    test_move_player(p_file21 , 'N' , rp_file27);
    test_move_player(p_file22 , 'S' , rp_file28);
    test_move_player(p_file23 , 'E' , rp_file29);
    test_move_player(p_file24 , 'W' , rp_file30);
    test_move_player(p_file25 , 'N' , rp_file31);
    test_move_player(p_file26 , 'S' , rp_file32);
    test_move_player(p_file27 , 'E' , rp_file33);
    test_move_player(p_file28 , 'W' , rp_file34);
    test_move_player(p_file29 , 'N' , rp_file35);
    test_move_player(p_file30 , 'S' , rp_file36);


    printf("  +-> OK!\n\n");

//Closing Origin files 
    fclose(p_file1);
    fclose(p_file2);
    fclose(p_file3);
    fclose(p_file4);
    fclose(p_file5);
    fclose(p_file6);
    fclose(p_file7);
    fclose(p_file8);
    fclose(p_file9);
    fclose(p_file10);
    fclose(p_file11);
    fclose(p_file12);
    fclose(p_file13);
    fclose(p_file14);
    fclose(p_file15);
    fclose(p_file16);
    fclose(p_file17);
    fclose(p_file18);
    fclose(p_file19);
    fclose(p_file20);
    fclose(p_file21);
    fclose(p_file22);
    fclose(p_file23);
    fclose(p_file24);
    fclose(p_file25);
    fclose(p_file26);
    fclose(p_file27);
    fclose(p_file28);
    fclose(p_file29);
    fclose(p_file30);

//Closing Result files 
    fclose(rp_file1);
    fclose(rp_file2);
    fclose(rp_file3);
    fclose(rp_file4);
    fclose(rp_file5);
    fclose(rp_file6);
    fclose(rp_file7);
    fclose(rp_file8);
    fclose(rp_file9);
    fclose(rp_file10);
    fclose(rp_file11);
    fclose(rp_file12);
    fclose(rp_file13);
    fclose(rp_file14);
    fclose(rp_file15);
    fclose(rp_file16);
    fclose(rp_file17);
    fclose(rp_file18);
    fclose(rp_file19);
    fclose(rp_file20);
    fclose(rp_file21);
    fclose(rp_file22);
    fclose(rp_file23);
    fclose(rp_file24);
    fclose(rp_file25);
    fclose(rp_file26);
    fclose(rp_file27);
    fclose(rp_file28);
    fclose(rp_file29);
    fclose(rp_file30);
    fclose(rp_file31);
    fclose(rp_file32);
    fclose(rp_file33);
    fclose(rp_file34);
    fclose(rp_file35);
    fclose(rp_file36);
    
    return EXIT_SUCCESS;
}
