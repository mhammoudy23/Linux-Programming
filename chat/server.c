

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>
#include<signal.h>

int main(int argc, char *argv[])
{
	
		pid_t pid = getpid();
		int sockfd, newsockfd;
		struct sockaddr_in serv_Addr;
		struct sockaddr_storage serv_Storage;
		socklen_t addr_size;

		sockfd = socket(PF_INET, SOCK_STREAM, 0);
		  
		serv_Addr.sin_family = AF_INET; 
		serv_Addr.sin_port = htons(7891);
		serv_Addr.sin_addr.s_addr = INADDR_ANY;
		memset(serv_Addr.sin_zero, '\0', sizeof serv_Addr.sin_zero);  
		bind(sockfd, (struct sockaddr *) &serv_Addr, sizeof(serv_Addr));

		while(1)
		{
			if(listen(sockfd,5) == 0)
		    	printf("Waiting for connection\n");
			else
			    printf("Error\n");

		
			addr_size = sizeof serv_Storage;
			newsockfd = accept(sockfd, (struct sockaddr *) &serv_Storage, &addr_size);
			// 
			printf("Connected\n");
			while(1)
			{
				char buf1[1024] = {0};
			  	read(newsockfd, buf1, 1024); 
			  	printf("Received command: %s\n", buf1);

			  	if(fork() == 0)
			  	{
			  		dup2(newsockfd, 1); 
					execlp(buf1, buf1, NULL);
			  	}
			}
		}
		
		close(newsockfd);
		kill(pid, SIGTERM);
		printf("\nClient left\n\n");

	
  
  return 0;
}
