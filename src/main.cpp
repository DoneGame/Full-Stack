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
    if ((err = stack_push(&stk, 40)) != NO_ERRORS) {
        stack_dump (stk, err);
        return err;
    }
    if ((err = stack_push(&stk, 50)) != NO_ERRORS) {
        stack_dump (stk, err);
        return err;
    }
    if ((err = stack_push(&stk, 60)) != NO_ERRORS) {
        stack_dump (stk, err);
        return err;
    }
    if ((err = stack_push(&stk, 70)) != NO_ERRORS) {
        stack_dump (stk, err);
        return err;
    }

    stack_dump (stk, NO_ERRORS);

    printf ("# Pop some elements\n");
    StackElem_t x = 0;
    if ((err = stack_pop(&stk, &x)) != NO_ERRORS) {
        stack_dump (stk, err);
        return err;
    }
    printf ("Poped: %d\n", x);
    if ((err = stack_pop(&stk, &x)) != NO_ERRORS) {
        stack_dump (stk, err);
        return err;
    }
    printf ("Poped: %d\n", x);
    if ((err = stack_pop(&stk, &x)) != NO_ERRORS) {
        stack_dump (stk, err);
        return err;
    }
    printf ("Poped: %d\n", x);
    if ((err = stack_pop(&stk, &x)) != NO_ERRORS) {
        stack_dump (stk, err);
        return err;
    }
    printf ("Poped: %d\n", x);
    if ((err = stack_pop(&stk, &x)) != NO_ERRORS) {
        stack_dump (stk, err);
        return err;
    }
    printf ("Poped: %d\n", x);
    if ((err = stack_pop(&stk, &x)) != NO_ERRORS) {
        stack_dump (stk, err);
        return err;
    }
    printf ("Poped: %d\n", x);

    printf ("# Pushing some elements\n");
    if ((err = stack_push(&stk, 30)) != NO_ERRORS) {
        stack_dump (stk, err);
        return err;
    }
    if ((err = stack_push(&stk, 90)) != NO_ERRORS) {
        stack_dump (stk, err);
        return err;
    }
    if ((err = stack_push(&stk, 180)) != NO_ERRORS) {
        stack_dump (stk, err);
        return err;
    }

    stack_dump (stk, NO_ERRORS);

    return 0;
}