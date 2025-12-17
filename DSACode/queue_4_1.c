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

// Structure to represent the Queue using two stacks
struct Queue {
    struct Stack stack1; // Used for enqueue
    struct Stack stack2; // Used for dequeue
};

// Function to initialize the queue
void initializeQueue(struct Queue* queue) {
    initializeStack(&queue->stack1);
    initializeStack(&queue->stack2);
}

// Function to enqueue an element to the queue
void enqueue(struct Queue* queue, int element) {
    // Push the element onto stack1
    push(&queue->stack1, element);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isStackEmpty(&queue->stack2)) {
        // If stack2 is empty, transfer elements from stack1 to stack2
        while (!isStackEmpty(&queue->stack1)) {
            push(&queue->stack2, pop(&queue->stack1));
        }
    }

    // Pop the element from stack2 (or return an error value if both stacks are empty)
    return isStackEmpty(&queue->stack2) ? -1 : pop(&queue->stack2);
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
