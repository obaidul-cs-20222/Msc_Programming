#include<stdio.h>
#include<omp.h>

int main()
{
	int A[10]={1,2,3,4,5,6,7,8,9,10};
	int i,sum=0;
	
	
	#pragma omp parallel for reduction(+:sum)
	
	for(i=0;i<10;i++)
	{
		sum+=A[i];
	}
	
	printf("\n Sum= %d\n", sum);
	
	return 0;
	
}
