#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
 char* args[]={"ps","-e",NULL};
 pid_t p;
 printf("parent\n");
 p=fork();
 
 if(p==0)
 {
 	printf("child");
 	int n=execv("/bin/ps",args);
 	if(n==-1)
 	{
 		perror("error");
 		return 0;
 	}
 }
wait(0);
return 0;
}
