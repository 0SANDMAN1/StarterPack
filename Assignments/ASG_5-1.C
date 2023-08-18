#include <stdio.h>
void max(int arr[]);

void min(int arr[]);

void selection_sort(int arr[]);

void swap(int *i, int *j);

void sorted(int arr[]);

int main()
{
    int arr_1[5];

    int i;

    printf("Enter your Numbers Here: \n");

    for(i = 0; i < 5; i++)
    {
        printf("Enter your Number %d:\n", i + 1);

        scanf("%d", &arr_1[i]);
    }

    printf("Your Numbers are: ");

    for(i = 0; i < 5; i++)
    {
        printf("%d  ", arr_1[i]);
    }

    max(arr_1);
    min(arr_1);
    selection_sort(arr_1);
    sorted(arr_1);
    return 0;
}

void max(int arr[])
{
    int max = arr[0];

    int pos = 0;

    int i;

    for(i = 1; i < 5; i++)
    {
        if(arr[i] > max)
        {
        max = arr[i];

        pos = i;
        }
    }

    printf("\nMax Number is %d with Position of %d\n", max, pos);
}

void min(int arr[])
{
    int min = arr[0];

    int pos = 0;

    int i;

    for(i = 1; i < 5; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
            pos = i;
        }
    }

    printf("Min Number is %d with Position of %d\n", min, pos);
}

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

void selection_sort(int arr[])
{
    int i, j, min;
    for(i = 0; i < 5 - 1; i++)
    {
        min = i;
        for(j = i + 1; j < 5; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(&arr[min], &arr[i]);
        }
    }
}

void sorted(int arr[])
{
    int i;
    for(i = 0; i < 5; i++)
    {
        printf("Sorted Array: %d\n", arr[i]);
    }
    printf("\n");
}
