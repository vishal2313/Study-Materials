#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent the Queue
struct Queue {
    int array[MAX_SIZE];
    int front, rear;
};

// Function to initialize the queue
void initializeQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the queue is full
int isFull(struct Queue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}

// Function to add an element to the queue (Enqueue)
void enqueue(struct Queue *queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear++;
    }

    queue->array[queue->rear] = element;
    printf("%d enqueued to the queue.\n", element);
}

// Function to remove an element from the queue (Dequeue)
void dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    printf("%d dequeued from the queue.\n", queue->array[queue->front]);

    if (queue->front == queue->rear) {
        // Queue has only one element, so reset front and rear
        initializeQueue(queue);
    } else {
        queue->front++;
    }
}

// Function to display the elements in the queue
void display(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Elements in the queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

// Function to get the front element of the queue
int front(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }

    return queue->array[queue->front];
}

// Function to get the rear element of the queue
int rear(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }

    return queue->array[queue->rear];
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
