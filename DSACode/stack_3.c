#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure for the stack
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the Stack
struct Stack {
    struct Node* top;
};

// Function to initialize the stack
void initializeStack(struct Stack* stack) {
    stack->top = NULL;
}

// Function to check if the stack is empty
int isStackEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Function to push an element onto the stack
void push(struct Stack* stack, int element) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot push.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the new node
    newNode->data = element;
    newNode->next = stack->top;

    // Update the top pointer
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Error: Stack is empty.\n");
        exit(EXIT_FAILURE);
    }

    // Pop the top element and update the top pointer
    struct Node* temp = stack->top;
    int poppedElement = temp->data;
    stack->top = temp->next;

    free(temp);
    return poppedElement;
}

// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[]) {
    struct Stack stack;
    initializeStack(&stack);

    int i = 0;
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            // If the character is a digit, push it onto the stack
            push(&stack, postfix[i] - '0'); // Convert char to int
        } else {
            // If the character is an operator, pop two operands, perform the operation, and push the result
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (postfix[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0) {
                        push(&stack, operand1 / operand2);
                    } else {
                        printf("Error: Division by zero.\n");
                        exit(EXIT_FAILURE);
                    }
                    break;
                default:
                    printf("Error: Invalid operator.\n");
                    exit(EXIT_FAILURE);
            }
        }

        i++;
    }

    // The final result should be at the top of the stack
    if (!isStackEmpty(&stack)) {
        return pop(&stack);
    } else {
        printf("Error: Postfix expression is invalid.\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    char postfixExpression[100];

    printf("Enter a postfix expression: ");
    fgets(postfixExpression, sizeof(postfixExpression), stdin);

    int result = evaluatePostfix(postfixExpression);

    printf("Result: %d\n", result);

    return 0;
}
