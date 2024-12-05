// CYNDY ALEJANDRA MIRANDA LARA
// DESC: (Funciones e Introduccion a Arreglos en C)  
// Fecha: 19/03/2024   Terminado: 22/03/2024s
// CAML_ACT08_01.cpp

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void llenar_primer_vector(int primer_vector[]);
void llenar_segundo_vector(int segundo_vector[]);
void llenar_tercer_vector(int primer_vector[], int segundo_vector[], int tercer_vector[]);
void imprimir_vectores(int primer_vector[], int segundo_vector[], int tercer_vector[]);
void llenar_matriz(int primer_vector[], int segundo_vector[], int matriz[4][4]);
void imprimir_matriz(int matriz[4][4]);

//****  main principal  *********
int main()
{
   srand(time(NULL));
   menu();
   return 0;
}

//  *** DESARROLLO DE LAS FUNCIONES  ******
//*********************//
int msges()
{ 
  int op;
  printf("\n");
  printf("   M  E   N   U \n");
  printf("1.- LLENAR VECTOR 1 (MANUALMENTE) \n");
  printf("2.- LLENAR VECTOR 2 ALEATORIAMENTE \n");
  printf("3.- LLENAR VECTOR 3 (CON VECTOR1 Y VECTOR2) \n");
  printf("4.- IMPRIMIR VECTORES \n");
  printf("5.- LLENA MATRIZ 4 X 4 \n");
  printf("6.- IMPRIMIR MATRIZ \n");
  printf("0.- SALIR  \n");
  printf("ESCOGE UNA OPCION: ");
  scanf("%d",&op);
  return op;
}
//****************
void menu()
{
  int primer_vector[10];
  int segundo_vector[10];
  int tercer_vector[20];
  int matriz[4][4];
  int op;
  do{
      op=msges();
      switch (op)
      {
        case 1:
          llenar_primer_vector(primer_vector);
          break;
        case 2:
          llenar_segundo_vector(segundo_vector);
          break;
        case 3:
          llenar_tercer_vector(primer_vector, segundo_vector, tercer_vector);
          break;
        case 4:
          imprimir_vectores(primer_vector, segundo_vector, tercer_vector);
          break;
        case 5:
          llenar_matriz(primer_vector, segundo_vector, matriz);
          break;
        case 6:
          imprimir_matriz(matriz);
          break;
      }
    } while (op != 0);
}

//*********************//
void llenar_primer_vector(int primer_vector[])
{
  int i = 0;
  printf("\n----------------------------------------\n");
  while(i < 10)
  {
    printf("\nEscribe el %d valor del arreglo (entre 30 y 70)\n", (i+1));
    scanf("%d", &primer_vector[i]);
    if(primer_vector[i] >= 30 && primer_vector[i] <= 70)
    {
      i++;
    }
    else
    {
      printf("\nEl valor ingresado no esta entre 30 y 70, ingresalo nuevamente.\n");
    }
  }
  printf("\n----------------------------------------\n");
}

void llenar_segundo_vector(int segundo_vector[])
{
  printf("\n----------------------------------------\n");
  printf("\nGenerando 10 valores aleatorios...\n");
  int revisado[20] = {0};
  for (int i = 0; i < 10; i++)
  {
    int aleatorio;
    do
    {
      aleatorio = rand() % 20 + 1;
    } while (revisado[aleatorio]); 
    revisado[aleatorio] = 1;
    segundo_vector[i] = aleatorio;
  }
  printf("\n        Listo!\n");
  printf("\n----------------------------------------\n");
}

void llenar_tercer_vector(int primer_vector[], int segundo_vector[], int tercer_vector[])
{
  printf("\n----------------------------------------\n");
  printf("\nLlenando el tercer vector con los vectores 1 y 2...\n");
  for(int i = 0; i < 10; i++)
  {
    tercer_vector[i] = primer_vector[i];
    tercer_vector[i+10] = segundo_vector[i];
  }
  printf("\n        Listo!\n");
  printf("\n----------------------------------------\n");
}

void imprimir_vectores(int primer_vector[], int segundo_vector[], int tercer_vector[])
{
  printf("\n----------------------------------------\n");
  printf("\n        IMPRESION DE VECTORES\n\n");
  printf("\n----------------------------------------\n");      
  printf("\nVECTOR 1\n");
  for(int i = 0; i < 10; i++)
  {
    printf("\n%d\n", primer_vector[i]);
  }
  printf("\nVECTOR 2\n");
  for(int i = 0; i < 10; i++)
  {
    printf("\n%d\n", segundo_vector[i]);
  }
  printf("\nVECTOR 3\n");
  for(int i = 0; i < 20; i++)
  {
    printf("\n%d\n", tercer_vector[i]);
  }
  printf("\n----------------------------------------\n");
}

void llenar_matriz(int primer_vector[], int segundo_vector[], int matriz[4][4])
{
  printf("\n----------------------------------------\n");
  printf("\n     LLENANDO MATRIZ AUTOMATICAMENTE....\n\n"); 
  int k = 0;
  for(int i = 0; i < 2; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      matriz[i][j] = primer_vector[k];
      k++;
    }
  }
  k = 0;
  for(int i = 2; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      matriz[i][j] = segundo_vector[k];
      k++;
    }
  }
  printf("\n        Listo!\n");
  printf("\n----------------------------------------\n");   
}

void imprimir_matriz(int matriz[4][4])
{
  printf("\n----------------------------------------\n");
  printf("\n        IMPRESION DE MATRIZ\n\n");
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      if(matriz[i][j] < 10)
      {
        printf("0%d ", matriz[i][j]);
      }
      else
      {
        printf("%d ", matriz[i][j]);
      }
    }
    printf("\n");
  }
  printf("\n----------------------------------------\n");
}
