#include<stdio.h>
#include<omp.h>

int main(){

	int n=3, a[3][3]={{9, 8, 7}, {3, 3, 6}, {5, 1, 9}};
	int x,y,z;
	#pragma omp parallel sections
	{
		#pragma omp section
		{
			x=a[0][0]*(a[1][1]*a[2][2] - a[1][2]*a[2][1]);
		}
		#pragma omp section
		{
			y=-1 * a[0][1]*(a[1][0]*a[2][2] - a[1][2]*a[2][0]);
		}
		#pragma omp section
		{
			z=a[0][2]*(a[1][0]*a[2][1] - a[1][1]*a[2][0]);
		}
	}
	int d = x+y+z;
	printf("\nDeterminant of the given matrix is = %d\n",d);
	return 0;
}
