#include <stdio.h>
#include <stdlib.h>
//typedef unsigned char uint8;

/*struct Emp
{
    int salary;
    int age;
    char *name;
    char *position;
    int years[4];
};*/



int main(void)
{
    int cnt = 0;
    char *ptr = "Eslam Ehab";
    int i = 0;
    while(ptr[i]!= '\0')
    {
        cnt++;
        i++;
    }
    printf("%d", cnt);


    /*
    struct Emp Eslam = {999, 21, "Eslam", "Owner", {2019, 2020, 2021, 2022}};
    struct Emp Mina = {999, 21, "Mina", "Owner", {2019, 2020, 2021, 2022}};
    struct Emp mostafa = {999, 21, "Mostafa", "Owner", {2019, 2020, 2021, 2022}};
    struct Emp ibrahim = {999, 21, "Ibrahim", "Owner", {2019, 2020, 2021, 2022}};
    struct Emp gohary = {999, 21, "Gohary", "Owner", {2019, 2020, 2021, 2022}};

    //printf("%s, ", Eslam.name);
    //printf("%d, ", Eslam.salary);
    //printf("%d, ", Eslam.years[3]);
    //printf("%s\n", Eslam.position);
    /*struct Emp *Empptr;
    Empptr = &Eslam;
    printf("%d", Empptr->age);

    struct Emp ID[5]={Eslam, Mina, mostafa, ibrahim, gohary};
    int i;
    for(i=0; i<5; i++)
    {
        printf("%s\n", ID[i].name);
    }
    */


}
