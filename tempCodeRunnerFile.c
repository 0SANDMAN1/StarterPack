void sorted(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n"); // Added a newline at the end for better formatting
    fflush(stdout); // Flush the output buffer
}