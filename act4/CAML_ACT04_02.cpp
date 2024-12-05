// CYNDY ALEJANDRA MIRANDA LARA
// DESC: Programa que use un menú para realizar conversiones de unidades de medida
// Fecha: 24/02/2024
// CAML_ACT04_02.cpp

#include <stdio.h>
#define cm_a_pulg 0.393701
#define cm_a_pies 0.0328084
#define km_a_millas 0.621371
#define pulg_a_cm 2.54
#define pies_a_cm 30.48
#define millas_a_km 1.60934

int main()
{
    int opc;
    float num, calc;

    printf("\nMENU:\n -------------------------------------------------------------------------------- \n 1. cm a pulgadas 2. cm a pies 3. Km a millas 4. Pulgadas a cm 5. pies a cm 6. millas a Km \n\n");
    scanf("%d", &opc);

    if(opc>3)
    {
        if(opc>4)
        {
            if(opc==5)
            {
                printf("Ingresa el valor a convertir\n");
                scanf("%f", &num);
                calc = num * pies_a_cm;
                printf("Resultado: %.2f", calc);
            }

            else
            {
                printf("Ingresa el valor a convertir\n");
                scanf("%f", &num);
                calc = num * millas_a_km;
                printf("Resultado: %.2f", calc);
            }
        }

        else
        {
                printf("Ingresa el valor a convertir\n");
                scanf("%f", &num);
                calc = num * pulg_a_cm;
                printf("Resultado: %.2f", calc);
        }
    }

    else
    {
        if(opc > 1)
        {
            if(opc == 2)
            {
                printf("Ingresa el valor a convertir\n");
                scanf("%f", &num);
                calc = num * cm_a_pies;
                printf("Resultado: %.2f", calc);
            }

            else
            {
                printf("Ingresa el valor a convertir\n");
                scanf("%f", &num);
                calc = num * km_a_millas;
                printf("Resultado: %.2f", calc);
            }
        }

        else
        {
                printf("Ingresa el valor a convertir\n");
                scanf("%f", &num);
                calc = num * cm_a_pulg;
                printf("Resultado: %.2f", calc);
        }
    }

}
