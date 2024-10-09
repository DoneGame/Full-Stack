#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include "errors.h"


typedef int StackElem_t;
const size_t initial_stack_size = 2;

struct Stack_t
{
    StackElem_t *data;
    size_t size;
    size_t capacity;
};


ERROR_t       stack_create (Stack_t *stk);
ERROR_t       stack_push (Stack_t *stk, StackElem_t x);
void          stack_dump (Stack_t stk, ERROR_t program_err);
static size_t increase_capacity (size_t current_capacity);
static size_t decrease_capacity (size_t current_capacity);

#endif //STACK_H