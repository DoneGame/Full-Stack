#ifndef ERRORS_H
#define ERRORS_H

typedef enum ERROR_t {
    NO_ERRORS = 0,
    INCORRECT_POINTER = 1,
    MEM_ALLOC_ERR = 2,
    MEM_REALLOC_ERR = 3,
    INDEX_OUT_OF_RANGE = 4,
    INCORRECT_STACK = 5,
    POP_ON_EMPTY_STK = 6,
} ERROR_t;

#endif //ERRORS_H