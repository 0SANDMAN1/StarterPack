#include <stdio.h>
/*char binary_search(int array[])
{
    
     char l;
     char h;
     int mid = 5; 
     int value;
    char m = (l+h)/2;
    while(l<=h)
    {
        if(array[mid] == value)
        {
            return 1;
        }
        if(array[mid] < value)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return 0;




}
int main()
{
    int array[15]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
   binary_search(array);
}*/
void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

void sort(int array[], int size)
{
    int i, j, min;
    for (i = 0; i < size - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
            if (min != i)
            {
                swap(&array[min], &array[i]);
            }
        
        
    }
}

void sorted(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n"); // Added a newline at the end for better formatting
}

int main()
{
    int array[] = {5, 8, 0, 3, 7, 9, 4, 1};
    int size = sizeof(array) / sizeof(array[0]); // Calculate the size of the array

    
    sort(array, size); // Call the sorting function
    /*
    for(int i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }
    */
    sorted(array, size);
    for(int i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}
