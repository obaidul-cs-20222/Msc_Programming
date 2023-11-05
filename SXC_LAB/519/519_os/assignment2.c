#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
   char filename[]= "sample.txt";
   int fd=open(filename,O_CREAT|O_WRONLY|O_TRUNC,0666);
   
   if(fd==-1)
   {
   	perror("error");
   	return 0;
   }
   char buff[100];
   printf("enter a message: \n");
   while(fgets(buff,sizeof(buff), stdin)!=NULL)
   {
   	if(write(fd,buff,strlen(buff))==-1)
   	{
   			perror("error");
   			close(fd);
   			return 0;
   	
   	}
   
   }
   
   
   close(fd);
   pid_t p=fork();
   
   if(p==0)
   {
   	printf("\nchild process\n");
   	struct stat finfo;
   	if(stat(filename,&finfo))
   	{
   		perror("error");
   		return 0;
   	}
   	printf(" %s size=\t%d\n",filename,finfo.st_size);
   	
   }
   wait(0);
   return 0;
   
   
   
}


















