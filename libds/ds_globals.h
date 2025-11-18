#ifndef DS_GLOBALS_H
#define DS_GLOBALS_H
#include <stdint.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

typedef enum
{
    DS_SUCCESS = 0,
    DS_ALLOC_ERROR = 1,
    DS_NULL_POINTER = 2,
    DS_ARGS_ERROR = 3,
    DS_NOT_FOUND = 4,
    DS_ALREADY_EXIST = 5
} ERROR_FLAGS;

#endif
