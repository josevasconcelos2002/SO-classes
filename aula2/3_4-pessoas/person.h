#define FILENAME "file_pessoas"

typedef struct person
{
    char name[100];
    int age;
} Person;

int new_person(char *name, int age);

int list_persons(int nr);

int change_age(char *name, int age);

int change_age2(int pos, int age);