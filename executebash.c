#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<stdio.h>

int main()
{

	int x = fork();

	if(x == 0)
	{
		execlp("./mybash.sh", "mybash.sh", "EXAM!",(char *)0);

	}
	else
	{
		sleep(1);
		printf("STUDY! STUDY! STUDY\n");
		exit(1);
	}
	return 0;
}