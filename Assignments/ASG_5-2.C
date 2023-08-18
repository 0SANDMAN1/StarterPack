#include <stdio.h>
void reverse(int arr[], int n);


int main()
{
    int arr_1[] = {1,2,3,4,5,6,7,8,9,10};

    int n;

    n = sizeof(arr_1)/sizeof(arr_1[0]);

    printf(" Original Array: ");

    for(int i = 0; i < n; i++)
    {
        printf("%d  ", arr_1[i]);
    }
    reverse(arr_1, n);

    printf("\nReversed Array: ");
    for(int i = 0; i < n; i++)
{
    printf("%d  ", arr_1[i]);
}
printf("\n");

}




void reverse(int arr[], int n)
{
    int i;
    for(i = 0; i < n / 2; i++)
    {
        int temp = arr[i];                  // Store the value of the current element
        arr[i] = arr[n - i - 1];            // Swap with the corresponding element from the end
        arr[n - i - 1] = temp;              // Assign the stored value to the corresponding end element
    }
}
