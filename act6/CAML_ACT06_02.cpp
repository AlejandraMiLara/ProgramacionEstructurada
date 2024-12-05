// CYNDY ALEJANDRA MIRANDA LARA
// DESC: SUBIR UN PROGRAMA QUE LLAME LOS 5 ejercicios Y CON CADA UNA DE LAS SENTENCIAS.
// Fecha: 07/03/2024 termine 08/03/2024
// CAML_ACT06_02.cpp

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>



//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void derecho_examen();
void tablas_multiplicar();
void lectura_numeros();
void promedio_peso();
void baja_academica();


//****  main principal  *********
int main()
{
   menu();

   return 0;
}


//  *** DESARROLLO DE LAS FUNCIONES  ******
//*********************//
int msges()
{ int op;
  printf("\n");
  printf ("   M  E   N   U \n");
  printf("1.- DERECHO A EXAMEN \n");
  printf("2.- TABLAS DE MULTIPLICAR \n");
  printf("3.- LECTURA DE NUMEROS \n");
  printf("4.- PROMEDIO DE PESO \n");
  printf("5.- BAJA ACADEMICA \n");
  printf("0.- SALIR  \n");
  printf("ESCOGE UNA OPCION: ");
  scanf ("%d",&op);
  return op;
}
//****************
void menu()
{
  int op;
  do{
      op=msges();
      switch (op)
      {
        case 1:
        derecho_examen();
              break;
        case 2:
        tablas_multiplicar();
              break;
        case 3:
        lectura_numeros();
              break;
        case 4:
        promedio_peso();
              break;
        case 5:
        baja_academica();
              break;
      }

    }while (op != 0);


}

//*********************//

void derecho_examen()
{

    int calif=0, acum_sin_derecho=0, acum_calif=0, promedio=0;

    for(int i = 0; i < 40; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("\n DAME EL PROMEDIO: %d DEL ALUMNO: %d \n", (j+1), (i+1));
            scanf("%d", &calif);
            acum_calif += calif; 
        }

        promedio = acum_calif/5;

        if(promedio < 50)
        {
            acum_sin_derecho++;
        }

        promedio = 0;
        acum_calif = 0;
        calif = 0;

    }

    printf("\n Hay: %d alumnos sin derecho a examen \n", acum_sin_derecho);

}

void tablas_multiplicar()
{
    int calc;
    
    for (int i = 0; i < 10; i++)
    {
        printf("\n TABLAS DEL: %d \n", (i+1));

        for(int j = 0; j < 10; j++)
        {
            calc = (i+1)*(j+1);
            printf("%d X %d = %d\n",(i+1),(j+1),calc);
        }

        system("pause");
    }
    
}

void lectura_numeros()
{
    int n, valor, suma=0, media;
    printf("\nIngresa cuantos numeros quieres sumar (y obtener media)\n");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("\nIngresa el %d dato\n", (i+1));
        scanf("%d", &valor);

        suma += valor; 
    }

    media = suma/n;
    printf("\n Suma: %d --- Media: %d \n", suma, media);

}

void promedio_peso()
{
    int i=1, peso = 0, acum_peso = 0, band = 1, promedio = 0;

    while(band)
    {
        printf("\n Ingresa tu peso \n");
        scanf("%d", &peso);
        acum_peso += peso;

        promedio = acum_peso/i;

        if(acum_peso > 805) //ya incluye el 15% de sobrepeso
        {
            printf("\n Exceso de peso \n");
            printf("\n Promedio de peso: %d\n", promedio);
            band = 0;
        }

        if(i > 10)
        {
            printf("\n Exceso de tripulantes \n");
            printf("\n Promedio de peso: %d\n", promedio);
            band = 0;
        }
    }
}

void baja_academica()
{
    int i, calif, acum_calif=0, promedio;
    int repetir = 0;

    for(i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("\n Introduce tu %d calificacion: \n", (j+1));
            scanf("%d", &calif);
            acum_calif += calif;
        }

        promedio = acum_calif/3;

        if(promedio < 60)
        {
            system("cls");
            printf("\n Reprobaste \n");
        }
        else
        {
            system("cls");
            printf("\n Aprobado \n");
            break;
        }
    }

    if(i > 2)
    {
        printf("\n Baja academica \n");
    }


}