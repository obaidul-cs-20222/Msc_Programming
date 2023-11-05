#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
#include<sys/wait.h>

int main()
{
	int a,b,sum=0;
	pid_t p;
	p=fork();
	if(p==0)
	{	
	
	printf("enter a number: ");
	scanf("%d",&a);
	printf("\nenter another number: ");
	scanf("%d",&b);
	printf("\nchild process\n");
		if(a>=b)
		{
			printf("The maximum number is:\t%d\n",a);
		}
		else
			printf("The maximum number is:\t%d\n",b);
	}
	printf("\nparent process\n");
	sum=a+b;
	printf("Result of addition is:\t%d,",sum);
	return 0;
}
