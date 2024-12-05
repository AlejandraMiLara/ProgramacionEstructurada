/******************************************************************************

    CYNDY ALEJANDRA MIRANDA LARA MATR: 365544
    DESCR: Algoritmo que lea 3 números y desplegar cuál número es del medio y su valor
    FECHA: 21/02/2024  
    CAML_ACT3_02.cpp

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
	
    if(num1 > num2)
    {
        if(num1 > num3)
        {
            if(num2 > num3)
            {
                printf("El de en medio es %d", num2);
            }

            else
            {
                printf("El de en medio es %d", num3);
            }
        }

        else
        {
            printf("El de en medio es %d", num1);
        }
    }

    else
    {
        if(num2 > num3)
        {
            if(num1 > num3)
            {
                printf("El de en medio es %d", num1);
            }

            else
            {
                printf("El de en medio es %d", num3);
            }
        }

        else
        {
            printf("El de en medio es %d", num2);
        }
    }
	

    return 0;
}
