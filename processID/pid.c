#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include<fcntl.h>

int main(int argc, char *argv[]){

	int pid[7];
	int num[8];

	num[1] = getpid();
	pid[1] =  fork();

	if(pid[1] > 0)
	{
		pid[2] = fork();
		if(pid[2] == 0)
		{
			num[3] = getpid();

			pid[5] = fork();

			if(pid[5] > 0)
			{
				pid[6] = fork();
				if(pid[6] == 0)
				{
					num[7] = getpid();
				}
			}
			else if(pid[5] == 0)
			{
				num[6] = getpid();
			}
		}
	}
	else
	{
		num[2] = getpid();
		pid[3] = fork();

		if(pid[3] > 0)
		{
			pid[4] = fork();
			if(pid[4] == 0)
			{
				num[5] = getpid();
			}
		}
		else if(pid[4] == 0)
		{
			num[4] = getpid();	
		}
	}
	
	for(int i = 1; i <= 7; i++)
	{
		if(getpid() == num[i])
		{
			sleep(atoi(argv[i]));
			printf("process %d terminated. pid=%d\n", i, getpid());
		}
		
	}
	
	exit(0);

	return 0;
	
}
