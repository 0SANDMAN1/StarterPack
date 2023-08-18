#include <stdio.h>
#include <stdlib.h>

struct STD
{
    char *name;
    int age;
    float degree;
    int section;
};

void print(struct STD array[5]);

int main()
{
    struct STD Eslam = {"Eslam", 21, 96.27, 1};

    struct STD Ahmed = {"Ahmed", 20, 92.45, 2};

    struct STD Shady = {"Shady", 19, 94.69, 3};

    struct STD Mohamed = {"Mohamed", 22, 95.28, 4};

    struct STD Mohanad = {"Mohanad", 23, 96.39, 5};

    struct STD ID[5] = {Eslam, Ahmed, Shady, Mohamed, Mohanad};

    print(ID);

    return 0;
}

void print(struct STD array[5])
{
    for (int i = 0; i < 5; i++)
    {
        printf("Name: %s\nAge: %d\nDegree: %.2f\nSection: %d\n______________________\n", array[i].name, array[i].age, array[i].degree, array[i].section);
    }
}
