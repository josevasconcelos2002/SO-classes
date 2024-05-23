#ifndef PERSON_H
#define PERSON_H

#define file "file_pessoas"

typedef struct person
{
    char *name;
    int age;
} Person;

int new_person(char *nome, int idade);
int list_persons(int n);

#endif