#include <stdio.h>
int main()
{
    int math;
    float number_1, number_2, result;

    printf("Enter Your First Number Here:\n");

    scanf("%f", &number_1);

    printf("Choose Your Operation Type Here:\n");
    printf("1. +\n");
    printf("2. -\n");
    printf("3. *\n");
    printf("4. /\n");

    scanf("%d", &math);

    printf("Enter Your Second Number Here:\n");

    scanf("%f", &number_2);

    switch (math)
    {
    case 1:
        result = number_1 + number_2;
        break;
    case 2:
        result = number_1 - number_2;
        break;
    case 3:
        result = number_1 * number_2;
        break;
    case 4:
        if(number_2 == 0)
        {
            printf("Can't Divide By Zero :)\n");
        }
        else
        {
            result = number_1 / number_2;
        }
        break;
    default:
        printf("You Didn't Enter Valid Operation\n");
    }
    printf("Your Answer is: %f", result);
    return 0;
}
