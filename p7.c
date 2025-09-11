#include <stdio.h>

int main() {
    int temp;
    int *temp_ptr;

    printf("Enter integer: ");
    scanf("%d", &temp);

    temp_ptr = &temp;

    printf("%d,\n", temp);
    printf("%d,\n", *temp_ptr);
    printf("%p,\n", &temp);
    printf("%p,\n", temp_ptr);

    return 0;
}