// to compile openMP: gcc -fopenmp -o q4 omp_assignment2.c

#include<stdio.h>
#include<omp.h>

int main()
{
		int B[10]={1,2,3,4,5,6,7,8,9,10},i,m;
		int C[10]={20,30,40,50,60,70,80,90,100,200};
		int A[10];
		for(i=0;i<10;i++)
		{
			A[i]=0;
		}
		omp_set_dynamic(0);
		omp_set_num_threads(3);
		#pragma omp parallel for shared(A) shared(B) shared(C) private(i)
		for(i=0;i<10;i++)
		{
			A[i]=B[i]+C[i];
		}
		
		printf("CONTENTS OF ARRAY A:\n");
		for(i=0;i<10;i++)
		{
			printf("\t%d\t",A[i]);
		}
		printf("\n");
		return 0;

}
