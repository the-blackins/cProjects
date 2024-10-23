#include <stdio.h>

double add(double a, double b) {
    return a + b;
}

double multiply(double a, double b) {
    return a * b;
}

double subtraction(double a, double b) {
    return a - b;
}

double divide(double a, double b) {
    return a / b;
}

int main() {
    int commence, complex;
    printf("Begin operation [yes = 1 / no = 0]: ");
    scanf("%d", &commence);
 
    while (commence == 1) {
        double num1, numN, result;
        char oper;

        printf("Input number: ");
        scanf("%lf", &num1);

        printf("Choose your operator: - + * / : ");
        scanf(" %c", &oper);  
        
        printf("Input number: ");
        scanf("%lf", &numN);
        
complex_calculation_begin:

        

        switch (oper) {
            case '+':
                result = add(num1, numN);
                printf("Result: %.2lf\n", result);
                break;
            case '-':
                result = subtraction(num1, numN);
                printf("Result: %.2lf\n", result);
                break;
            case '*':
                result = multiply(num1, numN);
                printf("Result: %.2lf\n", result);
                break;
            case '/':
                if (numN == 0) {
                    printf("Error: Division by zero is undefined.\n");
                } else {
                    result = divide(num1, numN);
                    printf("Result: %.2lf\n", result);
                }
                break;
            default:
                printf("Error: Invalid operator. Please use +, -, *, or /.\n");
                break;
        }

        printf("do you want the operation to be a continous one?  [yes = 1 / no = 0]: ");
        scanf( "%d", &complex);

        // numN = result;
        if (complex ==0)
        {
           printf("Continue operation [yes = 1 / no = 0]: ");
           scanf("%d", &commence); 
        }
        else if (complex)
        {
            num1 = result;

            printf("Choose your operator: - + * / : ");
            scanf(" %c", &oper);  

            printf("Input next number: ");
            scanf("%lf", &numN);

            printf("%.2lf  %c  %.2lf  ", num1, oper, numN);

            goto complex_calculation_begin;

        }
        else
        {
            printf("invalid input");
        }
        
        
        


        
        
        
        

        printf("Final result: %.2lf\n", result);
    }

    printf("Exiting the operation. Goodbye!\n");
    return 0;
}
