#include <stdio.h>
#include <stdlib.h>

// function prototypes

struct node *getnode(int);
struct node *insert(struct node *, struct node *, int *);
struct node *rotateleft(struct node *);
struct node *rotateright(struct node *);
struct node *rightbalance(struct node *, int *);
struct node *leftbalance(struct node *, int *);
void inorder(struct node *);

typedef struct node // defining the node structure
{
    int data;
    struct node *left;
    struct node *right;
    int bf;
} node;

int main()
{
    node *root = NULL;
    int tall = 0;
    int n, item;

    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &item);
        node *newnode = getnode(item);
        root = insert(root, newnode, &tall);
    }

    printf("\nInorder traversal of the AVL tree: \n"); // inorder traversal of the tree
    inorder(root);
    printf("\n");
}
struct node *getnode(int item) // initializing a node
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = item;
    p->left = NULL;
    p->right = NULL;
    p->bf = 999;
    return p;
}

struct node *insert(node *root, node *new, int *tall)
{
    if (root == NULL)
    {
        root = new;
        root->bf = 0;
        root->left = root->right = NULL;
        *tall = 1;
    }
    else if (new->data == root->data)
    {
        printf("\n Duplicate element in AVL tree\n");
    }
    else if (new->data < root->data)
    {
        root->left = insert(root->left, new, tall);
        if (*tall == 1)
        {
            switch (root->bf)
            {
            case 1:
                root = leftbalance(root, tall);
                break;
            case 0:
                root->bf = 1;
                break;
            case -1:
                root->bf = 0;
                *tall = 0;
                break;
            }
        }
    }

    else
    {
        root->right = insert(root->right, new, tall);
        if (*tall == 1)
        {
            switch (root->bf)
            {
            case 1:
                root->bf = 0;
                *tall = 0;
                break;
            case 0:
                root->bf = -1;
                break;
            case -1:
                root = rightbalance(root, tall);
                break;
            }
        }
    }

    return root;
}

struct node *rotateleft(node *p) // function definition for left rotation
{
    node *temp;
    if (p == NULL)
    {
        printf("\n cannot rotate empty tree\n");
    }
    else if (p->right == NULL)
    {
        printf("\n can not rotate left");
    }
    else
    {
        temp = p->right;
        p->right = temp->left;
        temp->left = p;
    }
    return temp;
}

struct node *rotateright(node *p) // function definition for right rotation
{
    node *temp;
    if (p == NULL)
    {
        printf("\n cannot rotate empty tree\n");
        return p;
    }
    else if (p->left == NULL)
    {
        printf("\n can not rotate right");
        return p;
    }
    else
    {
        temp = p->left;
        p->left = temp->right;
        temp->right = p;
    }
    return temp;
}

struct node *rightbalance(node *root, int *tall)
{
    node *rs = root->right;
    node *ls;
    switch (rs->bf)
    {
    case -1:
        root->bf = rs->bf = 0;
        root = rotateleft(root);
        *tall = 0;
        break;

    case 0:
        printf("\ntree already balanced\n");
        break;
    case 1:
        ls = rs->left;
        switch (ls->bf)
        {
        case -1:
            root->bf = 1;
            rs->bf = 0;
            break;

        case 0:
            root->bf = rs->bf = 0;
            break;
        case 1:
            root->bf = 0;
            rs->bf = -1;
            break;
        }

        ls->bf = 0;
        root->right = rotateright(rs);
        root = rotateleft(root);
        *tall = 0;
    }
    return root;
}

struct node *leftbalance(node *root, int *tall)
{
    node *ls = root->left;
    node *rs;
    switch (ls->bf)
    {
    case 1:
        root->bf = ls->bf = 0;
        root = rotateright(root);
        *tall = 0;
        break;

    case 0:
        printf("\ntree already balanced\n");
        break;
    case -1:
        rs = ls->right;
        switch (rs->bf)
        {
        case 1:
            root->bf = -1;
            ls->bf = 0;
            break;

        case 0:
            root->bf = ls->bf = 0;
            break;
        case -1:
            root->bf = 0;
            ls->bf = 1;
            break;
        }

        rs->bf = 0;
        root->left = rotateleft(ls);
        root = rotateright(root);
        *tall = 0;
    }
    return root;
}

void inorder(node *start)
{
    if (start != NULL)
    {

        inorder(start->left);
        printf("%d \t", start->data);
        inorder(start->right);
    }
}

// sample tree input: 5 6 7 8 4 2 10 3 1 9
// inorder traversal should be in sorted order for this sample input