#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct neighbour *success;
};

struct neighbour
{
    int data;
    struct neighbour *nxt;
};

void createlist(struct node **, int);
void print(struct node *);
struct node *getnode(int);
struct neighbour *getnei(int);

int main()
{
    int item, i, j, n;
    struct node *start = NULL;

    do
    {
        printf("\n enter the node:\t");
        scanf("%d", &item);
        createlist(&start, item);

        printf("\ndo you want to insert another node?[0/1]:\t");
        scanf("%d", &j);

    } while (j == 1);

    print(start);

    return 0;
}

void createlist(struct node **start, int item)
{
    int i, n;
    struct node *p, *q;
    if (*start == NULL)
    {
        *start = getnode(item);
        p = *start;
    }
    else
    {

        p = getnode(item);
        q = *start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
    int ch;

    struct neighbour *y;
    printf("\n does it has any neighbour?[0/1]:\t");
    scanf("%d", &ch);
    while (ch == 1)
    {

        printf("\nenter the value of neighbour:\t");
        scanf("%d", &n);

        y = getnei(n);
        if (p->success == NULL)
        {

            p->success = y;
        }
        else
        {
            struct neighbour *z;
            z = (struct neighbour *)malloc(sizeof(struct neighbour));
            z = p->success;
            while (z->nxt != NULL)
            {
                z = z->nxt;
            }
            z->nxt = y;
        }
        printf("\n does it has any neighbour?[0/1]:\t");
        scanf("%d", &ch);
    }
}

struct node *getnode(int item)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = item;
    p->next = NULL;
    p->success = NULL;

    return p;
}

struct neighbour *getnei(int n)
{
    struct neighbour *x;
    x = (struct neighbour *)malloc(sizeof(struct neighbour));
    x->data = n;
    x->nxt = NULL;
    return x;
}

void print(struct node *start)
{
    struct node *p;
    struct neighbour *q;

    if (start == NULL)
    {
        printf("\n Empty list\n");
    }
    else
    {

        p = start;

        while (p->next != NULL)
        {
            printf("\nthe node is :\t%d\t", p->data);
            if (p->success != NULL)
            {
                printf("\tit's neighbours are:\t");
                q = p->success;
                while (q->nxt != NULL)
                {
                    printf("\t -->\t%d ", q->data);
                    q = q->nxt;
                }
                printf("\t -->\t%d ", q->data);
            }

            p = p->next;
        }
        printf("\nthe node is:\t%d\t", p->data);

        if (p->success != NULL)
        {
            printf("\tit's neighbours are:\t");
            q = p->success;
            while (q->nxt != NULL)
            {
                printf("\t -->\t%d ", q->data);
                q = q->nxt;
            }
            printf("\t -->\t%d ", q->data);
        }
        printf("\n");
    }
}