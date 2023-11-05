#include<stdio.h>
#include<omp.h>

int main()
{
	int i,n,sum=0;
	int k;
	
	printf("Enter the value for n: ");
	scanf("%d",&n);
	
	#pragma omp parallel for reduction(+:sum)
	
	for(i=1;i<=n;i++)
	{
		k=i*(i+1);
		sum=sum+k;
	}
	
	printf("\n Sum= %d\n", sum);
	
	return 0;
	
}
