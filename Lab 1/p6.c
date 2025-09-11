#include <stdio.h>

int main() {
    char inputString[256];
    char *ptr = inputString;
    int length = 0;

    printf("Enter string: ");

    fgets(inputString, sizeof(inputString), stdin);

    while (*ptr != '\0' && *ptr != '\n') {
        length++;
        ptr++;
    }

    printf("%d\n", length);

    return 0;
}
