#include <stdio.h>
#include <stdlib.h>

void max_min(int *, int, int, int *, int *);

int main()
{
    int *a, n, i;
    int max, min;
    printf("How many elements are to be inserted?  ");
    scanf("%d", &n);
    a = (int *)calloc(n, sizeof(int));
    for (i = 0; i < n; i++)
    {
        printf("\n enter element no%d:  ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("\n input array: \n");
    for (i = 0; i < n; i++)
    {
        printf("\t%d\t", *(a + i));
    }
    max_min(a, 0, n - 1, &max, &min);
    printf("\n max is: %d\n", max);
    printf("\n min is: %d\n", min);
    printf("\n");
    return 0;
}

void max_min(int *a, int i, int j, int *max, int *min)
{
    if (i == j)
    {
        *max = *min = a[i];
    }
    else if (i == j - 1)
    {
        if (a[i] < a[j])
        {
            *max = a[j];
            *min = a[i];
        }
        else
        {
            *max = a[i];
            *min = a[j];
        }
    }
    else
    {
        int mid;
        mid = (i + j) / 2;
        int max1, min1, max2, min2;
        max_min(a, i, mid, &max1, &min1);
        max_min(a, mid + 1, j, &max2, &min2);
        if (max1 < max2)
        {
            *max = max2;
        }
        else if (max1 > max2)
        {
            *max = max1;
        }
        if (min1 < min2)
        {
            *min = min1;
        }
        else if (min1 > min2)
        {
            *min = min2;
        }
    }
}