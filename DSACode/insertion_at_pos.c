#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *add_at_beg(struct node *head, int d) //don't call it if using the codes of multiple line comment in main fn
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = d;
    ptr->link = NULL;
    ptr->link = head;
    head = ptr;
    return head;
}

void add_at_pos(struct node *head, int data, int pos)
{
    struct node *ptr = head;
    struct node *ptr2 = (struct node *)malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->link = NULL;
    pos--;
    while (pos != 1)
    {
        ptr = ptr->link;
        pos--;
    }

    ptr2->link = ptr->link;
    ptr->link = ptr2;
}

int main()
{

    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 66;
    head->link = NULL;
    head = add_at_beg(head, 98);
    head = add_at_beg(head, 43);
    head = add_at_beg(head, 32);
    /*
     struct node *head1 = (struct node *)malloc(sizeof(struct node));
     head1->data = 64;
     head1->link = NULL;
     head->link = head1;

     struct node *head2 = (struct node *)malloc(sizeof(struct node));
     head2->data = 36;
     head2->link = NULL;
     head1->link = head2;

     struct node *head3 = (struct node *)malloc(sizeof(struct node));
     head3->data = 23;
     head3->link = NULL;
     head2->link = head3;

   */
    int data = 76, position = 3;
    add_at_pos(head, data, position);
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    return 0;
}