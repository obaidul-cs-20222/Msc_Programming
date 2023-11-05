#include<stdio.h>
#include<omp.h>

int main()
{
	int i,j,k,n;
	
	printf("Please enter the order of square matrices:-\n");
	scanf("%d",&n);
	int a[n][n],b[n][n],c[n][n];
	
	printf("Please enter elements of matrix a:-\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	printf("Please enter elements of matrix b:-\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&b[i][j]);
			c[i][j]=0;
		}
	}
	
	
	omp_set_dynamic(0);
	omp_set_num_threads(n);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			#pragma omp parallel for private(k)
			for(k=0;k<n;k++)
			{
				c[i][k]+=a[i][j]*b[j][k];
			}
		}
	}
	
	printf("Matrix A:-\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	
	
	printf("Matrix B:-\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	
	
	printf("Matrix C:-\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}

	return 0;
}
