
// CYNDY ALEJANDRA MIRANDA LARA
// DESC: Terreno rectangular para saber el costo de sembrar pasto
// Fecha: 06/02/2024
// CAML_ACT01_02.cpp

#include <stdio.h>

int main(){
    
    float precio_por_metro, precio_calculado, perimetro, largo, ancho;
    precio_por_metro = 32.40;

    printf("Introduce el largo del terreno en metros \n");
    scanf("%f", &largo);
    printf("Introduce el ancho del terreno en metros \n");
    scanf("%f", &ancho);

    precio_calculado = (largo*ancho)*precio_por_metro;
    perimetro = (2*largo)+(2*ancho);

    printf("\n\nEl precio de sembrar el pasto en tu terreno es de: $%.2f \n  Además necesitarías %.2f METROS lineales de cerca.\n\n", precio_calculado, perimetro);

    return 0;
}
