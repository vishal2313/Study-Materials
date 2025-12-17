#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the Queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize the queue
void initializeQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL && queue->rear == NULL);
}

// Function to add an element to the queue (Enqueue)
void enqueue(struct Queue* queue, int element) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot enqueue.\n");
        return;
    }

    newNode->data = element;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        // If the queue is empty, set both front and rear to the new node
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        // Otherwise, add the new node to the rear and update the rear pointer
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to remove an element from the queue (Dequeue)
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return an error value
    }

    struct Node* temp = queue->front;
    int data = temp->data;

    if (queue->front == queue->rear) {
        // If there is only one element, reset both front and rear
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        // Otherwise, move the front pointer to the next node
        queue->front = queue->front->next;
    }

    free(temp);
    return data;
}

// Function to push an element onto the stack
void push(struct Queue* queue, int element) {
    // Enqueue the new element to the queue
    enqueue(queue, element);

    // Dequeue and enqueue all elements except the recently added one
    int size = 1; // Number of elements in the queue
    while (size > 1) {
        int frontElement = dequeue(queue);
        enqueue(queue, frontElement);
        size--;
    }
}

// Function to pop an element from the stack
int pop(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return an error value
    }

    // Dequeue and return the front element of the queue
    return dequeue(queue);
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    push(&queue, 10);
    push(&queue, 20);
    push(&queue, 30);

    printf("Popped element: %d\n", pop(&queue));
    printf("Popped element: %d\n", pop(&queue));

    return 0;
}
