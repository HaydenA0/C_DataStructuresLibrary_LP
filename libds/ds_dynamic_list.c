#include "./ds_dynamic_list.h"
#include "ds_globals.h"
#include <stdlib.h>
#include <string.h>

DsArray *ds_array_new(u16 element_size, u32 size)
{
    if (element_size == 0)
    {
        return NULL;
    }

    DsArray *new_array = malloc(sizeof(DsArray));
    if (new_array == NULL)
    {
        return NULL;
    }

    new_array->size = size;
    new_array->capacity = 2 * size;
    new_array->element_size = element_size;
    new_array->data = NULL;

    return new_array;
}

void ds_array_destroy(DsArray *array)
{
    if (array == NULL)
    {
        return;
    }

    array->capacity = 0;
    array->size = 0;

    if (array->data != NULL)
    {
        free(array->data);
        array->data = NULL;
    }
}

u8 ds_array_append(DsArray *array, void *element)
{
    if (array == NULL || element == NULL)
    {
        return DS_NULL_POINTER;
    }

    if (array->size >= array->capacity)
    {
        u32 new_capacity = (array->capacity == 0 ? 1 : array->capacity * 2);

        void *new_body = realloc(array->data, new_capacity * array->element_size);
        if (new_body == NULL)
        {
            return DS_ALLOC_ERROR;
        }

        array->data = new_body;
        array->capacity = new_capacity;
    }

    void *last_address = (u8 *)array->data + (array->size * array->element_size);
    memcpy(last_address, element, array->element_size);

    array->size++;

    return DS_SUCCESS;
}
