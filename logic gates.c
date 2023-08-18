#include <stdio.h>
int main()
{
int a=1;
int b=0;
//printf("Enter 2 Values to compare\n");
//scanf("%d%d\n", &a, &b);

printf("%d\n", a&b);
printf("%d\n", a|b);
printf("%d\n", a^b);
printf("%d\n", a<<1);
printf("%d\n", b<<2);
return 0;
}
