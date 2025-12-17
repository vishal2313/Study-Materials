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

/*
struct node *del_at_end(struct node *head)
{
    if (head == NULL)
    {
        printf(" the list is already empty");
    }
    else if (head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        struct node *temp2 = head;
        while (temp->link != NULL)
        {
            temp2 = temp;
            temp = temp->link;
        }
        temp2->link = NULL;
        free(temp);
        temp = NULL;
    }
    return head;
}
*/

void del_at_end(struct node *head)
{
    if (head == NULL)
    {
        printf(" the list is already empty");
    }
    else if (head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        while (temp->link->link != NULL)
        {
            temp = temp->link;
        }
        free(temp->link);
        temp->link = NULL;
    }
}

int main()
{

    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 66;
    head->link = NULL;
    head = add_at_beg(head, 98);
    head = add_at_beg(head, 43);
    head = add_at_beg(head, 32);

  //  head= del_at_end(head);
    del_at_end(head);

    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}