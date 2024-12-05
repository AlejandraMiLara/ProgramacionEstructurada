
// CYNDY ALEJANDRA MIRANDA LARA
// DESC: Programa que sirva para calcular el salario semanal de un trabajador
// Fecha: 07/02/2024 
// CAML_ACT01_07.cpp

#include <stdio.h>

int main(){
    
    float salario_normal, salario_extra, salario_total, horas_trabajadas, salario_por_hora, dobles, triples;

    printf("Ingresa las horas trabajadas\n");
    scanf("%f", &horas_trabajadas);

    printf("Ingresa tu salario por hora\n");
    scanf("%f", &salario_por_hora);

    if(horas_trabajadas>40){ //metiste hrs extras
        if(horas_trabajadas <= 49){
            dobles = horas_trabajadas-40;
            salario_normal = ((horas_trabajadas-dobles)*salario_por_hora);
            salario_extra = ((dobles*salario_por_hora)*2);
            salario_total = salario_normal + salario_extra;

            printf("\nLaboraste %.2f horas con un salario de %.2f por hora. \n", horas_trabajadas, salario_por_hora);
            printf("Tuviste: %.2f horas extras pagadas al doble.\n", dobles);
            printf("Salario normal: $%.2f semanal\n", salario_normal);
            printf("Salario extra: $%.2fsemanal\n", salario_extra);
            printf("Salario total: $%.2f semanal\n", salario_total);
        }else{
            dobles = 9;
            triples = horas_trabajadas-49;

            salario_normal = ((horas_trabajadas-(dobles+triples))*salario_por_hora);
            salario_extra = ((dobles*salario_por_hora)*2) + ((triples*salario_por_hora)*3);
            salario_total = salario_normal + salario_extra;

            printf("\nLaboraste %.2f horas con un salario de %.2f por hora. \n", horas_trabajadas, salario_por_hora);
            printf("Tuviste: %.2f horas extras pagadas al doble.\n", dobles);
            printf("Tuviste: %.2f horas extras pagadas al triple.\n", triples);
            printf("Salario normal: $%.2f semanal\n", salario_normal);
            printf("Salario extra: $%.2f semanal\n", salario_extra);
            printf("Salario total: $%.2f semanal\n", salario_total);
        }
    }else{
        salario_normal = (horas_trabajadas*salario_por_hora);
        salario_extra = 0;
        salario_total = salario_normal;

        printf("\nLaboraste %.2f horas con un salario de %.2f por hora. \n", horas_trabajadas, salario_por_hora);
        printf("Salario normal: $%.2f semanal\n", salario_normal);
        printf("Salario extra: $%.2f semanal\n", salario_extra);
        printf("Salario total: $%.2f semanal\n", salario_total);
    }

    return 0;
}
