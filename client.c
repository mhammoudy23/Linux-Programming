
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>
#include<signal.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{

  int clientSocket; // information about the socket
  pid_t pid = getpid();
  socklen_t addr_size;
  struct sockaddr_in serv_Addr;
  //      address of family. 

  clientSocket = socket(PF_INET, SOCK_STREAM, 0); //
     
  serv_Addr.sin_family = AF_INET;
  //sets the family of address
  serv_Addr.sin_port = htons(7891);
  //assigning the port   
  serv_Addr.sin_addr.s_addr = inet_addr(argv[1]);
  //give the address of where you want to connect to
  
  memset(serv_Addr.sin_zero, '\0', sizeof serv_Addr.sin_zero);  
  
  addr_size = sizeof serv_Addr;
  connect(clientSocket, (struct sockaddr *) &serv_Addr, addr_size);
  //      socket descriptor     address of the server   size of socket address
  printf("Connected\n");

  while(1)
  {
    char buf[1024] = {0}, buf1[10] = {0};
    printf("Enter shell command: ");
    scanf("%s", buf1);
    write(clientSocket,&buf1,13);
    read(clientSocket, buf, 1024);
    printf("%s\n", buf);
  }

  close(clientSocket);
  kill(pid, SIGTERM);

  printf("\nDisconnected\n\n");
  exit(0);
  
  
  return 0;
}
