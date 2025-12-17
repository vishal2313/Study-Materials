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

    printf("%d enqueued to the queue.\n", element);
}

// Function to remove an element from the queue (Dequeue)
void dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    struct Node* temp = queue->front;
    printf("%d dequeued from the queue.\n", temp->data);

    if (queue->front == queue->rear) {
        // If there is only one element, reset both front and rear
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        // Otherwise, move the front pointer to the next node
        queue->front = queue->front->next;
    }

    free(temp);
}

// Function to display the elements in the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* current = queue->front;
    printf("Elements in the queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to get the front element of the queue
int front(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }

    return queue->front->data;
}

// Function to get the rear element of the queue
int rear(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }

    return queue->rear->data;
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    display(&queue);

    printf("Front element: %d\n", front(&queue));
    printf("Rear element: %d\n", rear(&queue));

    dequeue(&queue);
    display(&queue);

    return 0;
}
