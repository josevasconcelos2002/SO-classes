#include "person.h"
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void insertPerson(char *nome, int idade, char *file)
{
    Person p;
    p.name = strdup(nome);
    p.age = idade;
    int fd = open(file, O_WRONLY | O_APPEND);
    // lseek(fd, 0, SEEK_END);
    write(fd, &p, sizeof(Person));
    close(fd);
}

void listPersons(int n, char *file)
{
    int fd = open(file, O_RDONLY);
    Person p;
    char buffer[200];
    for (int i = 1; i <= n && read(fd, &p, sizeof(Person)) > 0; i++)
    {
        write(1, buffer, n);
    }
    close(fd);
}