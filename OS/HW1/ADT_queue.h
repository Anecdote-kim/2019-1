#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1

typedef struct node
{
    void *data_ptr;
    struct node *next;
} QUEUE_NODE;

typedef struct queue
{
    int count;
    QUEUE_NODE *front;
    QUEUE_NODE *rear;
} QUEUE;

QUEUE *create_queue();
int enqueue(QUEUE *queue, void *in);
void *dequeue(QUEUE *queue);
void *check_queue(QUEUE *queue);
