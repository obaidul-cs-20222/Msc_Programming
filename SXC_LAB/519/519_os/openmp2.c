#include<stdio.h>
#include<omp.h>

int main()
{
	int m,k;
	omp_set_dynamic(0);
		
	#pragma omp parallel num_threads(6)


	printf("\n HELLO %d of %d \n",omp_get_thread_num(),omp_get_num_threads());

	return 0;
}
