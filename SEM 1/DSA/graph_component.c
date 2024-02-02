#include <stdlib.h>
#include <stdio.h>

int bfs(int **, int, int, int *);

int main()
{
    int **a, n, s, d, i, j, bfs_counter = 0;

    do
    {

        printf("enter the no of vertices in the graph: ");
        scanf("%d", &n);
    } while (n <= 0);
    a = (int **)calloc(n, sizeof(int *));
    int *dist = (int *)calloc(n, sizeof(int));
    for (i = 0; i < n; i++)
    {
        a[i] = (int *)calloc(n, sizeof(int));
        dist[i] = -1;
    }
    printf("\nenter the edges:\n");
    do
    {
        printf("\n\tenter the vertex pair for which there is an edge: ");
        scanf("%d%d", &s, &d);
        a[s - 1][d - 1] = 1;
        a[d - 1][s - 1] = 1;
        printf("\n do  you want to enter more no edges:[0/1] ");
        scanf("%d", &s);
    } while (s != 0);
    printf("\nthe input graph is:\n");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
        {
            printf("%d", a[i][j]);
            printf("\t");
        }
    }

    printf("\nplease enter the source node: ");
    scanf("%d", &s);
    s = s - 1;
    int count = bfs(a, n, s, dist);
    bfs_counter++;
    if (count == n)
    {
        printf("\n graph is connected, there is only 1 component in the given graph\n");
        printf("\nthe distance array:\t");
        for (i = 0; i < n; i++)
        {

            printf("\t%d\t", dist[i]);
        }
        printf("\n");
    }
    else
    {
        printf("\n graph is not connected, there is more than 1 component in the given graph\n");
        printf("\nthe distance array:\t");
        for (i = 0; i < n; i++)
        {

            printf("\t%d\t", dist[i]);
        }
        printf("\nDo you want to apply bfs again?[0/1]:\t");
        scanf("%d", &d);
        while (d != 0)
        {
            printf("\nEnter the source vertex:\t");
            scanf("%d", &s);
            bfs(a, n, s - 1, dist);
            bfs_counter++;
            printf("\nthe distance array:\t");
            for (i = 0; i < n; i++)
            {

                printf("\t%d\t", dist[i]);
            }
            printf("\nDo you want to appy bfs again?[0/1]:\t");
            scanf("%d", &d);
        }
    }
    printf("\nNumber of components detected: %d\n", bfs_counter++);

    free(a);
    free(dist);
    return 0;
}

int bfs(int **a, int n, int s, int *d)
{

    int *parent = (int *)calloc(n, sizeof(int));
    int *q = (int *)calloc(n, sizeof(int));

    int i, count = 0, k, u, v, front = -1, rear = -1;

    for (i = 0; i < n; i++)
    {

        parent[i] = -1;
    }
    d[s] = 0;

    q[++rear] = s;

    while (front != rear)
    {
        v = q[++front];

        count++;

        for (u = 0; u < n; u++)
        {
            if (a[v][u] == 1)
            {
                if (d[u] < 0)
                {
                    d[u] = d[v] + 1;
                    parent[u] = v;
                    q[++rear] = u;
                }
            }
        }
    }

    free(q);
    free(parent);
    return count;
}