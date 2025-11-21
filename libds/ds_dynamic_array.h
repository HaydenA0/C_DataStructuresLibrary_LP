#ifndef DS_DYNAMIC_ARRAY_H
#define DS_DYNAMIC_ARRAY_H
#include "./ds_globals.h"

typedef struct
{
    u32 size;
    u32 capacity;
    void *data;
    u16 element_size;
} DsArray;

DsArray *ds_array_new(const u16 element_size, const u32 size);
void ds_array_destroy(DsArray *array);
u8 ds_array_append(DsArray *array, const void *element);
u8 ds_array_remove(DsArray *array, const u32 index);
u8 ds_array_find(const DsArray *array, const void *element, u32 *index);

#endif
