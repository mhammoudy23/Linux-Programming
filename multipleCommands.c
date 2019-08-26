#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
	int pid;
	for(int i = 1; i < argc-1; i +=2)
	{
		pid = fork();
		
		if(pid == 0)
		{
			printf("\n\nThe child with PID %d is executing this command\n", getpid());
			
				execlp(argv[i], argv[i], argv[i+1], 0);			
			
			exit(1);
		}
		else
		{
			int returnStatus;
			waitpid(pid, &returnStatus, 0);
		}


	}
			if(pid == 0){
			if(argc %2==0){
			printf("\n\nThe child with PID %d is executing this command\n", getpid());
			
				execlp(argv[argc-2], argv[argc-2], argv[argc-1],(char*) 0);			
			
			exit(1);
		}
		
		else
		{
				execlp(argv[argc-1], argv[argc-1],(char*) 0);			

		}
}
}
