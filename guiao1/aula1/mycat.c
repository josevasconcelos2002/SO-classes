#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    if(argc == 2)
    {
        int fd = open(argv[1], O_RDONLY);
        if(fd)
        {
            char buffer[1024] = {0};
            int bytesRead = 0;
            while((bytesRead = read(fd, buffer, 1024)) > 0)
            {
                write(STDOUT_FILENO, buffer, bytesRead);
            }
        }
        close(fd);
        return 0;
    }
    else
    {
        printf("Introduza 2 argumentos\n");
        return -1;
    }
}