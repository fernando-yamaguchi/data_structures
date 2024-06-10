#include <stdio.h>
#include "queue.h"

int main() {
    int data;
    queue_t *queue = create_queue();
    if (queue == NULL) {
        printf("Failed to create the queue.\n");
        return 1;
    }

    printf("Enqueue elements 10, 20, and 30.\n");
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    // Test peek functionality
    if (peek(queue, &data) == 0) {
        printf("Peeked at front element: %d\n", data);
    } else {
        printf("Failed to peek at front element.\n");
    }

    // Dequeue all elements and print them
    printf("Dequeueing elements:\n");
    while (!is_queue_empty(queue)) {
        if (dequeue(queue, &data) == 0) {
            printf("%d ", data);
        } else {
            printf("Failed to dequeue an element.\n");
        }
    }
    printf("\n");

    // Try to dequeue from an empty queue to check error handling
    printf("Attempting to dequeue from an empty queue: ");
    if (dequeue(queue, &data) == -1) {
        printf("Passed. Queue is empty as expected.\n");
    } else {
        printf("Failed. Unexpected behavior when dequeuing from an empty queue.\n");
    }

    // Clean up
    free(queue);
    return 0;
}
