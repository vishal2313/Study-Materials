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

// Function to reverse the linked list
void reverseLinkedList(struct LinkedList* list) {
    struct Node* prev = NULL;
    struct Node* current = list->head;
    struct Node* next = NULL;

    while (current != NULL) {
        // Store the next node
        next = current->next;

        // Reverse the link
        current->next = prev;

        // Move to the next nodes
        prev = current;
        current = next;
    }

    // Update the head pointer to the new first node
    list->head = prev;
}

int main() {
    struct LinkedList myList;
    initializeLinkedList(&myList);

    insertAtEnd(&myList, 10);
    insertAtEnd(&myList, 20);
    insertAtEnd(&myList, 30);
    insertAtEnd(&myList, 40);

    printf("Original ");
    display(&myList);

    // Reverse the linked list
    reverseLinkedList(&myList);

    printf("Reversed ");
    display(&myList);

    return 0;
}
