#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void add_at_end(struct node *head, int data)
{
    struct node *ptr;
    ptr = head;
    struct node *temp = malloc(sizeof(struct node));
    temp->data = 87;
    temp->link = NULL;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}

int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *sec = malloc(sizeof(struct node));
    sec->data = 98;
    sec->link = NULL;
    head->link = sec;

    struct node *third = malloc(sizeof(struct node));
    third->data = 12;
    third->link = NULL;
    sec->link = third;

    add_at_end(head, 87);
}