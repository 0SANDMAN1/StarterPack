#include <stdio.h>
int main (void)
{
    int x, y;

    printf("Enter First Number: \n");

    scanf("%d", &x);

    printf("Enter Second Number: \n");

    scanf("%d", &y);

    swap (&x,&y);
}
void swap(int *x, int *y)
{
    printf("Numbers Before Swap: x = %d, y = %d \n", *x, *y);

    *x = *x + *y;

    *y = *x - *y;

    *x = *x - *y;

    printf("Numbers After  Swap: x = %d, y = %d\n", *x, *y);
}
