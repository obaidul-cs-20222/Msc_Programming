#include <stdio.h>
#include <stdlib.h>

void adjacency_matrix();
void incident_matrix();

int main()
{
    int d;
    do
    {
        printf("\n\n\n\t1.Adjacency Matrix");
        printf("\n\t2.Incident Matrix");
        printf("\n\t3.EXIT");
        printf("\n\tenter your choice: ");
        scanf("%d", &d);

        switch (d)
        {
        case 1:
            printf("\nAdjacency Matrix representation: \n");
            adjacency_matrix();
            break;

        case 2:
            printf("\nIncident Matrix representation: \n");
            incident_matrix();
            break;

        case 3:
            break;

        default:
            printf("\nenter valid choice: ");
            break;
        }

    } while (d != 3);

    return 0;
}

void adjacency_matrix()
{
    int **a, i, j, s, d, n;
    do
    {

        printf("enter the no of vertices in the graph: ");
        scanf("%d", &n);
    } while (n <= 0);
    a = (int **)calloc(n, sizeof(int *));
    for (i = 0; i < n; i++)
    {
        a[i] = (int *)calloc(n, sizeof(int));
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
    printf("\nthe input graph in adjacency matrix representation is:\n");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
        {
            printf("%d", a[i][j]);
            printf("\t");
        }
    }

    free(a);
}

void incident_matrix()
{
    int **a, i, j, e, n, s, d;

    do
    {
        printf("\nEnter the number of vertices:\t");
        scanf("%d", &n);
        printf("\nEnter the number of edges:\t");
        scanf("%d", &e);
    } while (n <= 0 || e < 0);

    a = (int **)calloc(n, sizeof(int *));
    for (i = 0; i < n; i++)
    {
        a[i] = (int *)calloc(e, sizeof(int));
    }

    for (i = 0; i < e; i++)
    {
        printf("\nEnter the source and destination for edge %d :\t", i + 1);
        scanf("%d%d", &s, &d);
        a[s - 1][i] = -1;
        a[d - 1][i] = 1;
    }
    printf("\nThe input graph in incident matrix representation is:\n");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < e; j++)
        {
            printf("%d", a[i][j]);
            printf("\t");
        }
    }

    free(a);
}