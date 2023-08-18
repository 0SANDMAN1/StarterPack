#include <stdio.h>
#include <math.h>
//int main()
//{
    /*
    unsigned char x = 240;
    x+=1;
    printf("%d", x);
    return 0;
    */

    /*
    int x = 5;
    int y;
    y=x++; //prefix will increment the x first then give its value to y
    y=++x; //posfix will give the x value to y then increment x
    */

    /*
    float x, y; //exercise 1
    printf("Enter Temperature Here in F:\n");
    scanf("%f", &x);
    y = ( x - 32)/1.8;
    printf("Temperature in Celsius: %f", y);
    return 0;
    */

    /*
    int x;
    int i;
    int y;
    printf("Enter Your Number here:");
    scanf("%d", &x);
    for(i=0;i<11;i++)
    {
        y = x * i;
        printf("%d * %d = %d\n", x, i, y);
    }
    */


    /*
    int x, y;
    printf("Enter 2 Numbers:\n");
    scanf("%d%d", &x, &y);
    if(x>y)
        printf("%d is Greater", x);
    else if(y>x)
    printf("%d is Greater", y);
    else
        printf("they are equal!");
        */

        /*
        int x, y, i;
        printf("Enter Number of Rows:");
        scanf("%d", &x);
        for(i=1;i<=x;i++)
        {
            for(y=i;y<x;y++)
        {
            printf(" ");
        }

        for(y=1;y<=(2*i-1);y++)
        {
            printf("*");
        }

        printf("\n");
        }
        return 0;
        */

        //int add(int x, int y); //has input arguments and has return
        //void printage(float age); //has inputs arguments and no return
        //int scanuserpass(void); //has no inputs arguments and has return
        //void pirntmyname(void);//has no arguments and has no return

        double getsqrt(double y)
        {
            if(y<0)
                printf("can't get square root of negative number");

        else
            return sqrt(y);
        }
        int main()
        {
            double x;
            printf("Enter Number Here:");
            scanf("%lf", &x);
            double ans = getsqrt(x);
            if(ans>0)
            printf("square root of %lf is %lf", x, ans);
}
