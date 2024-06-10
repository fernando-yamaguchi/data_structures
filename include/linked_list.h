#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node
{
    void *data;
    struct Node *next;
} Node;

Node *create_node(void *data, size_t data_size);
void insert_front(Node **head, void *data, size_t data_size);
void insert_back(Node **head, void *data, size_t data_size);
void display_list(Node *head, void (*print_func)(void *));
void free_list(Node **head);

#endif // LINKED_LIST_H
