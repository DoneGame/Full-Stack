#include <stdio.h>
#include "stack.h"
#include "errors.h"

#define CHECKED_(StackMethod) {                   \
    if ((StackMethod) != NO_ERRORS) {             \
        stack_dump (stk, err);                    \
        return err;                               \
    }                                             \
}

int main() {
    ERROR_t err = NO_ERRORS;
    Stack_t stk = {};

    CHECKED_(stack_create(&stk));

    printf ("\n# Pushing some elements\n");
    CHECKED_(stack_push(&stk, 10));
    printf ("Pushed: %d\n", 10);
    CHECKED_(stack_push(&stk, 20));
    printf ("Pushed: %d\n", 20);
    CHECKED_(stack_push(&stk, 30));
    printf ("Pushed: %d\n", 30);
    CHECKED_(stack_push(&stk, 40));
    printf ("Pushed: %d\n", 40);
    CHECKED_(stack_push(&stk, 50));
    printf ("Pushed: %d\n", 50);
    CHECKED_(stack_push(&stk, 60));
    printf ("Pushed: %d\n", 60);
    CHECKED_(stack_push(&stk, 70));
    printf ("Pushed: %d\n", 70);

    stack_dump (stk, NO_ERRORS);

    printf ("\n# Pop some elements\n");
    StackElem_t x = 0;
    CHECKED_(stack_pop(&stk, &x));
    printf ("Poped: %d\n", x);
    CHECKED_(stack_pop(&stk, &x));
    printf ("Poped: %d\n", x);
    CHECKED_(stack_pop(&stk, &x));
    printf ("Poped: %d\n", x);
    CHECKED_(stack_pop(&stk, &x));
    printf ("Poped: %d\n", x);
    CHECKED_(stack_pop(&stk, &x));
    printf ("Poped: %d\n", x);
    CHECKED_(stack_pop(&stk, &x));
    printf ("Poped: %d\n", x);

    printf ("\n# Pushing some elements\n");
    CHECKED_(stack_push(&stk, 30));
    printf ("Pushed: %d\n", 30);
    CHECKED_(stack_push(&stk, 90));
    printf ("Pushed: %d\n", 90);
    CHECKED_(stack_push(&stk, 180));
    printf ("Pushed: %d\n", 180);

    stack_dump (stk, NO_ERRORS);

    printf ("\n# Destroying stack\n");
    CHECKED_(stack_destroy(&stk));

    stack_dump (stk, NO_ERRORS);

    return 0;
}