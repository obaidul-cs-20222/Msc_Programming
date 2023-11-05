#include <stdio.h>
#include <stdlib.h>

void merge(int *, int, int, int);
void merge_sort(int *, int, int);

int main()
{
	int n, i;
	int *a;
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

	printf("\napplying merge sort\n");
	merge_sort(a, 0, n - 1);

	for (i = 0; i < n; i++)
	{
		printf("\t%d\t", *(a + i));
	}

	printf("\n");
	free(a);
	return 0;
}

void merge(int *a, int lb, int ub, int mid)
{
	int *b;
	b = (int *)calloc(ub + 1, sizeof(int));
	int i, j, k;
	i = lb;
	j = mid + 1;
	k = lb;

	while (i <= mid && j <= ub)
	{
		if (a[i] > a[j])
		{
			b[k] = a[j];
			j++;
			k++;
		}

		if (a[i] < a[j])
		{
			b[k] = a[i];
			i++;
			k++;
		}
	}

	while (i <= mid)
	{
		b[k] = a[i];
		i++;
		k++;
	}
	while (j <= ub)
	{
		b[k] = a[j];
		j++;
		k++;
	}

	for (i = lb; i <= ub; i++)
	{
		a[i] = b[i];
	}
}

void merge_sort(int *a, int lb, int ub)
{
	int mid;
	if (lb < ub)
	{
		mid = (lb + ub) / 2;
		merge_sort(a, lb, mid);
		merge_sort(a, mid + 1, ub);
		merge(a, lb, ub, mid);
	}
}