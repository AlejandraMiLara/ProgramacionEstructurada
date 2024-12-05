// CYNDY ALEJANDRA MIRANDA LARA
// DESC: Programa que use un menú para realizar las 4 operaciones básicas
// Fecha: 24/02/2024
// CAML_ACT04_01.cpp

#include <stdio.h>

int main()
{
    int opc;
    float num1, num2, calc;

    printf("\nMENU:\n ------------------------------------------------ \n 1. Sumar 2. Restar 3. Multiplicar 4. Dividir \n\n");
    scanf("%d", &opc);

    if(opc > 2)
    {
        if(opc == 3)
        {
            printf("Elegiste: Multiplicar \n Dame el primer numero\n");
            scanf("%f", &num1);
            printf("Dame el segundo numero\n");
            scanf("%f", &num2); 

            calc = num1 * num2;
            printf("Resultado: %.2f", calc);
        }

        else
        {
            printf("Elegiste: Dividir \n Dame el primer numero\n");
            scanf("%f", &num1);
            printf("Dame el segundo numero\n");
            scanf("%f", &num2); 

            calc = num1 / num2;
            printf("Resultado: %.2f", calc);
        }
    }

    else
    {
        if(opc == 1)
        {
            printf("Elegiste: Sumar \n Dame el primer numero\n");
            scanf("%f", &num1);
            printf("Dame el segundo numero\n");
            scanf("%f", &num2); 

            calc = num1 + num2;
            printf("Resultado: %.2f", calc);
        }

        else
        {
            printf("Elegiste: Restar \n Dame el primer numero\n");
            scanf("%f", &num1);
            printf("Dame el segundo numero\n");
            scanf("%f", &num2); 

            calc = num1 - num2;
            printf("Resultado: %.2f", calc);
        }
    }


}