#include <stdio.h>
#include <stdlib.h>
int main()
{
    int **a, *arr, n, s, d, i, j, bfs_counter = 0;
    int key;
    do
    {

        printf("enter the no of vertices in the graph: ");
        scanf("%d", &n);
    } while (n <= 0);
    a = (int **)calloc(n, sizeof(int *));
    arr = (int *)calloc(n, sizeof(int));
    for (i = 0; i < n; i++)
    {
        a[i] = (int *)calloc(n, sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        printf("\nenter the elements:\t");
        scanf("%d", &key);
        a[i] = key;
    }
    dag(a, arr, n);
}

int dag(int **a, int *arr, int n)
{
    int i, j;
    for (int i = 1, j = i - 1; i < n; i++)
    {
        if (j < i)
        {
            a[j][i] = 1;
        }
    }
}