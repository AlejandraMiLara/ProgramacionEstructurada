
// CYNDY ALEJANDRA MIRANDA LARA
// DESC: Algoritmo que sirva para desplegar el Total de una llamada telefónica
// Fecha: 07/02/2024 
// CAML_ACT01_08.cpp

#include <stdio.h>

int main(){
    
    float minutos, subtotal, iva, total;
    int tipo;

    printf("\n Escoge el tipo de llamada que hiciste \n");
    printf("1: LOCAL   2: NACIONAL   3: INTERNACIONAL\n");
    scanf("%d", &tipo);

    printf("\n Introduce los minutos usados:\n");
    scanf("%f", &minutos); 

    switch (tipo){
    case 1:
        subtotal = minutos*3;
        iva = subtotal*0.16;
        total = subtotal+iva;

        printf("\nLlamada: LOCAL, %.1f minutos\n\n", minutos);
        printf("Subtotal: $%.1f \n + IVA: $%.1f \n ---------------------- \n Total: $%.1f \n\n ", subtotal, iva, total);
        break;
    case 2:
        if(minutos<=3){
            subtotal = 7;
            iva = subtotal*0.16;
            total = subtotal+iva;

            printf("\nLlamada: NACIONAL, %.1f minutos\n\n", minutos);
            printf("Subtotal: $%.1f \n + IVA: $%.1f \n ---------------------- \n Total: $%.1f \n\n ", subtotal, iva, total);
        }else{
            subtotal = 7 + ((minutos-3)*2);
            iva = subtotal*0.16;
            total = subtotal+iva;

            printf("\nLlamada: NACIONAL, %.1f minutos\n\n", minutos);
            printf("Subtotal: $%.1f \n + IVA: $%.1f \n ---------------------- \n Total: $%.1f \n\n ", subtotal, iva, total);
        }
        break;
    case 3:
        if(minutos<=2){
            subtotal = 9;
            iva = subtotal*0.16;
            total = subtotal+iva;

            printf("\nLlamada: INTERNACIONAL, %.1f minutos\n\n", minutos);
            printf("Subtotal: $%.1f \n + IVA: $%.1f \n ---------------------- \n Total: $%.1f \n\n ", subtotal, iva, total);
        }else{
            subtotal = 9 + ((minutos-2)*4);
            iva = subtotal*0.16;
            total = subtotal+iva;

            printf("\nLlamada: INTERNACIONAL, %.1f minutos\n\n", minutos);
            printf("Subtotal: $%.1f \n + IVA: $%.1f \n ---------------------- \n Total: $%.1f \n\n ", subtotal, iva, total);
        }
        break;
    default:
            printf("Error al escoger el tipo de llamada.");
        break;
    }

    return 0;
}
