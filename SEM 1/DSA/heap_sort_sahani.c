#include <stdio.h>
#include <stdlib.h>

void heapsort(int *, int);    // Funtion prototype for Heap sort
void heapify(int *, int);     // Function prototype for heapify
void adjust(int *, int, int); // Function prototype for adjust which will adjust the heap

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

    heapsort(a, n - 1); // Calling the function for heap sort
    printf("\n\narray after heapsort:\n\n");
    for (int i = 0; i < n; i++)
    { // printing the sorted array

        printf("%d\t", a[i]);
    }
    printf("\n");
    free(a); // Free the input array
    return 0;
}

void heapsort(int *a, int n)
{ // Function definition for heapsort

    heapify(a, n); // Calling the function to build the initial max heap

    for (int i = n; i >= 1; i--)
    { // placing the root value in it's appropriate position
        int t = a[i];
        a[i] = a[0];
        a[0] = t;
        adjust(a, 0, i - 1); // Calling the function to adjust the heap
    }
}

void heapify(int *a, int n)
{ // Function definition to build the heap

    for (int i = n / 2; i >= 0; i--)
    {
        adjust(a, i, n);
    }
}

void adjust(int *a, int i, int n)
{ // Function definition to adjust the heap
    int j = 2 * i;
    int item = a[i];
    while (j <= n)
    {
        if ((j < n) && (a[j] < a[j + 1]))
        { // Compare left and right child and let j be the bigger child
            j = j + 1;
        }
        if (item >= a[j])
        {
            break; // A position for item is found
        }
        a[j / 2] = a[j];
        j = 2 * j;
    }
    a[j / 2] = item;
}