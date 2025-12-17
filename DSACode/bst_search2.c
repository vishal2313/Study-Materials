#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n = malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}
 // method1
/* struct node *search(struct node *root, int key)
{
  if (root == NULL)
  {
      return NULL;
  }
  if (key == root->data)
  {
      return root;
  }
  else if (key < root->data)
  {
      return search(root->left, key);
  }
  else
  {
      return search(root->right, key);
  }
}   */

// method2
struct node *searchIter(struct node *root, int key)
{
    while (root != NULL)
    {

        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

int main()
{ 
    /*
    struct node *p = malloc(sizeof(struct node));
    p->data = 2;
    p->left = NULL;
    p->right = NULL;

    struct node *p1 = malloc(sizeof(struct node));
    p1->data = 1;
    p1->left = NULL;
    p1->right = NULL;

    struct node *p2 = malloc(sizeof(struct node));
    p2->data = 4;
    p2->left = NULL;
    p2->right = NULL;

    p->left = p1;
    p->right = p2;

     */
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    /*         5
              / \
             3   6
            / \
           1   4
    */

    struct node *n = searchIter(p, 9);
    if (n != NULL)
    {
        printf("Found: %d", n->data);
    }
    else
    {
        printf("not found");
    }

    return 0;
}






