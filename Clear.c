#include <stdio.h>
int main()
{
    int a;
    int b;
    int c;
    printf("Enter Number\n");

    scanf("%d", &a);

    printf("Enter number of shifts to be cleared\n");

    scanf("%d", &b);

    c = ~(1<<b);

    a &= c;

    printf("%d", a);

    return 0;
}
