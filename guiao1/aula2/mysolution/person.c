#include "person.h"
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int new_person(char *nome, int idade)
{
    Person p;
    strcpy(p.name, nome);
    p.age = idade;
    int fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0666);
    write(STDOUT_FILENO, &p, sizeof(Person));
    write(fd, &p, sizeof(Person));
    off_t pos = lseek(fd, 0, SEEK_CUR);
    printf("%lu\n", pos / sizeof(p));
    close(fd);
    return pos;
}

int list_persons(int n)
{
    int fd = open(file, O_RDONLY);
    Person p;
    char buffer[200];
    for (int i = 1; i <= n && read(fd, &p, sizeof(Person)) > 0; i++)
    {
        write(1, buffer, n);
    }
    close(fd);
    return 0;
}