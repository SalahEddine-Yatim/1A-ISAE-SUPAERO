#include "linked_list_int.h"
#include <stdio.h>

int main()
{
    // Test for NIL
    linked_list_int list = nil();

    printf("Test for nil : \n");
    print_list(list);
    printf("\n");

    // Test is empty
    printf("Test 1 for is empty : \n");

    if (is_empty(list))
    {
        printf("yes\n");
    } 
    else
    {
        printf("no\n");
    }

    // Test for cons
    for (int i = 0; i < 10; i++)
    {
        list = cons(list, i);
    }

    printf("Test for cons : \n");
    print_list(list);
    printf("\n");

    // Test for size
    int size_list = size(list);
    printf("Test for size : \n");
    printf("%d\n", size_list);

    // Test for get element
    printf("Test for get_element : \n");
    for (int i = 0; i < size(list); i++)
    {
        printf("%d\n", i);
    }

    // Test is empty
    printf("Test 2 for is empty : \n");

    if (is_empty(list))
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }

    // Test for insert
    list = insert_element(list, 5, 8);
    list = insert_element(list, 0, 8);
    printf("Test for insert_element : \n");
    print_list(list);
    printf("\n");

    // Test for remove
    list = remove_element(list, 0);
    list = remove_element(list, 9);
    printf("Test for remove_element : \n");
    print_list(list);
    printf("\n");

    deallocate_list(list);
}
