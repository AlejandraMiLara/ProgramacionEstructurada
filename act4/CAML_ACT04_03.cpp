// CYNDY ALEJANDRA MIRANDA LARA
// DESC: Programa que lea 6 números, desplegar el valor del número mayor.
// Fecha: 25/02/2024
// CAML_ACT04_03.cpp

#include <stdio.h>

int main()
{
    int num1, num2, num3, num4, num5, num6, max1, max2;

    printf("Escribe el primer numero\n");
    scanf("%d", &num1);
    printf("Escribe el segundo numero\n");
    scanf("%d", &num2);
    printf("Escribe el tercer numero\n");
    scanf("%d", &num3);
    printf("Escribe el cuarto numero\n");
    scanf("%d", &num4);
    printf("Escribe el quinto numero\n");
    scanf("%d", &num5);
    printf("Escribe el sexto numero\n");
    scanf("%d", &num6);

    //para 1,2,3

    if(num1 > num2)
    {
        if(num1 > num3)
        {
            max1 = num1;
        }
        
        else
        {
            max1 = num3;
        }
    }
    
    else
    {
        if(num3 > num2)
        {
            max1 = num3;
        }
        
        else
        {
            max1 = num2;
        }
    }

    // para 4,5,6

    if(num4 > num5)
    {
        if(num4 > num6)
        {
            max2 = num4;
        }
        
        else
        {
            max2 = num6;
        }
    }
    
    else
    {
        if(num6 > num5)
        {
            max2 = num6;
        }
        
        else
        {
            max2 = num5;
        }
    }

    if(max1 > max2)
    {
        printf("\n\n El mayor es: %d ", max1);
    }

    else
    {
        printf("\n\n El mayor es: %d ", max2);
    }

}