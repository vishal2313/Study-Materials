#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent the Stack
struct Stack
{
    int array[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initializeStack(struct Stack *stack)
{
    stack->top = -1;
}

// Function to check if the stack is empty
int isStackEmpty(struct Stack *stack)
{
    return (stack->top == -1);
}

// Function to check if the stack is full
int isStackFull(struct Stack *stack)
{
    return (stack->top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(struct Stack *stack, int element)
{
    if (isStackFull(stack))
    {
        printf("Stack is full. Cannot push.\n");
        return;
    }

    stack->top++;
    stack->array[stack->top] = element;
    printf("%d pushed to the stack.\n", element);
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (isStackEmpty(stack))
    {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return an error value
    }

    int poppedElement = stack->array[stack->top];
    stack->top--;
    return poppedElement;
}

// Function to peek at the top element of the stack
int peek(struct Stack *stack)
{
    if (isStackEmpty(stack))
    {
        printf("Stack is empty. Cannot peek.\n");
        return -1; // Return an error value
    }

    return stack->array[stack->top];
}

// Function to display the elements in the stack
void display(struct Stack *stack)
{
    if (isStackEmpty(stack))
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Elements in the stack: ");
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

int main()
{
    struct Stack stack;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    printf("Peeked element: %d\n", peek(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    display(&stack);

    return 0;
}
