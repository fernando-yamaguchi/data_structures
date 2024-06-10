#include "stack.h"

my_stack *create_my_stack(void) {
    my_stack *new_stack = (my_stack *)malloc(sizeof(my_stack));
    if (new_stack == NULL) {
        return NULL;
    }
    new_stack->top = NULL;
    return new_stack;
}

void push_my_stack(my_stack *stack, int data) {
    my_stack_node *new_node = (my_stack_node *)malloc(sizeof(my_stack_node));
    if (new_node == NULL) {
        return;
    }
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
}

int pop_my_stack(my_stack *stack) {
    if (is_my_stack_empty(stack)) {
        return -1;
    }
    my_stack_node *top_node = stack->top;
    int data = top_node->data;
    stack->top = top_node->next;
    free(top_node);
    return data;
}

int peek_my_stack(const my_stack *stack) {
    if (is_my_stack_empty(stack)) {
        return -1;
    }
    return stack->top->data;
}

bool is_my_stack_empty(const my_stack *stack) {
    return stack->top == NULL;
}
