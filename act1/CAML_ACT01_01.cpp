
// CYNDY ALEJANDRA MIRANDA LARA
// DESC: Algoritmo que sirva para calcular el volumen de un cilindro
// Fecha: 06/02/2024
// CAML_ACT01_01.cpp

#include <stdio.h>

int main(){
    
    float radio, altura, volumen;
    float PI = 3.1416;

    printf("Dame el radio en cm\n");
    scanf("%f", &radio);
    printf("Dame la altura en cm\n");
    scanf("%f", &altura);

    volumen = PI*(radio*radio)*altura;
    printf("\n\n El volumen es de: %.2f cm^3 \n\n", volumen);

    return 0;
}
