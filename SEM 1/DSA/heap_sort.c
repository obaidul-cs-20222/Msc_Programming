#include <stdio.h>
#include <stdlib.h>

void heapsort(int *, int); // Funtion prototype for Heap sort

int main()
{
    int *a, n;
    do
    {
        printf("How many elements to be inserted?:  ");
        scanf("%d", &n);
        if (n <= 0)
        {
            printf("\nEnter a valid number!!!..\n");
        }

    } while (n <= 0);

    // Dynamic memory allocation for input array
    a = (int *)calloc(n, sizeof(int));
    printf("Enter the elements:\t");
    for (int i = 0; i < n; i++)
    {

        scanf("%d", &a[i]);
    }

    heapsort(a, n); // Calling the function for heap sort
    printf("\n\narray after heapsort:\n\n");
    for (int i = 0; i < n; i++)
    { // printing the sorted array

        printf("\n%d\t%d", i + 1, a[i]);
    }
    printf("\n");
    free(a); // Free the input array
    return 0;
}

// Function definition for heap sort
void heapsort(int *a, int n)
{
    int i, elt, s, f, ivalue;

    // Building the initial max heap
    for (i = 1; i < n; i++)
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

    // Adjusting the heap to maintain the max heap property
    // as well as putting the root value in its appropriate position in the array
    for (i = n - 1; i > 0; i--)
    {
        ivalue = a[i];
        a[i] = a[0];
        f = 0;
        if (i == 1)
        {
            s = -1;
        }
        else
        {
            s = 1;
        }
        if (i > 2 && a[2] > a[1])
        {
            s = 2;
        }
        while (s >= 0 && ivalue < a[s])
        {
            a[f] = a[s];
            f = s;
            s = 2 * f + 1;
            if (s + 1 <= i - 1 && a[s] < a[s + 1])
            {
                s = s + 1;
            }
            if (s > i - 1)
            {
                s = -1;
            }
        }
        a[f] = ivalue;
    }
}