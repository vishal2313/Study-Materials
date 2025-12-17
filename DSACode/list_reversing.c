#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *add_at_beg(struct node *head, int d)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = d;
    ptr->link = NULL;
    ptr->link = head;
    head = ptr;
    return head;
}

struct node *reverse_list(struct node *head)
{

    struct node *prev = NULL;
    struct node *next = NULL;
    while (head != NULL)
    {
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
}

int main()
{

    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 66;
    head->link = NULL;
    head = add_at_beg(head, 98);
    head = add_at_beg(head, 43);
    head = add_at_beg(head, 32);

    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    head = reverse_list(head);
    printf("\n");
    
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    return 0;
}