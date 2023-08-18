#include <stdio.h>

// Function to increment the value of x by 1
void edit(int* ptr) {
    (*ptr)++;
}

int main() {
    int x;

    printf("Enter the initial value of x: ");
    scanf("%d", &x);

    printf("Value of x before calling edit: %d\n", x);

    // Call edit function and pass the address of x
    edit(&x);

    printf("Value of x after calling edit: %d\n", x);

    // Store [5, 20, 80] inside x without overwriting
    x = 5;
    printf("x = %d\n", x);

    x = 20;
    printf("x = %d\n", x);

    x = 80;
    printf("x = %d\n", x);

    return 0;
}
