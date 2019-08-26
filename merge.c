
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
        int fd1 = open ("firework.ppm", O_RDONLY);
        int fd2 = open ("150.ppm", O_RDONLY);

        int fd3 = open ("firework150.ppm", O_WRONLY | O_CREAT | O_TRUNC, 0777);

        char buf1[4] = "";
        char buf2[4] = "";

        char buf3[4] = "";
        char buf4[4] = "";

        lseek(fd1, 3, SEEK_SET);
        lseek(fd2, 3, SEEK_SET);

        read(fd1, &buf1, 3);
        lseek(fd1, 1, SEEK_CUR);
        read(fd1, &buf2, 3);

        read(fd2, &buf3, 3);
        lseek(fd2, 1, SEEK_CUR);
        read(fd2, &buf4, 3);

        int str1 = atoi(buf1);
        int str2 = atoi(buf2);
        int str3 = atoi(buf3);
        int str4 = atoi(buf4);

        if(str3 > str1 || str4 > str2)
        {
                return 0;
        }

        lseek(fd1, 0, SEEK_SET);
        lseek(fd2, 15, SEEK_SET);

        char a;

        for(int f = 0; f < 15; f++)
        {
                read(fd1, &a, 1);
                write(fd3, &a, 1);
        }

        for(int m = 0; m < (str4); m++)
        {
                for (int n = 0; n < ((str1-str3)*3); n++)
                {
                        read(fd1, &a, 1);
                        write(fd3, &a, 1);
                }
                lseek(fd1, (str3*3), SEEK_CUR);
                for (int p = 0; p < (str3*3); p++)
                {
                        read(fd2, &a, 1);
                        write(fd3, &a, 1);
                }
        }

        for(int q = 0; q < ((str2-str4)); q++)
        {
                for(int r = 0; r < (str2*3); r++)
                {
                        read(fd1, &a, 1);
                        write(fd3, &a, 1);
                }
        }
    
        close(fd1);
        close(fd2);
        close(fd3);
}
