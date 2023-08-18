#include <stdio.h>

struct Complex {
    float real;
    float imaginary;
};

struct Complex addComplex(struct Complex num1, struct Complex num2);

int main() {
    struct Complex num1, num2, result;

    // Taking input for the first complex number
    printf("Enter real and imaginary parts of the first complex number:\n");
    scanf("%f %f", &num1.real, &num1.imaginary);

    // Taking input for the second complex number
    printf("Enter real and imaginary parts of the second complex number:\n");
    scanf("%f %f", &num2.real, &num2.imaginary);

    // Adding the complex numbers
    result = addComplex(num1, num2);

    // Displaying the result
    printf("Sum: %.2f + %.2fi\n", result.real, result.imaginary);

    return 0;
}

struct Complex addComplex(struct Complex num1, struct Complex num2) {
    struct Complex sum;

    sum.real = num1.real + num2.real;
    sum.imaginary = num1.imaginary + num2.imaginary;

    return sum;
}
