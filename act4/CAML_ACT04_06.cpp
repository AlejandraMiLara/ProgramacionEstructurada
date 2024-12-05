// CYNDY ALEJANDRA MIRANDA LARA
// DESC: Programa en C que sirva para calcular el Total a pagar por consumo de agua
// Fecha: 25/02/2024 
// CAML_ACT04_06.cpp

#include <stdio.h>

int main()
{
    int m3;
    float subtotal, iva, total;

    printf("Ingresa los M3 consumidos\n");
    scanf("%d", &m3);

    if(m3 >= 16)
    {
        if(m3 > 50)
        {
            //4
            subtotal = m3 * 11;
            iva = subtotal * 0.16;
            total = subtotal + iva;

            printf("\n M3: %d \n--------------- \n\n Subtotal: %.2f \n Iva: %.2f \n TOTAL: %.2f \n\n", m3, subtotal, iva, total);
        }

        else
        {
            //3
            subtotal = m3 * 10;
            iva = subtotal * 0.16;
            total = subtotal + iva;

            printf("\n M3: %d \n--------------- \n\n Subtotal: %.2f \n Iva: %.2f \n TOTAL: %.2f \n\n", m3, subtotal, iva, total);
        }
    } 
    
    else
    {
        if(m3 > 4)
        {
            //2
            subtotal = m3 * 8;
            iva = subtotal * 0.16;
            total = subtotal + iva;

            printf("\n M3: %d \n--------------- \n\n Subtotal: %.2f \n Iva: %.2f \n TOTAL: %.2f \n\n", m3, subtotal, iva, total);
        }

        else
        {
            //1
            subtotal = 50;
            iva = subtotal * 0.16;
            total = subtotal + iva;

            printf("\n M3: %d \n--------------- \n\n Subtotal: %.2f \n Iva: %.2f \n TOTAL: %.2f \n\n", m3, subtotal, iva, total);
        }
    }
}