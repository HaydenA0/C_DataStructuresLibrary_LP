#include "ds_globals.h"
#include "ds_linked_lists.h"
#include <stdio.h>
#include <stdlib.h>

void print_list(const DsLinkedList *llist)
{
    DsNode *current = llist->head;
    printf("List (size %u): ", llist->size);
    while (current)
    {
        printf("%d ", *(int *)current->value);
        current = current->next_element;
    }
    printf("\n");
}

int main(void)
{

    DsLinkedList *list = ds_llist_new();
    if (!list)
    {
        fprintf(stderr, "Failed to create linked list\n");
        return 1;
    }

    for (int i = 1; i <= 3; ++i)
    {
        int *value = malloc(sizeof(int));
        *value = i;
        DsNode *node = ds_node_new(value, sizeof(int));
        ds_llist_pushfront(list, node);
    }
    print_list(list);

    for (int i = 4; i <= 5; ++i)
    {
        int *value = malloc(sizeof(int));
        *value = i;
        DsNode *node = ds_node_new(value, sizeof(int));
        ds_llist_pushback(list, node);
    }
    print_list(list);

    int target = 3;
    const DsNode *found = NULL;
    if (ds_llist_search(list, &target, &found) == DS_SUCCESS)
    {
        printf("Found value: %d\n", *(int *)found->value);
    }
    else
    {
        printf("Value %d not found in the list\n", target);
    }

    target = 2;
    if (ds_llist_search(list, &target, &found) == DS_SUCCESS)
    {
        ds_list_delete(list, (DsNode *)found);
        printf("Deleted value: %d\n", target);
    }
    print_list(list);

    DsNode *current = list->head;
    while (current)
    {
        free(current->value);
        current = current->next_element;
    }
    ds_llist_destroy(list);

    return 0;
}
