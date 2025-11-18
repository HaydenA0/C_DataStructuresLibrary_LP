#ifndef DS_DYNAMIC_LIST_H
#define DS_DYNAMIC_LIST_H
#include "./ds_globals.h"

typedef struct
{
    u32 size;
    u32 capacity;
    void *data;
    u16 element_size;
} DsArray;

DsArray *ds_array_new(u16 element_size, u32 size);
void ds_array_destroy(DsArray *array);
u8 ds_array_append(DsArray *array, void *element);

#endif
