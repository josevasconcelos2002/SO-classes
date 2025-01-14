#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if(argc == 3)
    {
        printf("Argv[0]: %s\n", argv[0]);
        printf("Argv[1]: %s\n", argv[1]);
        printf("Argv[2]: %s\n", argv[2]);
        int fd = open(argv[1], O_RDONLY);
        if(fd != -1)
        {
            char* dest = strcat(argv[2], argv[1]);
            int fd2 = open(dest, O_CREAT | O_WRONLY, 0644);
            printf("Path para o ficheiro resultante: %s \n", dest);
            if(fd2 != -1)
            {
                char buffer[1024] = {0};
                int bytesRead = 0;
                while((bytesRead = read(fd, buffer, 1024)) > 0)
                {
                    write(fd2, buffer, bytesRead);
                }
                close(fd2);
            }
            else
            {
                perror("Error opening destination file");
            }
            close(fd);
        }
        else
        {
            perror("Error opening source file");
        }
        close(fd);
        return 0;
    }

    else
    {
        printf("Usage: ./mycp <file_to_copy> <destination>\n");
        return -1;
    }
}