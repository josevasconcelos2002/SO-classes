#ifndef PERSON_H
#define PERSON_H

typedef struct person
{
    char *name;
    int age;
} Person;

void insertPerson(char *nome, int idade, char *file);
void listPersons(int n, char *file);

#endif