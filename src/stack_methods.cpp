#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

ERROR_t stack_create (Stack_t *stk) {
    if (! stk)
        return INCORRECT_POINTER;

    #ifndef NDEBUG
        printf ("Trying to allocate stack\n");
    #endif //NDEBUG

    StackElem_t *array = (StackElem_t *) calloc (initial_stack_size, sizeof(StackElem_t));

    #ifndef NDEBUG
        printf ("Stack allocated at adress %lu\n", (unsigned long) array);
    #endif //NDEBUG

    if (! array)
        return MEM_ALLOC_ERR;

    stk->data = array;
    stk->size = 0;
    stk->capacity = initial_stack_size;

    return NO_ERRORS;
}

ERROR_t stack_push (Stack_t *stk, StackElem_t x) {
    if (! stk)
        return INCORRECT_POINTER;

    if (stk->size == stk->capacity) {
        size_t new_size = increase_capacity (stk->capacity);

        #ifndef NDEBUG
            printf ("Trying to reallocate stack\n");
        #endif //NDEBUG

        StackElem_t *array = (StackElem_t *) realloc (stk->data, new_size * sizeof(StackElem_t));

        #ifndef NDEBUG
            printf ("Stack reallocated at adress %lu, new size = %lu\n", (unsigned long) array, (unsigned long) new_size);
        #endif //NDEBUG

        if (! array)
            return MEM_ALLOC_ERR;

        stk->capacity = new_size;
        stk->data = array;
    }

    if (! stk->data)
        return INCORRECT_POINTER;
    if (stk->size >= stk->capacity)
        return INDEX_OUT_OF_RANGE;

    stk->data[stk->size] = x;
    stk->size++;

    return NO_ERRORS;
}

ERROR_t stack_pop (Stack_t *stk, StackElem_t *x) {
    if (! stk)
        return INCORRECT_POINTER;
    if (! x)
        return INCORRECT_POINTER;

    if (increase_capacity(increase_capacity(stk->size)) == stk->capacity) {
        size_t new_size = decrease_capacity (stk->capacity);

        #ifndef NDEBUG
            printf ("Trying to reallocate stack\n");
        #endif //NDEBUG

        StackElem_t *array = (StackElem_t *) realloc (stk->data, new_size * sizeof(StackElem_t));

        #ifndef NDEBUG
            printf ("Stack reallocated at adress %lu, new size = %lu\n", (unsigned long) array, (unsigned long) new_size);
        #endif //NDEBUG

        if (! array)
            return MEM_ALLOC_ERR;

        stk->capacity = new_size;
        stk->data = array;
    }

    if (! stk->data)
        return INCORRECT_POINTER;
    if (stk->size >= stk->capacity)
        return INDEX_OUT_OF_RANGE;

    stk->size--;
    *x = stk->data[stk->size];

    return NO_ERRORS;
}

void stack_dump (Stack_t stk, ERROR_t program_err) {
    if (program_err != NO_ERRORS) {
        printf ("Program error: ");

        switch (program_err) {
            case INCORRECT_POINTER:  printf ("Some pointer is equal to 0!\n");
                                     break;
            case MEM_ALLOC_ERR:      printf ("Unable to allocate stack!\n");
                                     break;
            case MEM_REALLOC_ERR:    printf ("Unable to reallocate stack!\n");
                                     break;
            case INDEX_OUT_OF_RANGE: printf ("Attempt to access array element outside its intended bounds!\n");
                                     break;
        }
    }

    printf ("Stack dump:\n");
    printf ("Adress - %lu\n",   (unsigned long) stk.data);
    printf ("Size - %lu\n",     (unsigned long) stk.size);
    printf ("Capacity - %lu\n", (unsigned long) stk.capacity);

    if (stk.data) {
        printf ("Elements:\n");
        for (size_t i = 0; i < stk.capacity; i++) {
            printf ("%d ", stk.data[i]);
            if (i == stk.size - 1)
                printf ("| ");
        }
        printf ("\n");
    }
}

static size_t increase_capacity (size_t current_capacity) {
    return 2 * current_capacity;
}

static size_t decrease_capacity (size_t current_capacity) {
    return current_capacity / 2;
}
