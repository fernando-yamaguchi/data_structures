#include "linked_list.h"

void print_int(void *n) {
    printf("%d -> ", *(int *)n);
}

int main() {
    Node *head = NULL;
    int data[] = {10, 20, 30};

    for (int i = 0; i < 3; i++) {
        insert_front(&head, &data[i], sizeof(int));
    }

    display_list(head, print_int);
    free_list(&head);

    return 0;
}
