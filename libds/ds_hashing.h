#ifndef DS_HASHING_H
#define DS_HASHING_H
/*
 *Quadratic probing... does not require the
 *use of a second hash function and is thus likely to be
 *simpler and faster in practice [than double hashing]
 *simpler and faster in practice [ Rehash
 *when the table reaches a certain load factor
 */
#include "ds_dynamic_array.h"
#include "ds_globals.h"
#include "ds_linked_lists.h"
u32 ds_hash_function(const char *key, const u32 hash_size);

#endif
