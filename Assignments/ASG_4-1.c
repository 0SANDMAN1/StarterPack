#include <stdio.h>
int main(void)
{
    int x;

    printf("Enter Your Number Here:\n");

    scanf("%d", &x);

    printf("Number Before Increment: %d\n", x);

    int *ptr = &x;

    printf("Number After Increment: %d\n", ++*ptr);

    x = 5;

    printf("%d\n", x);

    x = 20;

    printf("%d\n", x);

    x = 80;

    printf("%d\n", x);

    return 0;
}
