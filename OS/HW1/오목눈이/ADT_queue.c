#include "ADT_queue.h"

QUEUE *create_queue()
{
    printf("creating queue...\n");
    QUEUE *queue = (QUEUE *)malloc(sizeof(QUEUE));
    if (!queue)
    {
        return FALSE;
    }
    queue->count = 0;
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int enqueue(QUEUE *queue, void *in)
{
    printf("pushing a data into queue... \n");
    QUEUE_NODE *node = (QUEUE_NODE *)malloc(sizeof(QUEUE_NODE));
    if (!node)
    {
        return FALSE;
    }
    node->data_ptr = in;
    node->next = NULL;

    if (queue->count == 0)
    {
        queue->front = node;
    }
    else
    {
        queue->rear->next = node;
    }
    (queue->count)++;
    queue->rear = node;

    return TRUE;
}

void *dequeue(QUEUE *queue)
{
    printf("deleteing a queue... \n");

    if (queue->count == 0)
    {
        printf("there is no queue");
        return NULL;
    }
    QUEUE_NODE *deleted_node;
    deleted_node = queue->front;
    void *data = queue->front->data_ptr;
    if (queue->count == 1)
    {
        queue->front = NULL;
        queue->rear = NULL;
    }
    else
    {
        queue->front = queue->front->next;
    }
    (queue->count)--;
    free(deleted_node);
    // free(temp);
    return data;
}

void *check_queue(QUEUE *queue)
{
    if ((queue->count) == 0)
        printf("The queue is empty .\n");
    else
    {
        printf("The queue is :\n");
        QUEUE_NODE *temp = (QUEUE *)malloc(sizeof(QUEUE));
        temp = queue->front;
        while ((temp) != NULL)
        {
            printf(" %s -->", temp->data_ptr);
            temp = temp->next;
        }
        printf("NULL\n\n");
        free(temp);
    }
}
