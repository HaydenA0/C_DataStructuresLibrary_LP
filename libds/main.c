

#include "ds_globals.h"
#include "ds_hashing.h"
#include <stdio.h>
int main()
{
    char *key = "Hajar-Hona";
    u32 hash = ds_hash_function(key, 10000);
    printf("For the key : %s\n", key);
    printf("the hash is : %d\n", hash);
}
