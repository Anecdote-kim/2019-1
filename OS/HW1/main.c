#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ADT_queue.h"
#include "ADT_stack.h"
#define SIZE 20
void instructions();
STACK *stack;

void main()
{
    stack = create_stack();
    QUEUE *queue = create_queue();

    int choice;
    char *d_numbers;
    char numbers[SIZE];
    char data[SIZE];
    char *temp;
    char *temp2;

    while (TRUE)
    {

        instructions();
        printf("? ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the numbers: ");
            fflush(stdin);
            gets(numbers);

            d_numbers = strtok(numbers, " ");
            while (d_numbers != NULL)
            {
                printf("%s ", d_numbers);
                push(stack, d_numbers);
                printf("%s ", d_numbers);
                enqueue(queue, d_numbers);
                d_numbers = strtok(NULL, " ");
            }
            push(stack, d_numbers);
            check_stack(stack);
            check_queue(queue);
            break;

        case 2:
            fflush(stdin);
            temp = pop(stack);
            temp2 = dequeue(queue);
            printf("The popped value is %s \n", temp);
            printf("The dequeued value is %s \n", temp2);
            check_stack(stack);
            check_queue(queue);
            free(temp);
            free(temp2);
            break;

        default:
            printf("Invalid choice.\n\n");
            return 0;
        }
        fflush(stdin);
    }
}

void instructions()
{
    printf("Enter your choice:\n"
           "   1 to add an items to the queue,stack \n"
           "   2 to remove an item from the queue,stack \n"
           "   3 to end \n");
}
