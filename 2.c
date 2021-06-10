
#include <stdio.h>
#include <stdlib.h>

struct data
{
    char names[2][10];
    char lname[10];
    int age;
};
struct staff
{
    int room;
    struct data emp[5];
};

int cmpr(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int cmprl(const void *a, const void *b)
{
    return strcmp((const char *)a, (const char *)b);
}

int main(void)
{
    FILE *bFile = fopen("staff.dat", "rb");

    if (!bFile)
    {
        printf("Błąd odczytu pliku");
        exit(1);
    }
    int amount = 0;

    fread(&amount, sizeof(int), 1, bFile);

    printf("Rooms: %d\n\n", amount);

    struct staff *tab = malloc(sizeof(struct staff) * amount);

    fread(tab, sizeof(struct staff), amount, bFile);

    for (int i = 0; i < amount; i++)
    {
        printf("Room: %d \n", tab[i].room);
        for (int j = 0; j < 5; j++)
        {
            struct data *emp = malloc(sizeof(struct data));
            *emp = tab[i].emp[j];
            printf("    Employee: %s %s %s, %d lat\n", emp->names[0], emp->names[1], emp->lname, emp->age);
            free(emp);
        }
    }

    printf("\n\n");
    qsort(tab, amount, sizeof(struct staff), cmpr);

    for (int i = 0; i < amount; i++)
    {
        qsort(tab[i].emp, 5, sizeof(char) * 10, cmprl);
    }

    for (int i = 0; i < amount; i++)
    {
        printf("Room: %d \n", tab[i].room);
        for (int j = 0; j < 5; j++)
        {
            struct data *emp = malloc(sizeof(struct data));
            *emp = tab[i].emp[j];
            printf("    Employee: %s %s %s, %d lat\n", emp->names[0], emp->names[1], emp->lname, emp->age);
            free(emp);
        }
    }

    fclose(bFile);
    free(tab);
    printf("\n-----\n");
    return 0;
}
