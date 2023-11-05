// CODE FOR INSERTION AND CREATION IN A BINARY SEARCH TREE(BST); RUNS SUCCESFULLY!!!!!

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *getnode(int);
void tree(struct node **, int);
void inorder(struct node *);
void preorder(struct node *start);
void postorder(struct node *start);

int main()
{
    struct node *start = NULL;
    int a, n, ch, item;
    printf("\nenter a node to create a BST:\t");
    scanf("%d", &item);
    tree(&start, item);
    printf("\ndo you want to continue:\t");
    scanf("%d", &ch);
    while (ch == 1)
    {
        printf("\nenter a number:\t");
        scanf("%d", &item);
        tree(&start, item);
        printf("\ndo you want to continue:\t");
        scanf("%d", &ch);
    }

    printf("\n\ninorder traversal is :\t\t");
    inorder(start);
    printf("\n\n\n\n\n\n\n\n\n");
    printf("\n\npostorder traversal is :\t\t");
    postorder(start);
    printf("\n\n\n\n\n\n\n\n\n");
    printf("\n\npreorder traversal is :\t\t");
    preorder(start);

    return 0;
}

struct node *getnode(int item)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = item;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void tree(struct node **start, int item)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));

    if (*start == NULL)
    {
        *start = getnode(item);
    }
    else
    {
        p = *start;
        if (item > p->data)
        {
            tree(&p->right, item);
        }
        else
        {
            if (item < p->data)
            {
                tree(&p->left, item);
            }
        }
    }
}

void inorder(struct node *start)
{
    if (start != NULL)
    {

        inorder(start->left);
        printf("\t%d \t", start->data);
        inorder(start->right);
    }
}

void preorder(struct node *start)
{
    if (start == NULL)
    {
        return;
    }
    else
    {
        printf("\t%d\t", start->data);
        preorder(start->left);
        preorder(start->right);
    }
}

void postorder(struct node *start)
{
    if (start == NULL)
    {
        return;
    }
    else
    {
        postorder(start->left);
        postorder(start->right);
        printf("\t%d\t", start->data);
    }
}
