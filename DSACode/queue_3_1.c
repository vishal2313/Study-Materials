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
void push(struct Queue* q1, struct Queue* q2, int element) {
    // Enqueue the new element to the non-empty queue
    if (!isEmpty(q1)) {
        enqueue(q1, element);
    } else {
        enqueue(q2, element);
    }
}

// Function to pop an element from the stack
int pop(struct Queue* q1, struct Queue* q2) {
    if (isEmpty(q1) && isEmpty(q2)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return an error value
    }

    int poppedElement;

    // Dequeue all elements from the non-empty queue to the other queue
    if (!isEmpty(q1)) {
        while (q1->front->next != NULL) {
            enqueue(q2, dequeue(q1));
        }
        poppedElement = dequeue(q1);
    } else {
        while (q2->front->next != NULL) {
            enqueue(q1, dequeue(q2));
        }
        poppedElement = dequeue(q2);
    }

    return poppedElement;
}

int main() {
    struct Queue queue1, queue2;
    initializeQueue(&queue1);
    initializeQueue(&queue2);

    push(&queue1, &queue2, 10);
    push(&queue1, &queue2, 20);
    push(&queue1, &queue2, 30);

    printf("Popped element: %d\n", pop(&queue1, &queue2));
    printf("Popped element: %d\n", pop(&queue1, &queue2));

    // Remaining elements in the stack after popping
    printf("Remaining elements in the stack:\n");
    while (!isEmpty(&queue1)) {
        printf("%d\n", dequeue(&queue1));
    }

    return 0;
}
