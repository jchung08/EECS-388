#include <stdio.h>

int findmin(int array[], int x) {
int min = array[0];
    for (int i = 1; i < x; i++) {
        if (array[i] < min){
            min = array[i];
        }
    }
    return min;
}

int findmax(int array[], int x){
int max = array[0];
    for (int i = 1; i < x; i++) {
        if (array[i] > max){
            max = array[i];
        }
    }
    return max;
}


int main() {
    int array[10] = {500, 1, 255, 7, -12, 40, 42, 999, 50, 227};
    int x = 10;
    char input;

    printf("Enter m, n, or b:\n");
    scanf("%c", &input);

    if (input == 'm') {
        int maxval = findmax(array, x);
        printf("%d\n",maxval);
    } else if (input == 'n') {
        int minval = findmin(array, x);
        printf("%d\n",minval);
    } else if (input == 'b') {
        int minval = findmin(array, x);
        int maxval = findmax(array, x);
        printf("%d\n", minval);
        printf("%d\n", maxval);
    } else {
            printf("Error");
    }
return 0;
}

    
