#include <stdio.h>
#include <stdlib.h>

void max_heap(int *, int);
void min_heap(int *, int);

int main()
{
    int *a, n;
    printf("\nEnter the number of elememts:\t");
    scanf("%d", &n);
    a = (int *)calloc(n, sizeof(int));
    printf("\nEnter the elements:\t");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    max_heap(a, n);

    printf("Max Heap:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\t%d\t", a[i]);
    }

    min_heap(a, n);

    printf("\nMin Heap:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\t%d\t", a[i]);
    }
    free(a);
}

void max_heap(int *a, int n)
{
    int elt, s, f;
    for (int i = 1; i < n; i++)
    {
        elt = a[i];
        s = i;
        f = (s - 1) / 2;
        while (s > 0 && a[f] < elt)
        {
            a[s] = a[f];
            s = f;
            f = (s - 1) / 2;
        }
        a[s] = elt;
    }
}

void min_heap(int *a, int n)
{
    int elt, s, f;
    for (int i = 1; i < n; i++)
    {
        elt = a[i];
        s = i;
        f = (s - 1) / 2;
        while (s > 0 && a[f] > elt)
        {
            a[s] = a[f];
            s = f;
            f = (s - 1) / 2;
        }
        a[s] = elt;
    }
}