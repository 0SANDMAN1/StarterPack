#include <stdio.h>
int main()
{
    int a;

    int b;

    printf("Enter your number here:\n");

    scanf("%d", &a);

    printf("Enter your Nth Bit (0-31) here:\n");

    scanf("%d", &b);

    a ^= (1 << b); //The XOR operation is used to toggle the nth bit of the given number. XORing a bit with 1 will flip its value, and XORing a bit with 0 will leave it unchanged.

    printf("The Nth bit is: %d", a);

    return 0;
}
