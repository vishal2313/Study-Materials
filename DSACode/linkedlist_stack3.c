#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int stackBottom(struct stack *sp)
{
    if (isEmpty(sp))
    {

        return -1;
    }
    else

        return sp->arr[0];
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("stack overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("stack underflow\n");
        return -1;
    }

    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *sp, int i)
{
    int arrInd = sp->top - i + 1;
    if (arrInd < 0)
    {
        printf("not a valid position for the stack\n");
        return -1;
    }
    else
    {
        return sp->arr[arrInd];
    }
}

int main()
{
    struct stack *sp = malloc(sizeof(struct stack));
    sp->size = 5;
    sp->top = -1;
    sp->arr = malloc(sp->size * sizeof(int));

    push(sp, 51);
    push(sp, 32);
    push(sp, 43);
    push(sp, 65);
    push(sp, 58);

    printf("the topmost element of the stack is %d\n", stackTop(sp));
    printf("the bottommost element of the stack is %d\n", stackBottom(sp));

    return 0;
}