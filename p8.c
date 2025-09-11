#include <stdio.h>

int main() {
    int number;
    int bitposition;

    printf("Enter integer: ");
    scanf("%d", &number);

    printf("Enter integer: ");
    scanf("%d", &bitposition);

    int mask = 1 << bitposition;

    if ((number & mask) != 0) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
    }
