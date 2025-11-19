#include "./ds_dynamic_list.h"
#include "ds_globals.h"
#include <stdlib.h>
#include <string.h>

void ds_print_errors(ERROR_FLAGS throwed)
{
    if (throwed == DS_ALLOC_ERROR)
    {
        printf("Allocation Error\n");
    }
    if (throwed == DS_NULL_POINTER)
    {
        printf("Given a NULL pointer\n");
    }
    if (throwed == DS_ARGS_ERROR)
    {
        printf("Invalid args in function\n");
    }
    if (throwed == DS_NOT_FOUND)
    {
        printf("Not Found\n");
    }
    if (throwed == DS_ALREADY_EXIST)
    {
        printf("Element Already Exist\n");
    }
}

DsArray *ds_array_new(const u16 element_size, const u32 size)
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

u8 ds_array_append(DsArray *array, const void *element)
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
u8 ds_array_remove(DsArray *array, const u32 index)
{
    if (array == NULL)
        return DS_NULL_POINTER;

    if (index >= array->size)
        return DS_ARGS_ERROR;

    if (array->size == 0)
        return DS_NOT_FOUND;

    u8 *data_ptr = (u8 *)array->data;
    void *target = data_ptr + index * array->element_size;
    void *next = target + array->element_size;

    u32 bytes_to_move = (array->size - index - 1) * array->element_size;
    if (bytes_to_move > 0)
    {
        memmove(target, next, bytes_to_move);
        // I did go for memmove over memcpy because memmove is safer
        // in this case, that safety is needed over the speed of memcpy
        // since we are risking overwriting
    }

    array->size--;
    return DS_SUCCESS;
}

u8 ds_array_find(const DsArray *array, const void *element, u32 *index)
{
    if (array == NULL || element == NULL || index == NULL)
    {
        return DS_NULL_POINTER;
    }
    u8 *data_ptr = (u8 *)array->data;
    for (u32 i = 0; i < array->size; i++)
    {
        void *target = data_ptr + i * array->element_size;
        if (!memcmp(target, element, array->element_size))
        {
            *index = i;
            return DS_SUCCESS;
        }
    }
    return DS_NOT_FOUND;
}
