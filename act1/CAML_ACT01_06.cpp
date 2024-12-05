
// CYNDY ALEJANDRA MIRANDA LARA
// DESC: Algoritmo que lea 3 números y desplegar en orden ascendente 
// Fecha: 07/02/2024 
// CAML_ACT01_06.cpp

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
            printf("\n%d %d %d\n", num3,num2,num1);
        }else if(num3>num1){
            printf("\n%d %d %d", num2,num1,num3);
        }else{
            printf("\n%d %d %d\n", num2,num3,num1);
        }
    }else{
        if(num1>num3){
            printf("\n%d %d %d\n", num3,num1,num2);
        }else if(num2>num3){
            printf("\n%d %d %d", num1,num3,num2);
        }else{
            printf("\n%d %d %d\n", num1,num2,num3);
        }  
    }

    return 0;
}
