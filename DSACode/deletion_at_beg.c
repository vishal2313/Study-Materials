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

struct node *del_at_beg(struct node *head)
{
    if (head == NULL)
    {
        printf(" the list is already empty");
    }
    else
    {
        struct node *temp = head;
        head = head->link;
        free(temp);
        temp=NULL;
    }
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

    head = del_at_beg(head);
    /*
    struct node *temp = head;
    head = head->link;
    free(temp);

    */

    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}