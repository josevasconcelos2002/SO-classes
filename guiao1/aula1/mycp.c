#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    char buffer[4096] = {0};
    int fd_read = open(argv[1], O_RDONLY);
    if (fd_read < 0)
    {
        perror("open");
        return -1;
    }
    int fd_write = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0666);
    if (fd_write < 0)
    {
        perror("open");
        return -1;
    }
    while (read(fd_read, buffer, sizeof(buffer)) > 0)
    {
        write(fd_write, buffer, sizeof(buffer));
    }
    close(fd_read);
    close(fd_write);
    return 0;
}