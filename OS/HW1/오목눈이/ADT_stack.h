#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1

typedef struct node2
{
    void *data_ptr2;
    struct node2 *next;
} STACK_NODE;

typedef struct stack
{
    int count;
    STACK_NODE *top;
} STACK;

STACK *create_stack();
int push(STACK *stack, void *in);
void *pop(STACK *stack);
void *check_stack(STACK *stack);
