
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/wait.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
	int fd1 = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0755);
	int num[18], space = 1;

	num[0]='P';
	num[1] = '6';
    num[2] = '\n';
    num[3] = '1';
    num[4] = '0';
    num[5] = '0';
    num[6] = '0';
    num[7] = ' ';
    num[8] = '1';
    num[9] = '0';
    num[10] = '0';
    num[11] = '0';
    num[12] = '\n';
    num[14] = '2';
    num[15] = '5';
    num[16] = '5';
    num[17] = '\n';

    for(int i = 0; i < 18; i++)
    {
            write(fd1, &num[i], 1);
    }

    int c[5][3] = {0};

    for(int i = 0; i < 5; i++)
    {
        if(strcmp(argv[i + 2], "red") == 0)
        {
            c[i][0] = 255;
            c[i][1] = 0;
            c[i][2] = 0;
        }
        else if(strcmp(argv[i + 2], "green") == 0)
        {
            c[i][0] = 0;
            c[i][1] = 255;
            c[i][2] = 0;
        }
        else if(strcmp(argv[i + 2], "blue") == 0)
        {
            c[i][0] = 0;
            c[i][1] = 0;
            c[i][2] = 255;
        }
        else if(strcmp(argv[i + 2], "yellow") == 0)
        {
            c[i][0] = 255;
            c[i][1] = 255;
            c[i][2] = 0;
        }
        else if(strcmp(argv[i + 2], "orange") == 0)
        {
            c[i][0] = 255;
            c[i][1] = 128;
            c[i][2] = 0;
        }
        else if(strcmp(argv[i + 2], "cyan") == 0)
        {
            c[i][0] = 0;
            c[i][1] = 255;
            c[i][2] = 255;
        }
        else if(strcmp(argv[i + 2], "magenta") == 0)
        {
            c[i][0] = 255;
            c[i][1] = 0;
            c[i][2] = 255;
        }
        else if(strcmp(argv[i + 2], "ocean") == 0)
        {
            c[i][0] = 0;
            c[i][1] = 128;
            c[i][2] = 255;
        }
        else if(strcmp(argv[i + 2], "violet") == 0)
        {
            c[i][0] = 128;
            c[i][1] = 0;
            c[i][2] = 255;
        }
    }

    for(int i = 0; i < 10; i++)
    {
        pid_t childPid;
        childPid = fork();
        int d = 0;
        
        if(childPid == 0)
        {
            if(i == 0 || i == 1)
            {    
                for(int a = 0; a < 100; a++)
                {
                    for(int j = 0; j < 500; j++)
                    {
                        write(fd1, &c[1][0], 1);
                        write(fd1, &c[1][1], 1);
                        write(fd1, &c[1][2], 1);
                    }
                    for(int k = 0; k < 500; k++)
                    {
                        write(fd1, &c[2][0], 1);
                        write(fd1, &c[2][1], 1);
                        write(fd1, &c[2][2], 1);
                    }
                }
            }
            else if(i == 2)
            {
            	
            	for(int a = 200; a < 250; a++)
                {
                    for(int j = 0; j < 500; j++)
                    {
                        write(fd1, &c[1][0], 1);
                        write(fd1, &c[1][1], 1);
                        write(fd1, &c[1][2], 1);
                    }
                    for(int k = 0; k < 500; k++)
                    {
                        write(fd1, &c[2][0], 1);
                        write(fd1, &c[2][1], 1);
                        write(fd1, &c[2][2], 1);
                    }
                }
                for(int a = 250; a < 300; a++, d++)
                {
                    for(int j = 0; j < (500 - d); j++)
                    {
                        write(fd1, &c[1][0], 1);
                        write(fd1, &c[1][1], 1);
                        write(fd1, &c[1][2], 1);
                    }   
                    for(int j = 0; j < (2 * d); j++)
                    {
                    	write(fd1, &c[0][0], 1);
                        write(fd1, &c[0][1], 1);
                        write(fd1, &c[0][2], 1);
                    } 
                    for(int k = 0; k < (500 - d); k++)
                    {
                        write(fd1, &c[2][0], 1);
                        write(fd1, &c[2][1], 1);
                        write(fd1, &c[2][2], 1);
                    }
                }
            }
            else if(i == 3 || i == 4)
            {
            	if(i == 3)
            		d = 50;
            	else if(i == 4)
            		d = 150;
                for(int a = 300; a < 400; a++, d++)
                {
                    for(int j = 0; j < (500 - d); j++)
                    {
                        write(fd1, &c[1][0], 1);
                        write(fd1, &c[1][1], 1);
                        write(fd1, &c[1][2], 1);
                    }   
                    for(int j = 0; j < (2 * d); j++)
                    {
                    	write(fd1, &c[0][0], 1);
                        write(fd1, &c[0][1], 1);
                        write(fd1, &c[0][2], 1);
                    } 
                    for(int k = 0; k < (500 - d); k++)
                    {
                        write(fd1, &c[2][0], 1);
                        write(fd1, &c[2][1], 1);
                        write(fd1, &c[2][2], 1);
                    }
                }
            }
            else if(i == 5 || i == 6)
            {
            	if(i == 5)
            		d = 250;
            	else if(i == 6)
            		d = 150;
                for(int a = 500; a < 600; a++, d--)
                {
                    for(int j = 0; j < (500 - d); j++)
                    {
                        write(fd1, &c[3][0], 1);
                        write(fd1, &c[3][1], 1);
                        write(fd1, &c[3][2], 1);
                    }
                    for(int j = 0; j < (2 * d); j++)
                    {
                    	write(fd1, &c[0][0], 1);
                        write(fd1, &c[0][1], 1);
                        write(fd1, &c[0][2], 1);
                    } 
                    for(int k = 0; k < (500 - d); k++)
                    {
                        write(fd1, &c[4][0], 1);
                        write(fd1, &c[4][1], 1);
                        write(fd1, &c[4][2], 1);
                    }
                }  
            }
            else if(i == 7)
            {
            	d = 50;
                for(int a = 700; a < 750; a++, d--)
                {
                    for(int j = 0; j < (500 - d); j++)
                    {
                        write(fd1, &c[3][0], 1);
                        write(fd1, &c[3][1], 1);
                        write(fd1, &c[3][2], 1);
                    }
                    for(int j = 0; j < (2 * d); j++)
                    {
                    	write(fd1, &c[0][0], 1);
                        write(fd1, &c[0][1], 1);
                        write(fd1, &c[0][2], 1);
                    } 
                    for(int k = 0; k < (500 - d); k++)
                    {
                        write(fd1, &c[4][0], 1);
                        write(fd1, &c[4][1], 1);
                        write(fd1, &c[4][2], 1);
                    }
                }
                for(int a = 750; a < 800; a++)
                {
                    for(int j = 0; j < 500; j++)
                    {
                        write(fd1, &c[3][0], 1);
                        write(fd1, &c[3][1], 1);
                        write(fd1, &c[3][2], 1);
                    }
                    for(int k = 0; k < 500; k++)
                    {
                        write(fd1, &c[4][0], 1);
                        write(fd1, &c[4][1], 1);
                        write(fd1, &c[4][2], 1);
                    }
                }
            }
            else if(i == 8 || i == 9)
            {
                for(int a = 800; a < 900; a++)
                {
                    for(int j = 0; j < 500; j++)
                    {
                        write(fd1, &c[3][0], 1);
                        write(fd1, &c[3][1], 1);
                        write(fd1, &c[3][2], 1);
                    }
                    for(int k = 0; k < 500; k++)
                    {
                        write(fd1, &c[4][0], 1);
                        write(fd1, &c[4][1], 1);
                        write(fd1, &c[4][2], 1);
                    }
                }
            }
            exit(0);
        } 
        else
        {
            int returnStatus;
            waitpid(childPid, &returnStatus, 0);
        }
    }

    return 0;
}
 
