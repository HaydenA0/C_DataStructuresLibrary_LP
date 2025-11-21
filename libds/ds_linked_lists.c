#include "./ds_linked_lists.h"
#include "ds_globals.h"
#include <stdlib.h>
#include <string.h>

DsLinkedList *ds_llist_new(void)
{
    DsLinkedList *llist = malloc(sizeof(DsLinkedList));
    llist->head = NULL;
    llist->tail = NULL;
    llist->size = 0;
    return llist;
}

void ds_llist_destroy(DsLinkedList *llist)
{
    if (llist == NULL)
    {
        return;
    }
    DsNode *current_node = llist->head;
    while (current_node != NULL)
    {
        DsNode *next_node = current_node->next_element;
        current_node->prev_element = NULL;
        current_node->next_element = NULL;
        free(current_node);
        current_node = next_node;
    }
    free(llist);
}
DsNode *ds_node_new(void *value, const u32 element_size)
{
    if (value == NULL)
    {
        return NULL;
    }
    DsNode *output = malloc(sizeof(DsNode));
    output->next_element = NULL;
    output->prev_element = NULL;
    output->element_size = element_size;
    output->value = value;
    return output;
}
u8 ds_llist_search(const DsLinkedList *llist, const void *target_value, const DsNode **found_result)
{
    if (llist == NULL || target_value == NULL)
    {
        return DS_NULL_POINTER;
    }
    if (llist->head == NULL)
    {
        return DS_NOT_FOUND;
    }
    DsNode *current_node = llist->head;
    while (current_node != NULL)
    {
        void *target = current_node->value;
        if (!memcmp(target, target_value, current_node->element_size))
        {
            *found_result = current_node;
            return DS_SUCCESS;
        }
        current_node = current_node->next_element;
    }
    return DS_NOT_FOUND;
}
u8 ds_llist_pushfront(DsLinkedList *llist, DsNode *element)
{
    if (llist == NULL || element == NULL)
    {
        return DS_NULL_POINTER;
    }
    if (llist->head == NULL)
    {
        llist->size++;
        element->prev_element = NULL;
        element->next_element = NULL;
        llist->head = element;
        llist->tail = element;
        return DS_SUCCESS;
    }
    else
    {
        llist->size++;
        element->prev_element = NULL;
        element->next_element = llist->head;
        llist->head->prev_element = element;
        llist->head = element;
        return DS_SUCCESS;
    }
}
u8 ds_llist_pushback(DsLinkedList *llist, DsNode *element)
{
    if (llist == NULL || element == NULL)
    {
        return DS_NULL_POINTER;
    }
    if (llist->tail == NULL)
    {
        llist->size++;
        llist->head = element;
        llist->tail = element;
        element->prev_element = NULL;
        element->next_element = NULL;
        return DS_SUCCESS;
    }
    else
    {
        llist->size++;
        element->next_element = NULL;
        element->prev_element = llist->tail;
        llist->tail->next_element = element;
        llist->tail = element;
        return DS_SUCCESS;
    }
}
u8 ds_list_delete(DsLinkedList *llist, DsNode *element)
{
    if (llist == NULL || element == NULL)
    {
        return DS_NULL_POINTER;
    }
    if (llist->head == NULL || llist->tail == NULL)
    {
        return DS_INVALID_STATE;
    }
    if (llist->head == element)
    {
        if (llist->size == 1)
        {
            llist->head = NULL;
            llist->tail = NULL;
        }
        else
        {
            llist->head = element->next_element;
            llist->head->prev_element = NULL;
        }
    }
    else if (llist->tail == element)
    {
        llist->tail = element->prev_element;
        llist->tail->next_element = NULL;
    }
    else
    {
        element->next_element->prev_element = element->prev_element;
        element->prev_element->next_element = element->next_element;
    }
    element->next_element = NULL;
    element->prev_element = NULL;
    llist->size--;
    return DS_SUCCESS;
}
u8 ds_llist_insert_after(DsLinkedList *llist, DsNode *node_to_append_after, DsNode *node_to_append)
{
    if (llist == NULL || node_to_append_after == NULL)
    {
        return DS_NULL_POINTER;
    }
    if (llist->size <= 1)
    {
        ds_llist_pushfront(llist, node_to_append);
    }
    else if (node_to_append_after == llist->tail)
    {
        ds_llist_pushback(llist, node_to_append);
    }
    else
    {
        DsNode *next_node = node_to_append_after->next_element;
        node_to_append_after->next_element = node_to_append;
        node_to_append->prev_element = node_to_append_after;
        next_node->prev_element = node_to_append;
        node_to_append->next_element = next_node;
        llist->size++;
    }
    return DS_SUCCESS;
}
