#include <stdio.h>
#include "queue.h"

int main() {
    queue_t *myQueue = create_queue();
    if (myQueue == NULL) {
        fprintf(stderr, "Failed to create queue\n");
        return 1;
    }

    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);

    printf("Successfully enqueued 10, 20, 30\n");

    int dequeuedValue;
    while (!is_queue_empty(myQueue)) {
        if (dequeue(myQueue, &dequeuedValue) != -1) {
            printf("Dequeued: %d\n", dequeuedValue);
        } else {
            fprintf(stderr, "Failed to dequeue\n");
        }
    }

    free(myQueue);
    myQueue = NULL;

    return 0;
}
