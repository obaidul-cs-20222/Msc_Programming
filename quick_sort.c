#include <stdio.h>
#include <stdlib.h>
int partition(int *a, int, int);
void quicksort(int *a, int, int);
// void swap(int*,int*);

int main()
{

	int n, i, *a, ch;
	do
	{
		printf("\nEnter the no. of value:");
		scanf("%d", &n);
		if (n <= 0)
		{
			printf("Please enter a positive value");
		}

	} while (n <= 0);

	a = (int *)malloc(n * sizeof(int));
	printf("Enter the elements:\t");
	for (i = 0; i < n; i++)
	{

		// printf("Enter the element no %d \t:",i+1);
		scanf("%d", a + i);
	}
	quicksort(a, 0, n - 1);
	printf("\nThe sorted array using quick sort  is  :\n");
	for (i = 0; i < n; i++)
	{
		printf("\t%d  ", *(a + i));
		printf("\t");
	}
	free(a);
	return 0;
}

void quicksort(int *a, int lb, int ub)
{
	int j;
	if (lb >= ub)
		return;

	else
	{
		j = partition(a, lb, ub);
		quicksort(a, lb, j - 1);
		quicksort(a, j + 1, ub);
	}
}

int partition(int *a, int lb, int ub)
{
	printf("\nnew call\n\n");
	int pivot;
	pivot = a[lb];
	int down = lb;
	int up = ub;
	while (down < up)
	{
		while (a[down] <= pivot && down < up)

			down = down + 1;
		while (a[up] > pivot)
			up = up - 1;
		if (down < up)
		{

			// swap(&a[down],&a[up]);
			int t;
			t = a[down];
			a[down] = a[up];
			a[up] = t;
		}
	}

	a[lb] = a[up];
	a[up] = pivot;

	printf("\n\t\t pivot element is:\t\t%d\n\n", pivot);
	printf("\nin progress array:\n");
	for (int i = 0; i < 7; i++)
	{
		printf("\t%d  ", *(a + i));
		printf("\t");
	}
	printf("\n\n\n");
	for (int i = 0; i < up; i++)
	{
		printf("\t%d  ", *(a + i));
		printf("\t");
	}
	return up;
}
