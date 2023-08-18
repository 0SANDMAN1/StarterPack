#include <stdio.h>
#include <stdlib.h>

int main()
{
    //int *ptr = malloc(sizeof(int)*15);
    int *ptr = (int*) calloc(1, 15* sizeof(int));
    *ptr = 10;
    ptr = (int*) realloc(ptr, 15 * sizeof(int));
    printf("%d\n", *ptr);
    printf("%p\n", ptr);
    free(ptr);
    printf("%d\n", *ptr);
    printf("%p\n", ptr);
}
