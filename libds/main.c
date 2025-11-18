#include "./ds_dynamic_list.h"
#include "./ds_globals.h"
#include <stdio.h>

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
        printf("\n");
    }
}

int main(void)
{

    DsArray *array = ds_array_new(sizeof(int), 0);
    for (int i = 0; i < 10; i++)
    {
        ERROR_FLAGS throwed = ds_array_append(array, &i);
        ds_print_errors(throwed);
    }
    for (u8 i = 0; i < 10; i++)
    {
        int element = ((int *)array->data)[i];
        printf("List[%d] = %d\n", i, element);
    }

    return DS_SUCCESS;
}
