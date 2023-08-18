#include <stdio.h>

int main() {
    int num;
    int isEven, isOdd;

    printf("Enter a number: ");
    scanf("%d", &num);

    // Check if the LSB (least significant bit) is 0
    isEven = !(num & 1);
    // isEven will be 1 if the number is even, otherwise 0
    isOdd = !isEven;
    printf("%d\n", isEven);
    printf("%d\n", isOdd);

    if (isOdd) {
        printf("The number is odd = 1\n");
        printf("The number is even = 0\n");
    } else {
        printf("The number is odd = 0\n");
        printf("The number is even = 1\n");
    }

    return 0;
}
