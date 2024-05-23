#include <stdio.h>
#include <string.h>
#include "person.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc < 3)
    {
        printf("Usage:\n");
        printf("Add new person: ./pessoas -i [name] [age]\n");
        printf("List N persons: ./pessoas -l [N]\n");
        printf("Change person age: ./pessoas -u [name] [age]\n");
        printf("Change person age (v2): ./pessoas -o [position] [age]\n");
        return 1;
    }

    int fd = open("./file_pessoas", O_TRUNC | O_CREAT | O_WRONLY, 0666);

    if (strcmp(argv[1], "-i") == 0)
    {
        insertPerson(argv[2], atoi(argv[3]), "./file_pessoas");
    }

    if (strcmp(argv[1], "-l") == 0)
    {
        listPersons(atoi(argv[2]), "./file_pessoas");
    }

    if (strcmp(argv[1], "-u") == 0)
    {
        // TO DO
    }

    if (strcmp(argv[1], "-o") == 0)
    {
        // TO DO
    }
    close(fd);
    return 0;
}
