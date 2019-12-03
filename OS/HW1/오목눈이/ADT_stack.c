#include "ADT_stack.h"

STACK *create_stack()
{
    printf("creating stack...\n");
    STACK *stack = (STACK *)malloc(sizeof(STACK));
    if (!stack)
    {
        return FALSE;
    }
    stack->count = 0;
    stack->top = NULL;
    return stack;
}

int push(STACK *stack, void *in)
{
    printf("pushing a data into stack... \n");
    STACK_NODE *node2 = (STACK_NODE *)malloc(sizeof(STACK_NODE));
    if (!node2)
    {
        return FALSE;
    }
    node2->next = stack->top;
    stack->top = node2;
    node2->data_ptr2 = in;
    (stack->count)++;
    return TRUE;
}

void *pop(STACK *stack)
{
    // STACK_NODE *temp = stack->top;
    void *data_out = stack->top->next->data_ptr2;
    printf("popping a stack... \n");

    if (stack->count == 1)
    {
        printf("there is no stack");
        stack->top = NULL;
        return NULL;
    }
    else
    {
        stack->top = stack->top->next;
        (stack->count)--;
        // free(temp);
        return data_out;
    }

    /*
    stack->top = stack->top->link;
    stack->count--;
    */
}

void *check_stack(STACK *stack)
{
    if ((stack->count) == 1)
        printf("The stack is empty. \n");
    else
    {
        printf("The stack is :\n");
        STACK_NODE *temp = (STACK *)malloc(sizeof(STACK));
        temp = stack->top->next;
        while ((temp) != NULL)
        {
            printf("%s --> ", temp->data_ptr2);
            temp = temp->next;
        }
        printf("NULL\n\n");
        free(temp);
    }
}
