#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the Stack
struct Stack {
    struct Node* top;
};

// Function to initialize the stack
void initializeStack(struct Stack* stack) {
    stack->top = NULL;
}

// Function to check if the stack is empty
int isStackEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Function to push an element onto the stack
void push(struct Stack* stack, int element) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot push.\n");
        return;
    }

    // Initialize the new node
    newNode->data = element;
    newNode->next = stack->top;

    // Update the top pointer
    stack->top = newNode;

    printf("%d pushed to the stack.\n", element);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return an error value
    }

    // Pop the top element and update the top pointer
    struct Node* temp = stack->top;
    int poppedElement = temp->data;
    stack->top = temp->next;

    free(temp);
    return poppedElement;
}

// Function to peek at the top element of the stack
int peek(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1; // Return an error value
    }

    return stack->top->data;
}

// Function to display the elements in the stack
void display(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* current = stack->top;
    printf("Elements in the stack: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to clear the stack (free all nodes)
void clearStack(struct Stack* stack) {
    while (!isStackEmpty(stack)) {
        pop(stack);
    }
}

int main() {
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

    // Clear the stack
    clearStack(&stack);
    display(&stack);
    return 0;
}
