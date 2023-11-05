#include<stdio.h>
#include<omp.h>

int main()
{

	int f,i,n;
	printf("Enter the value for n: ");
	scanf("%d",&n);
	f=1;
	omp_set_dynamic(0);
	omp_set_num_threads(4);
	
	#pragma omp parallel for reduction(*:f)
	
	for(i=1;i<=n;i++)
	{
		f*=i;
	}
	
	printf("\n Factorial= %d\n",f);
	
	return 0;
	
}
