#include<stdio.h>
#include<omp.h>

int main()
{
	int a[]={3,6,9};
	int b[]={1,5,8};
	int i,s=0,x,y,z;
	
	#pragma omp parallel for reduction(+:s) 
	for(i=0;i<3;i++)
	{
		s+=a[i]*b[i];
	}
	
	printf("Dot product = %d\n",s);
	printf("Vector product = \t");
	#pragma omp parallel sections
	{
		#pragma omp section
		{		
			x=a[1]*b[2]-a[2]*b[1];
		}
		#pragma omp section
		{
			y=a[0]*b[2]-a[2]*b[0];
			
		}
		#pragma omp section
		{
			z=a[0]*b[1]-a[1]*b[0];
		}
	}
	printf("%di\t",x);
	printf("%dj\t",-y);
	printf("%dk\n",z);
	return 0;
}
