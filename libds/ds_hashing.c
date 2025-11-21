#include "ds_hashing.h"
#include "ds_globals.h"

DsArray *hash_array = ds_array_new(sizeof(DsLinkedList), H_SIZE);
u32 ds_hash_function(const char *key, const u32 hash_size)
{
    // polynomial hashing
    // because it gives every element
    // a VERY different weight
    // check Schwartz-Zippel lemma
    if (hash_size <= 0 || key == NULL)
    {
        return DS_ARGS_ERROR;
    }
    u32 hash = 0;
    u32 prime = 569;
    for (int i = 0; key[i] != '\0'; i++)
    {
        hash = (hash * prime + key[i]) % hash_size;
    }
    return hash;
}
