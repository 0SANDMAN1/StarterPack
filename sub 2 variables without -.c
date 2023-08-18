#include <stdio.h>
int main()
{
    int a, b, sub;
    //printf("Enter 2 Numbers\n");
    scanf("%d%d", &a, &b); //the &sign means that im taking the value inputed from the client
    sub = a+~b+1;
    printf("Subtraction of %d & %d is %d\n", a, b, sub);
    return 0;
}
