/**
 * @file test_linked_list_map.c
 * 
 * @brief Simple test to see if queue_map work 
 *
 * @author S.Yatim
 *
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "loader.h"
#include "queue_map.h"

char* load_map(FILE *p_file);

char* load_map(FILE *p_file) {

    // read dimensions on first line
    int width         = 0;
    int height        = 0;
    int fscanf_result = 0;

    fscanf_result = fscanf(p_file, "%d %d\n", &width, &height);

    if (fscanf_result != 2) {
        fprintf(stderr, "First line is not syntactically correct!\n");
        exit(EXIT_FAILURE);
    }

    char *p_map = load( width , height , p_file);

    return p_map;
   
}

void test_queue_map(FILE *p_file1 , FILE *p_file2 , FILE *p_file3 , FILE *p_file4) {

    //Loading the maps from files
    char* p_map1 = load_map(p_file1);
    char* p_map2 = load_map(p_file2);
    char* p_map3 = load_map(p_file3);
    char* p_map4 = load_map(p_file4);

    //Staet building the queue_map
    queue_map* p_queue = malloc(sizeof(queue_map));
    nil_queue(p_queue);
    
    //enqueueing element in the p_queue 
    enqueue(p_queue , p_map1);
    enqueue(p_queue , p_map2);
    enqueue(p_queue , p_map3);
    enqueue(p_queue , p_map4);

    //dequeueing element in the p_queue
    cell_map* cell_map1   = dequeue(p_queue);
    char* map1_from_list = cell_map1->p_map ;

    cell_map* cell_map2   = dequeue(p_queue);
    char* map2_from_list = cell_map2->p_map ;

    cell_map* cell_map3   = dequeue(p_queue);
    char* map3_from_list = cell_map3->p_map ;
    
    cell_map* cell_map4   = dequeue(p_queue);
    char* map4_from_list = cell_map4->p_map ;

    printf("Comparing map from load fonction and from the p_queue ... Done \n\n");
    printf("Verifying the order of dequeued maps ... \n\n");

    //Comparing ...
    assert(p_map1 == map1_from_list);
    assert(p_map2 == map2_from_list);
    assert(p_map3 == map3_from_list);
    assert(p_map4 == map4_from_list);

    //Delallocating
    deallocate_queue(p_queue);
    
    free(p_map1);
    free(p_map2);
    free(p_map3);
    free(p_map4);

    free(cell_map1);
    free(cell_map2);
    free(cell_map3);
    free(cell_map4);
    
    free(p_queue);
    
    printf("Test building a map and enqueueing and dequeueing it with 4 maps OK!\n");
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


    printf("* Starting queue_map tests...\n\n");

    test_queue_map(p_file1 , p_file2 , p_file3 , p_file4);

    printf("  +-> OK!\n\n");

    return 0;
}


