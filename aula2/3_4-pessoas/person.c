#include "person.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int new_person(char *name, int age)
{
    Person p;
    strcpy(p.name, name);
    p.age = age;
    int fp = open(FILENAME, O_CREAT | O_WRONLY | O_APPEND, 0600);
    if (fp == -1)
    {
        perror("Erro ao abrir o ficheiro!");
    }
    write(fp, &p, sizeof(Person));

    off_t pos = lseek(fp, 0, SEEK_CUR);
    printf("%llu\n", pos / sizeof(p));
    close(fp);
    return pos;
}

int list_persons(int nr)
{
    Person p;
    char buffer[200];

    int fd = open(FILENAME, O_RDONLY);
    for (int i = 0; i < nr && read(fd, &p, sizeof(Person)) > 0; i++)
    {
        int n = sprintf(buffer, "Registo: %s idade: %d\n", p.name, p.age);
        write(1, buffer, n);
    }
    close(fd);
    return 0;
}

int change_age(char *name, int new_age)
{
    Person p;
    int fd = open(FILENAME, O_RDONLY | O_WRONLY);
    while (read(fd, &p, sizeof(Person)) > 0)
    {
        if (strcmp(p.name, name) == 0)
        {
            printf("Encontrei a pessoa %s\n", p.name);
            p.age = new_age;

            lseek(fd, -sizeof(Person), SEEK_CUR);
            write(fd, &p, sizeof(Person));
            close(fd);
            return 1;
        }
    }
    close(fd);

    return 0;
}

int change_age2(int pos, int age)
{
    Person p;

    int fd = open(FILENAME, O_RDWR);

    lseek(fd, pos * sizeof(Person), SEEK_SET);

    // nao sabemos o que esta escrito no nome
    read(fd, &p, sizeof(Person));
    p.age = age;

    lseek(fd, -sizeof(Person), SEEK_CUR);
    write(fd, &p, sizeof(Person));

    close(fd);
    return 0;
}