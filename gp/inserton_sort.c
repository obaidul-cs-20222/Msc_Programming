#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *, int);

int main()
{
    int *a, n;
    printf("Enter the number of elements:\t ");
    scanf("%d", &n);
    a = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter a element:\t");
        scanf("%d", &a[i]);
    }
    printf("Input array: ");
    for (int i = 0; i < n; i++)
    {
        printf("\t%d\t", a[i]);
    }
    insertion_sort(a, n);
    printf("\n\n\nOutput sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("\t%d\t", a[i]);
    }
    free(a);
    return 0;
}

void insertion_sort(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}