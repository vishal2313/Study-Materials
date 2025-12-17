#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the Linked List
struct LinkedList {
    struct Node* head;
};

// Function to initialize the linked list
void initializeLinkedList(struct LinkedList* list) {
    list->head = NULL;
}

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot create node.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct LinkedList* list, int data) {
    struct Node* newNode = createNode(data);

    if (list->head == NULL) {
        // If the list is empty, set the new node as the head
        list->head = newNode;
    } else {
        // Otherwise, traverse to the end and add the new node
        struct Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to display the elements in the linked list
void display(struct LinkedList* list) {
    struct Node* current = list->head;

    printf("Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to find the minimum value node in the linked list starting from a given node
struct Node* findMinNode(struct Node* start) {
    struct Node* minNode = start;
    struct Node* current = start->next;

    while (current != NULL) {
        if (current->data < minNode->data) {
            minNode = current;
        }
        current = current->next;
    }

    return minNode;
}

// Function to perform selection sort on the linked list
void selectionSort(struct LinkedList* list) {
    struct Node* current = list->head;
    struct Node* sortedList = NULL;
    struct Node* minNode = NULL;
    struct Node* prevMinNode = NULL;

    while (current != NULL) {
        // Find the minimum value node in the remaining unsorted part of the list
        minNode = findMinNode(current);

        // Remove the minimum value node from its current position
        if (prevMinNode != NULL) {
            prevMinNode->next = minNode->next;
        } else {
            current = minNode->next;
        }

        // Add the minimum value node to the sorted part of the list
        minNode->next = sortedList;
        sortedList = minNode;

        // Update the head of the sorted list
        list->head = sortedList;

        // Update the pointer to the last node in the sorted list
        prevMinNode = minNode;
    }
}

int main() {
    struct LinkedList myList;
    initializeLinkedList(&myList);

    // Populate the linked list
    insertAtEnd(&myList, 30);
    insertAtEnd(&myList, 10);
    insertAtEnd(&myList, 50);
    insertAtEnd(&myList, 20);

    // Display the original linked list
    printf("Original ");
    display(&myList);

    // Sort the linked list using selection sort
    selectionSort(&myList);

    // Display the sorted linked list
    printf("Sorted ");
    display(&myList);

    return 0;
}
