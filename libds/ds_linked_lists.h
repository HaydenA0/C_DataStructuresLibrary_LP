#ifndef DS_LINKED_LIST_H
#define DS_LINKED_LIST_H

/*
 * llist : means linked list
 * caller must not use llist or nodes after the ds_llist_destroy
 * function as it assumes node values were malloced
 */

#include "ds_globals.h"
typedef struct DsNode
{
    struct DsNode *prev_element;
    struct DsNode *next_element;
    void *value;
    u32 element_size;

} DsNode;

typedef struct DsLinkedList
{
    DsNode *head;
    DsNode *tail;
    u32 size;

} DsLinkedList;
DsLinkedList *ds_llist_new(void);
void ds_llist_destroy(DsLinkedList *llist);
DsNode *ds_node_new(void *value, const u32 element_size);
void ds_node_destroy(const void *value, const u32 element_size); // WARN :do not use not implemented

u8 ds_llist_search(const DsLinkedList *llist, const void *target_value,
                   const DsNode **found_result);

u8 ds_llist_pushfront(DsLinkedList *llist, DsNode *element); // append at the begining
u8 ds_llist_pushback(DsLinkedList *llist, DsNode *element);  // append at the end
u8 ds_list_delete(DsLinkedList *llist, DsNode *element);
u8 ds_llist_insert_after(DsLinkedList *llist, DsNode *node_to_append_after, DsNode *node_to_append);
u8 ds_llist_remove_after(DsLinkedList *llist, DsNode *node); // remove after node

#endif
