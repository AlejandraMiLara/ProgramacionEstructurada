/******************************************************************************

    CYNDY ALEJANDRA MIRANDA LARA MATR: 365544
    DESCR: Algoritmo que lea 3 números y desplegar los 3 números en orden ascendente
    FECHA: 21/02/2024  
    CAML_ACT3_03.cpp

*******************************************************************************/

#include <stdio.h>

int main()
{
	int num1, num2, num3;
    printf("Dame el numero 1\n");
	scanf("%d", &num1);
    printf("Dame el numero 2\n");
	scanf("%d", &num2);
    printf("Dame el numero 3\n");
	scanf("%d", &num3);
	
    if(num1 < num2)
    {
        if(num1 < num3)
        {
            if(num2 < num3)
            {
                printf("%d %d %d \n", num1, num2, num3);
            }

            else
            {
                printf("%d %d %d \n", num1, num3, num2);
            }
        }

        else
        {
            printf("%d %d %d \n", num3, num1, num2);
        }
    }
	
    else
    {
        if(num2 < num3)
        {
            if(num1 < num3)
            {
                printf("%d %d %d \n", num2, num1, num3);
            }

            else
            {
                printf("%d %d %d \n", num2, num3, num1);
            }
        }

        else
        {
            printf("%d %d %d \n", num3, num2, num1);
        }
    }

    return 0;
}
