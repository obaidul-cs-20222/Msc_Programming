#include<stdio.h>
#include<stdlib.h>


void merge_sort(int *,int ,int );
void merge(int *,int ,int ,int );


int main()
{
		int n,i;
		int *a;
		printf("enter the total number of elements: ");
		scanf("%d",&n);
		a=(int*)malloc(n*sizeof(int));
		
		for(i=0;i<n;i++)
		{
		 printf("enter the element number %d: ",i+1);
		 scanf("%d",(a+i));
		}
		merge_sort(a,0,n-1);
		printf("sorted array using merge sort is:\t");
		for(i=0;i<n;i++)
		{
			printf("%d\t",*(a+i));
		}
		printf("\n");
		free(a);
		return 0;
}



void merge_sort(int *a,int lb,int ub)
{
	int mid;
	if(lb<ub)
	{
		mid=(lb+ub)/2;
		merge_sort(a,lb,mid);
		merge_sort(a,mid+1,ub);
		merge(a,lb,mid,ub);
	}


}



void merge(int *a,int lb,int mid,int ub)
{
		int *b,i,j,k;
		b=(int*) malloc((ub+1)*sizeof(int));
		
		for(i=lb;i<=ub;i++)
		{
			*(b+i)=*(a+i);
		}
		
		i=lb;
		j=mid+1;
		k=lb;
		
		while(i<= mid && j<=ub)
		{
			if(*(b+i)<*(b+j))
			{
			   *(a+k)=*(b+j);
			   i++;
			   k++;
			
			}
			else
			{
				*(a+k)=*(b+j);
				j++;
				k++;
			}
		}
		
		while(i<=mid)
		{
			*(a+k)=*(b+i);
			i++;
			k++;
		}
		
		while(j<=ub)
		{
			*(a+k)=*(b+j);
			j++;
			k++;
		}



}
