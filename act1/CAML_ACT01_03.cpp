
// CYNDY ALEJANDRA MIRANDA LARA
// DESC: Algoritmo que lea 3 calificaciones calcule el promedio del alumno 
// Fecha: 06/02/2024
// CAML_ACT01_03.cpp

#include <stdio.h>

int main(){
    
    float calif1, calif2, calif3, promedio;

    printf("Dame la calificación 1\n");
    scanf("%f",&calif1);
    printf("Dame la calificación 2\n");
    scanf("%f",&calif2);
    printf("Dame la calificación 3\n");
    scanf("%f",&calif3);

    promedio = (calif1+calif2+calif3)/3;

    if(promedio<30){
        printf("Repetir");
    }
    
    else if(promedio>=30 && promedio < 60 ){
        printf("Extraordinario");
    }

    else if(promedio>=60 && promedio < 70 ){
        printf("Suficiente");
    }

    else if(promedio>=70 && promedio < 80 ){
        printf("Regular");
    }

    else if(promedio>=80 && promedio < 90 ){
        printf("Bien");
    }

    else if(promedio>=90 && promedio < 98 ){
        printf("Muy bien");
    }

    else if(promedio>=98 && promedio < 100 ){
        printf("Excelente");
    }

    else{
        printf("Error en promedio");
    }

    return 0;
}
