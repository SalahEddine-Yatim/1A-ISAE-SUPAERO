#include <stdio.h>
#include <stdlib.h>

#include "linked_list_int.h"

// utilitary functions goes here

linked_list_int nil()
{
    return NULL;
}

linked_list_int cons(linked_list_int list, int value)
{
    cell_int *p_new_cell = malloc(sizeof(cell_int));
    p_new_cell->value = value;

    p_new_cell->next = list;

    return p_new_cell;
}

int size(linked_list_int list)
{
    cell_int current_cell = *list;
    int size = 0;

    while (current_cell.next != NULL)
    {
        size++;
        current_cell = *current_cell.next;
    }

    return size;
}

bool is_empty(linked_list_int list)
{
    if (list == NULL)
    {
        return true;
    }
    return false;
}

int get_element(linked_list_int list, int pos)
{
    cell_int current_cell = *(list);

    for (int i = 0; i < pos; i++)
    {
        current_cell = *current_cell.next;
    }

    return current_cell.value;
}

linked_list_int insert_element(linked_list_int list, int pos, int value)
{
    if (pos == 0)
    {
        return cons(list, value);
    }
    else
    {
        // Attention il faut que p_current_cell soit bien un pointer
        cell_int *p_new_cell = malloc(sizeof(cell_int));
        cell_int *p_current_cell = list;

        p_new_cell->value = value;

        // position in the list is in fact pos-1 bc we start at 0...
        for (int i = 0; i < pos - 1; i++)
        {
            p_current_cell = p_current_cell->next;
        }

        p_new_cell->next = p_current_cell->next;
        p_current_cell->next = p_new_cell;

        return list;
    }
}

linked_list_int remove_element(linked_list_int list, int pos)
{
    if (pos == 0)
    {
        return list->next;
    }
    else
    {
        cell_int *p_current_cell = list;

        // position in the list is in fact pos-1 bc we start at 0...
        for (int i = 0; i < pos - 1; i++)
        {
            p_current_cell = p_current_cell->next;
        }

        p_current_cell->next = ((p_current_cell->next)->next);

        return list;
    }
}

void deallocate_list(linked_list_int list)
{
    // order is very important there
    cell_int current_cell = *(list);
    cell_int *next_adress = current_cell.next;

    while (current_cell.next != NULL)
    {
        current_cell = *current_cell.next;
        free(next_adress);
        next_adress = current_cell.next;
    }

    free(list);
}

void print_list(linked_list_int list)
{
    // use of pointers because if liste vide ca marche plus
    cell_int *p_current_cell = list;

    printf("[ ");

    while (p_current_cell != NULL)
    {
        printf("%d", p_current_cell->value);
        printf(", ");
        p_current_cell = p_current_cell->next;
    }

    printf("]");
}

// functions from the signature
