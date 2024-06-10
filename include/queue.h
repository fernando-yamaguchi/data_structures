#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct queue_node_t {
    int data;
    struct queue_node_t *next;
} queue_node_t;

typedef struct queue_t {
    queue_node_t *front;
    queue_node_t *rear;
} queue_t;

queue_t *create_queue(void);
void enqueue(queue_t *queue, int data);
int dequeue(queue_t *queue, int *data);
bool is_queue_empty(const queue_t *queue);
int peek(const queue_t *queue, int *data);
void free_queue(queue_t *queue);

#endif // QUEUE_H
