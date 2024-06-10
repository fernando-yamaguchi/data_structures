#include "queue.h"

queue_t *create_queue(void) {
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    if (queue == NULL) {
        return NULL;
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(queue_t *queue, int data) {
    queue_node_t *new_node = (queue_node_t *)malloc(sizeof(queue_node_t));
    if (new_node == NULL) {
        return;
    }
    new_node->data = data;
    new_node->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = new_node;
        return;
    }
    queue->rear->next = new_node;
    queue->rear = new_node;
}

int dequeue(queue_t *queue, int *data) {
    if (is_queue_empty(queue)) {
        return -1;
    }
    queue_node_t *temp_node = queue->front;
    *data = temp_node->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp_node);
    return 0;
}

bool is_queue_empty(const queue_t *queue) {
    return (queue->front == NULL);
}

int peek(const queue_t *queue, int *data) {
    if (queue == NULL || is_queue_empty(queue)) {
        return -1;
    }

    *data = queue->front->data;
    return 0;
}

void free_queue(queue_t *queue) {
    if (queue == NULL) {
        return;
    }

    queue_node_t *current = queue->front;
    queue_node_t *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(queue);
}
