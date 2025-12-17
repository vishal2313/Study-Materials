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

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct LinkedList* list, int data) {
    struct Node* newNode = createNode(data);

    newNode->next = list->head;
    list->head = newNode;
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

// Function to delete a node with a given data value from the linked list
void deleteNode(struct LinkedList* list, int data) {
    struct Node* current = list->head;
    struct Node* prev = NULL;

    // Traverse the list to find the node with the specified data value
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    // If the node is found, delete it
    if (current != NULL) {
        if (prev == NULL) {
            // If the node is the head, update the head pointer
            list->head = current->next;
        } else {
            // Otherwise, update the next pointer of the previous node
            prev->next = current->next;
        }

        // Free the memory occupied by the deleted node
        free(current);
    } else {
        printf("Node with data %d not found. Cannot delete.\n", data);
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

// Function to clear the linked list (free all nodes)
void clearList(struct LinkedList* list) {
    while (list->head != NULL) {
        struct Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
}

int main() {
    struct LinkedList myList;
    initializeLinkedList(&myList);

    insertAtEnd(&myList, 10);
    insertAtEnd(&myList, 20);
    insertAtBeginning(&myList, 5);
    insertAtEnd(&myList, 30);

    display(&myList);

    deleteNode(&myList, 20);

    display(&myList);

    // Clear the linked list
    clearList(&myList);

    return 0;
}
