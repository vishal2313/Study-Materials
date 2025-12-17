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

// Function to merge two linked lists alternatively
struct LinkedList mergeAlternatively(struct LinkedList* list1, struct LinkedList* list2) {
    struct LinkedList mergedList;
    initializeLinkedList(&mergedList);

    struct Node* current1 = list1->head;
    struct Node* current2 = list2->head;

    while (current1 != NULL || current2 != NULL) {
        if (current1 != NULL) {
            insertAtEnd(&mergedList, current1->data);
            current1 = current1->next;
        }

        if (current2 != NULL) {
            insertAtEnd(&mergedList, current2->data);
            current2 = current2->next;
        }
    }

    return mergedList;
}

int main() {
    struct LinkedList list1, list2, mergedList;
    initializeLinkedList(&list1);
    initializeLinkedList(&list2);

    // Populate the first linked list
    insertAtEnd(&list1, 10);
    insertAtEnd(&list1, 20);
    insertAtEnd(&list1, 30);

    // Populate the second linked list
    insertAtEnd(&list2, 40);
    insertAtEnd(&list2, 50);
    insertAtEnd(&list2, 60);

    // Display the original linked lists
    printf("Original ");
    display(&list1);
    display(&list2);

    // Merge the linked lists alternatively
    mergedList = mergeAlternatively(&list1, &list2);

    // Display the merged linked list
    printf("Merged ");
    display(&mergedList);

    return 0;
}
