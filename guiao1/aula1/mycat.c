#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    char buffer[4096] = {0};
    while (read(STDIN_FILENO, buffer, sizeof(buffer)) > 0)
    {
        write(STDOUT_FILENO, buffer, sizeof(buffer));
    }
}