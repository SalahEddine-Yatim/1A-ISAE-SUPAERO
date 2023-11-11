/**
 * @file test-bst-map.c
 * 
 * @brief Simple test to see if bst_map_solver work 
 *
 * @author S.Yatim
 *
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "solver.h" 
#include "bst_map.h" 
#include "linked_list_map.h"
#include "queue_map.h"
#include "loader.h"
#include "move.h"

void test_solver(FILE *p_file , char* win_plan) {

    char* plan = solve_function_bst(p_file);

    //Comparing plans ...

    int i=0;
    while(win_plan[i] != '\0'){

        assert(win_plan[i] == plan[i]);
        i++;
    }
    
    free(plan);
}

int main(void) {

    // open file. The filename is the first argument on the command
    FILE *p_file1 = NULL;
    FILE *p_file2 = NULL;
    // FILE *p_file3 = NULL;
    // FILE *p_file4 = NULL;
    // FILE *p_file5 = NULL;
    // FILE *p_file6 = NULL;
    
    // open file. The filename is the first argument on the command fopen 
    p_file1 = fopen("./data/soko_dumber.in", "r");
    p_file2 = fopen("./data/soko_dumb.in", "r");
    // p_file3 = fopen("./data/soko_dumb_imp.in", "r");
    // p_file4 = fopen("./data/soko81.in", "r");
    // p_file5 = fopen("./data/soko99.in", "r");
    // p_file6 = fopen("./data/soko1.in", "r");

    char* plan1 = "EE";
    char* plan2 = "SSSEENN";
    // char* plan3 = "IMPOSSIBLE";
    // char* plan4 = "ENNENSSNWWNENNEESWNWSSWSEWWWNEE";
    // char* plan5 = "WWNNNENEESSWWNEWWSWSSEEENNWNNEESWNWS";
    // char* plan6 = "NNWWSWWNEESWSWWWNNEESSESSWWNSEENNNENENESSSWSWENEESWWNENNWWSWWNEWWWSSESSEENNWNENEENESSSWSWENENNWWWWWWSSESSEENNWESEENEESWWWENENNWWWWSSENWNEEENESSNWWWWWWSSESSEENEEEENWSWWWNNWNEEENESSSESWW";

    printf("* Starting bst_map_solver tests...\n\n");

    printf("Test for soko_dumber...");
    test_solver(p_file1 , plan1);
    printf("DONE \n");

    printf("Test for soko_dumb...");
    test_solver(p_file2 , plan2);
    printf("DONE \n");
    
    // printf("Test for soko_dumb_imp...");
    // test_solver(p_file3 , plan3);
    // printf("DONE \n");

    // printf("Test for soko81...");
    // test_solver(p_file4 , plan4);
    // printf("DONE \n");

    // printf("Test for soko99...");
    // test_solver(p_file5 , plan5);
    // printf("DONE \n");

    // printf("Test for soko1...");
    // test_solver(p_file6 , plan6);
    // printf("DONE \n\n");


    printf("  +-> OK!\n\n");

    return 0;
}