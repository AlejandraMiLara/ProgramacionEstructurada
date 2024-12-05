
// CYNDY ALEJANDRA MIRANDA LARA
// DESC: Algoritmo que lea 3 números y desplegar cuál número es del medio y su valor
// Fecha: 06/02/2024  Modificado: 07/02/2024
// CAML_ACT01_05.cpp

#include <stdio.h>

int main(){
    
    int num1, num2, num3;

    printf("Ingresa el número 1\n");
    scanf("%d",&num1);
    printf("Ingresa el número 2\n");
    scanf("%d",&num2);
    printf("Ingresa el número 3\n");
    scanf("%d",&num3);

    if(num1>num2){
        if(num2>num3){
            printf("-El %d es el de en medio.", num2);
        }else if(num3>num1){
            printf("-El %d es el de en medio.", num1);
        }else{
            printf("-El %d es el de en medio.", num3);
        }
    }else{
        if(num1>num3){
            printf("-El %d es el de en medio.", num1);
        }else if(num2>num3){
            printf("-El %d es el de en medio.", num3);
        }else{
            printf("-El %d es el de en medio.", num2);
        }
    }

    return 0;
}
