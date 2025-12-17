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

void del_at_pos(struct node *head, int postition)
{
    struct node *current = head;
    struct node *previous = head;
    if (head == NULL)
    {
        printf("the list is already empty");
    }
    else if (postition == 1)
    {
        head = current->link;
        free(current);
        current = NULL;
    }
    else
    {
        while (postition != 1)
        {
            previous = current;
            current = current->link;
            postition--;
        }
        previous->link = current->link;
        free(current);
        current = NULL;
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

    int position = 3;
    del_at_pos(head, position);

    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}