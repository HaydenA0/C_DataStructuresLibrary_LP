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
        printf("Not Found\n");
    }
    if (throwed == DS_ALREADY_EXIST)
    {
        printf("Element Already Exist\n");
    }
    if (throwed == DS_INVALID_STATE)
    {
        printf("The object is in an invalid state\n");
    }
}
