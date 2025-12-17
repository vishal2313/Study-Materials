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

// Function to reverse K nodes in the linked list
struct Node* reverseKNodes(struct Node* head, int k) {
    struct Node* current = head;
    struct Node* next = NULL;
    struct Node* prev = NULL;
    int count = 0;

    // Count the number of nodes in the current group
    struct Node* temp = head;
    while (temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }

    // If there are at least K nodes, reverse them
    if (count == k) {
        count = 0;
        while (current != NULL && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        // Recursively reverse the next group
        if (next != NULL) {
            head->next = reverseKNodes(next, k);
        }

        // prev is now the new head of the reversed group
        return prev;
    }

    // If there are fewer than K nodes, do not reverse
    return head;
}

int main() {
    struct LinkedList myList;
    initializeLinkedList(&myList);

    // Populate the linked list
    for (int i = 1; i <= 8; i++) {
        insertAtEnd(&myList, i);
    }

    // Display the original linked list
    printf("Original ");
    display(&myList);

    // Reverse every K nodes in the linked list (K = 3)
    myList.head = reverseKNodes(myList.head, 3);

    // Display the reversed linked list
    printf("Reversed ");
    display(&myList);

    return 0;
}
