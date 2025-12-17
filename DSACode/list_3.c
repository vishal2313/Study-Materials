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

// Function to detect and find the starting node of a loop in the linked list
struct Node* detectLoop(struct LinkedList* list) {
    struct Node* slow = list->head;
    struct Node* fast = list->head;

    // Move slow by one step and fast by two steps
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // If there is a loop, move slow to the head and start moving both slow and fast by one step until they meet
        if (slow == fast) {
            slow = list->head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            // Return the starting node of the loop
            return slow;
        }
    }

    // If no loop is found, return NULL
    return NULL;
}

int main() {
    struct LinkedList myList;
    initializeLinkedList(&myList);

    insertAtEnd(&myList, 10);
    insertAtEnd(&myList, 20);
    insertAtEnd(&myList, 30);
    insertAtEnd(&myList, 40);

    // Create a loop for demonstration (connecting the last node to the second node)
    myList.head->next->next->next->next = myList.head->next;

    struct Node* startingNode = detectLoop(&myList);

    if (startingNode != NULL) {
        printf("Loop detected. Starting node of the loop: %d\n", startingNode->data);
    } else {
        printf("No loop detected in the linked list.\n");
    }

    return 0;
}
