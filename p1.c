#include <stdio.h>
int main() {
    char operation;
    int operand1;
    int operand2;
    int result;

    printf("Enter first Operand:\n");
    scanf("%d", &operand1);
    printf("Enter an Operation:\n");
    scanf(" %c", &operation);
    
    switch(operation){
    case '+':
        printf("Enter second Operand:\n");
        scanf("%d", &operand2);
        result = operand1 + operand2;
        break;
    
    case '-':
        printf("Enter second Operand:\n");
         scanf("%d", &operand2);
        result = operand1 - operand2;
        break;
    
    case '*':
        printf("Enter second Operand:\n");
         scanf("%d", &operand2);
        result = operand1 * operand2;
        break;
    case '/':
        printf("Enter second Operand:\n");
         scanf("%d", &operand2);
        result = operand1 / operand2;
        break;
    case 's':
        result = operand1 * operand1;
        break;
    case 'c':
        result = operand1 * operand1 * operand1;
        break;
         }


    printf("%d\n", result);
    return 0;
        }
    