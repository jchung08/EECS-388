#include <stdio.h>

int main() {
    int size;
    int dupcount = 0;

    printf("How big is the array?\n");
    scanf("%d", &size);

    if (size <= 0) {
        printf("0\n");
        return 0;
    }

    int arr[size];
    for (int i = 0; i < size; i++) {
        printf("Enter element %d:\n", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size; i++) {
        int firsttime = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                firsttime = 0;
                break;
            }
        }

        if (!firsttime) {
            continue;
        }

        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                dupcount++;
                break;
            }
        }
    }

    printf("%d\n", dupcount);
    return 0;
}