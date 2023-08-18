#include <stdio.h>

int main() {
    int num, n;
    printf("Enter any number: ");
    scanf("%d", &num);
    printf("Enter nth bit to toggle (0-31): ");
    scanf("%d", &n);
    num ^= (1 << n);
    printf("Bit toggled successfully.\n\n");
    printf("Number before toggling %d bit: %d (in decimal)\n", n, num ^ (1 << n));
    printf("Number after toggling %d bit: %d (in decimal)\n", n, num);
    return 0;
}
