#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure for the stack
struct Node {
    char data;
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

// Function to push a character onto the stack
void push(struct Stack* stack, char element) {
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

// Function to pop a character from the stack
char pop(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Error: Stack is empty.\n");
        exit(EXIT_FAILURE);
    }

    // Pop the top element and update the top pointer
    struct Node* temp = stack->top;
    char poppedElement = temp->data;
    stack->top = temp->next;

    free(temp);
    return poppedElement;
}

// Function to get the precedence of an operator
int getPrecedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    initializeStack(&stack);

    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            // If the character is an operand, add it to the postfix expression
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            // If the character is an opening parenthesis, push it onto the stack
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            // If the character is a closing parenthesis, pop and add operators to the postfix expression until an opening parenthesis is encountered
            while (!isStackEmpty(&stack) && stack.top->data != '(') {
                postfix[j++] = pop(&stack);
            }
            // Pop the opening parenthesis
            pop(&stack);
        } else {
            // If the character is an operator, pop and add operators from the stack to the postfix expression until a lower precedence operator or an opening parenthesis is encountered, then push the current operator onto the stack
            while (!isStackEmpty(&stack) && getPrecedence(stack.top->data) >= getPrecedence(infix[i])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }

        i++;
    }

    // Pop and add remaining operators from the stack to the postfix expression
    while (!isStackEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    // Null-terminate the postfix expression
    postfix[j] = '\0';
}

int main() {
    char infixExpression[100];
    char postfixExpression[100];

    printf("Enter an infix expression: ");
    fgets(infixExpression, sizeof(infixExpression), stdin);

    infixToPostfix(infixExpression, postfixExpression);

    printf("Postfix expression: %s\n", postfixExpression);

    return 0;
}
