#include <stdio.h>
#include <stdlib.h>

// Node structure for the stack
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
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return an error value
    }

    // Pop the top element and update the top pointer
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);

    return data;
}

// Structure to represent the Queue using one stack
struct Queue {
    struct Stack stack;
};

// Function to initialize the queue
void initializeQueue(struct Queue* queue) {
    initializeStack(&queue->stack);
}

// Function to enqueue an element to the queue
void enqueue(struct Queue* queue, int element) {
    // Push the element onto the stack
    push(&queue->stack, element);
}

// Recursive function to dequeue elements and enqueue them again (helper function)
void dequeueAndEnqueueAgain(struct Stack* stack, int element) {
    if (isStackEmpty(stack)) {
        // Base case: if the stack is empty, enqueue the element
        push(stack, element);
        return;
    }

    // Recursive case: dequeue the elements, enqueue them again, and push the current element
    int frontElement = pop(stack);
    dequeueAndEnqueueAgain(stack, element);
    push(stack, frontElement);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isStackEmpty(&queue->stack)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return an error value
    }

    // Dequeue the front element using a recursive helper function
    int frontElement = pop(&queue->stack);
    dequeueAndEnqueueAgain(&queue->stack, frontElement);

    return frontElement;
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));

    enqueue(&queue, 40);
    enqueue(&queue, 50);

    printf("Dequeued element: %d\n", dequeue(&queue));

    return 0;
}
