#include <stdio.h>
int main()
{
    int a;
    int b;
    printf("Enter Number\n");

    scanf("%d", &a);

    printf("Enter Bit to be toggled\n");

    scanf("%d", &b);

    a ^= (1 << b);

    printf("Your toggle number: %d", a);

    return 0;
}
