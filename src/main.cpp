#include <stdio.h>
#include "stack.h"
#include "errors.h"

// #define CHECKED_(StackMethod) {                   \
//     if ((err = (StackMethod)) != NO_ERRORS) {    \
//         StackDump (stk, err);                    \
//         return err;                               \
//     }                                             \
// }

int main() {
    ERROR_t err = NO_ERRORS;
    Stack_t stk = {};

    printf ("# Creating stack\n");
    if ((err = stack_create(&stk)) != NO_ERRORS) {
        stack_dump (stk, err);
        return err;
    } 

    printf ("# Pushing some elements\n");
    if ((err = stack_push(&stk, 10)) != NO_ERRORS) {
        stack_dump (stk, err);
        return err;
    }
    if ((err = stack_push(&stk, 20)) != NO_ERRORS) {
        stack_dump (stk, err);
        return err;
    }
    if ((err = stack_push(&stk, 30)) != NO_ERRORS) {
        stack_dump (stk, err);
        return err;
    }

    stack_dump (stk, NO_ERRORS);

    return 0;
}