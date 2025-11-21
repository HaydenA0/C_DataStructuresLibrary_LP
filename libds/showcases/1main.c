#include "./ds_dynamic_array.h"
#include "./ds_globals.h"
#include <stdio.h>

int main(void)
{

    int size = 10;
    DsArray *array = ds_array_new(sizeof(int), 0);
    for (u8 i = 0; i < size; i++)
    {
        int element = i;
        ERROR_FLAGS throwed = ds_array_append(array, &element);
        ds_print_errors(throwed);
    }
    for (u8 i = 0; i < array->size; i++)
    {
        int element = ((int *)array->data)[i];
        printf("List[%d] = %d\n", i, element);
    }
    ERROR_FLAGS throwed = ds_array_remove(array, 5);
    ds_print_errors(throwed);
    printf("Removed the element of index 5\n");
    for (u8 i = 0; i < array->size; i++)
    {
        int element = ((int *)array->data)[i];
        printf("List[%d] = %d\n", i, element);
    }
    int searched_element = 7;
    u32 index = -1;
    throwed = ds_array_find(array, &searched_element, &index);
    ds_print_errors(throwed);
    if (throwed == DS_SUCCESS)
    {
        printf("We have found the element %d at the position : %d\n", searched_element, index);
    }

    return DS_SUCCESS;
}
