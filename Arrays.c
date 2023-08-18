#include <stdio.h>
#define add(x,y) x+y
#define mult(x,y) x*y
#define comp(x,y) (x+y)*x
//int array[2]= {[0 ... 1]=1};

/*
unsigned long long int factorial(unsigned int i) // Corrected the function signature
{
    if (i <= 1) // Removed the "unsigned int" from the condition
    {
        return 1;
    }
    return i * factorial(i - 1);
}

int main()
{
    int i;
    printf("Enter Number Here: ");
    scanf("%d", &i); // Corrected the scanf format specifier

    printf("Factorial of %d is %llu", i, factorial(i)); // Corrected the printf format specifier

    return 0;
}
*/
int main(void)
{
    /*
    int a, b;
   printf("EnterNumbers Here: \n");
   scanf("%d%d", &a, &b);
    printf("%d\n", add(a,b));
    printf("%d\n", mult(a,b));
    printf("%d\n", comp(a,b));
    */

    /*
    int array[3] = {[0] = 1, [2] = 2};
    int array[3] = {[0 ... 2]= 3};
    printf("%d\n", array[-1]);
    */


    /*
    int array[5] = {[0]=0, [1]=1, [2]=2, [3]=3, [4]=4};
    int (*ptr)[5];
    ptr = array[5];
    printf("%d", *(ptr++));
    */


    int array[2][4] = {{1, 2, 3, 4},{5, 6, 7, 8}};
    int r;
    int c;
    function(array,2,4);
}
void function(int array[2][4], int r, int c)
{
        int i;
        int j;
        for(i = 0; i < r; i++)
    {
        for(j=0; j < c; j++ )
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}
