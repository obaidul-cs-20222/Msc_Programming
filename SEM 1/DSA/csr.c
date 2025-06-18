// RUNS SUCESSFULLY
// program for graph partitioning halfly done also include graph input from a given file
// and graph representation in csr format
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int v_count;
    int e_count;
    int *vptr;
    int *eptr;
} Graph;

int genrand(Graph *, int, int);
Graph *CSR(/*char */);
int genrand(Graph *, int, int);
void print_graph(Graph *);

int main()
{

    Graph *csr;
    char *file_name;

    file_name = "graphfile.txt";
    csr = CSR(file_name);

    int count = 0, p, v, end;

    int **pop;
    printf("\nenter the value of population:\t");
    scanf("%d", &p);
    pop = (int **)calloc(p, sizeof(int *));
    for (int i = 0; i < p; i++)
    {
        pop[i] = (int *)calloc(csr->v_count, sizeof(int));
    }
    srand(time(0));

    printf("\n");

    while (count < p)
    {
        printf("\n");
        for (v = 0; v < csr->v_count; v++)
        {
            end = (v == csr->v_count - 1) ? 2 * csr->e_count : csr->vptr[v + 1];
            pop[count][v] = genrand(csr, csr->vptr[v], end - 1);
        }
        count++;
    }
    printf("\npop matrix:\n");
    for (int i = 0; i < p; i++)
    {
        printf("\n\n");
        for (int j = 0; j < csr->v_count; j++)
        {
            printf("%d\t", pop[i][j]);
        }
    }

    free(csr);
    free(pop);
    return 0;
}

Graph *CSR(/*char *file_name*/)
{
    Graph *csr;
    FILE *fp;

    int left_v, right_v, prev_v = -1;
    int i = 0, j = 0;

    csr = (Graph *)malloc(sizeof(Graph));
    if (csr == NULL)
    {
        printf("\nDynamic memory allocation failed!");
        return NULL;
    }

    // fp = fopen(file_name, "r");
    fp = fopen("graphfile.txt", "r");
    fscanf(fp, "%d\n%d\n", &csr->v_count, &csr->e_count);

    csr->vptr = (int *)calloc(csr->v_count, sizeof(int));
    if (csr->vptr == NULL)
    {
        printf("\nDynamic memory allocation failed!");
        return NULL;
    }
    csr->eptr = (int *)calloc(2 * csr->e_count, sizeof(int));
    if (csr->eptr == NULL)
    {
        printf("\nDynamic memory allocation failed!");
        return NULL;
    }

    while (!feof(fp))
    {
        fscanf(fp, "%d,%d\n", &left_v, &right_v);
        if (left_v != prev_v)
        {
            csr->vptr[left_v] = i;
        }
        csr->eptr[i] = right_v;
        i++;
        prev_v = left_v;
    }
    fclose(fp);
    print_graph(csr);

    return csr;
}

int genrand(Graph *csr, int start, int end)
{
    int x;
    x = (rand() % (end - start + 1)) + start;
    // printf("%d\t", csr->eptr[x]);
    return csr->eptr[x];
}

void print_graph(Graph *csr)
{
    int i = 0;
    printf("\nNumber of vertices: %d\n", csr->v_count);
    printf("\nNumber of edges: %d\n", csr->e_count);
    printf("\nVPTR:\t");
    for (i = 0; i < csr->v_count; i++)
    {
        printf("\t%d", csr->vptr[i]);
    }
    printf("\n\nEPTR:\t");
    for (i = 0; i < 2 * csr->e_count; i++)
    {
        printf("\t%d ", csr->eptr[i]);
    }
}