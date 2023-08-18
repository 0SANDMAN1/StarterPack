#include <stdio.h>

int main() {
    int a, b; // Value added by the user
    printf("Enter Your Number Here:\n");
    scanf("%d", &a);
    b = a % 2;
    if (b) {
        printf("The Number is Even = 0\n");
        printf("The Number is Odd = 1\n");
    } else {
        printf("The Number is Even = 1\n");
        printf("The Number is Odd = 0\n");
    }
    return 0;
}
