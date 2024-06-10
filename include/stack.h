#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct my_stack_node {
    int data;
    struct my_stack_node *next;
} my_stack_node;

typedef struct my_stack {
    my_stack_node *top;
} my_stack;

my_stack *create_my_stack(void);
void push_my_stack(my_stack *stack, int data);
int pop_my_stack(my_stack *stack);
int peek_my_stack(const my_stack *stack);
bool is_my_stack_empty(const my_stack *stack);

#endif // STACK_H
