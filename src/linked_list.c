#include "linked_list.h"

Node *create_node(void *data, size_t data_size)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error allocating memory\n");
        return NULL;
    }
    new_node->data = malloc(data_size);
    if (new_node->data == NULL)
    {
        free(new_node);
        fprintf(stderr, "Error allocating memory for data\n");
        return NULL;
    }
    memcpy(new_node->data, data, data_size);
    new_node->next = NULL;
    return new_node;
}

void insert_front(Node **head, void *data, size_t data_size)
{
    Node *new_node = create_node(data, data_size);
    new_node->next = *head;
    *head = new_node;
}

void insert_back(Node **head, void *data, size_t data_size)
{
    Node *new_node = create_node(data, data_size);
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

void display_list(Node *head, void (*print_func)(void *))
{
    Node *current = head;
    while (current != NULL)
    {
        print_func(current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void free_list(Node **head)
{
    Node *current = *head;
    Node *next;
    while (current != NULL)
    {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    *head = NULL;
}