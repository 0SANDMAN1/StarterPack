#include <stdio.h>
void add(int x, int y);
void sub(int x, int y);
void calc(void (*ptr)(int x, int y), int x, int y);
int main(void)
{
    /*
    int x,y;

    //int *ptr; //Deceleration

    x = 10;

    y = 15;

    printf("%d %d\n", x, y);

    int *ptr = &x; //Deceleration and Definition

    *ptr = 100;

    printf("%d %d", x, y);
    */



    /*
    int x = 10;
    int *ptr = &x;
    printf("%p\n", &x); //calling the address where the variable is stored
    printf("%p\n", ptr++);
    printf("%p\n", ++ptr);
    printf("%p", ptr);
    */


    /*
    int x = 0x11223344; //hot to determine the machine is big or little indian
    char *ptr = (char*)&x;
    if(*ptr = 0x44)
    {
        printf("little");
    }
    else
    {
        printf("Big");
    }
    */


    /*
    int x = 5;
    int y = 15;
    printf("%d %d\n", x, y);
    swap (&x,&y);
    printf("%d %d\n",x ,y);
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    printf("%d %d\n", *x, *y);
}
    */


    //const int *ptr;
    //int *const ptr;
    //const int *const ptr;


    //int *const ptr;
    //ptr++; //error: increment of read-only variable 'ptr'


    /*
    int x = 20;
    void *ptr;
    int *intptr = &x;
    printf("%d", *intptr);
    */


    /*
    int x = 10;
    printf("%d\n", x);
    int **p2;
    int *p1;
    p2 = &p1;
    p1 = &x;
    **p2 = 100;
    printf("%d", x);
    */

    /*
    int x = 25;
    void print (int x)
{
    printf("%d", x);
}
    void (*ptr) (int x);
    ptr = &print;
    ptr(x);
    */


    int x, y;
    x = 10;
    y = 5;
    calc(add, x, y);
    return 0;
}
    void add(int x, int y)
    {
        printf("%d", x + y);
    }
    void sub(int x, int y)
    {
        printf("%d", x-y);
    }
    void calc(void (*ptr)(int x, int y), int x, int y)
    {
        ptr(x, y);
    }
