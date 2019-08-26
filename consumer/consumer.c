
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


int main()  {
	FILE *fd;

		fd = fopen("storage","rw+");	//open file
		char buf[2];
		int sub, pid;
		fscanf(fd, "%s",buf);// read, store in buf
		int num = atoi(buf);//convert to int
		sub = num - 3;//take value subtract by 3
		
		printf("from consumer: current total is %d \n", sub);
		
		fseek(fd, 0, SEEK_SET);	//point to beginning
		fprintf(fd,"%d",sub); //write new value in storage
		pid = fork();
		
		if(pid == 0){
			execlp("./producer.sh","producer", NULL);	//execute

		}
		fclose(fd);
		
		return 0;
}
