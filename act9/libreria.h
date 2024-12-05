// CYNDY ALEJANDRA MIRANDA LARA
// DESC: Arreglos en C y Libreria propia
// Fecha: 22/03/2024  TERMINADO: 30/03/2024
// CAML_ACT09_01.cpp

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* PROTOTIPOS DE FUNCIONES */
int msges();
void menu();

void llenar_vector(int vector[], char nombre_vector[]);
void llenar_matriz(int matriz[4][4], char nombre_matriz[]);
void imprimir_vector(int vector[], char nombre_vector[]);
void imprimir_matriz(int matriz[4][4], char nombre_matriz[]);
void ordenar_vector(int vector[]);
int buscar_en_vector(int vector[]);


/* FUNCIONES */

//****************
int msges()
{ int op;
  printf("\n");
  printf ("   M  E   N   U \n");
  printf("1.- LLENAR VECTOR \n");
  printf("2.- LLENAR MATRIZ \n");
  printf("3.- IMPRIMIR VECTOR \n");
  printf("4.- IMPRIMIR MATRIZ \n");
  printf("5.- ORDENAR VECTOR \n");
  printf("6.- BUSCAR VALOR EN VECTOR \n");
  printf("0.- SALIR  \n");
  printf("ESCOGE UNA OPCION: ");
  scanf ("%d",&op);
  return op;
}


//****************
void menu()
{
  int vector[15];
  int matriz[4][4];
  char nombre_vector[100];
  char nombre_matriz[100];
  int op;
  do{
      op=msges();
      switch (op)
      {
        case 1:
        llenar_vector(vector, nombre_vector);
              break;
        case 2:
        llenar_matriz(matriz, nombre_matriz);
              break;
        case 3:
        imprimir_vector(vector, nombre_vector);
              break;
        case 4:
        imprimir_matriz(matriz, nombre_matriz);
              break;
        case 5:
        ordenar_vector(vector);
              break;
        case 6:
        buscar_en_vector(vector);
              break;
      }

    }while (op != 0);

}

//****************
void llenar_vector(int vector[], char nombre_vector[])
{
      printf("\n----------------------------------------\n");

      printf("\n Ingresa el nombre del vector \n");
      fflush(stdin);
      gets(nombre_vector);

      printf("\nGenerando 15 valores aleatorios en el vector : %s ...\n", nombre_vector);

      int revisado[201] = {0};

      for (int i = 0; i < 15; i++)
      {
            int aleatorio;
            do
            {
                  aleatorio = rand() % 101 + 100;
                  
            } while (revisado[aleatorio]); 

            revisado[aleatorio] = 1;
            vector[i] = aleatorio;
      }

      printf("\n        Listo!\n");
      printf("\n----------------------------------------\n");
}

//****************
void llenar_matriz(int matriz[4][4], char nombre_matriz[])
{
      printf("\n----------------------------------------\n");
      printf("\n     LLENANDO MATRIZ AUTOMATICAMENTE....\n\n"); 

      printf("\n Ingresa el nombre de la matriz\n");
      fflush(stdin);
      gets(nombre_matriz);
      int disponibles[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
      int aleatorio;
      int total = 16;
      int indice;

      printf("\nGenerando los valores aleatorios en la matriz : %s ...\n", nombre_matriz);

      int revisado[17] = {0};

      for(int i = 0; i < 4; i++)
      {
            for(int j = 0; j < 4; j++)
            {
                  int aleatorio;
                  do
                  {
                        aleatorio = rand() % 16 + 1;
                  } while (revisado[aleatorio]);

                  revisado[aleatorio] = 1;
                  matriz[i][j] = aleatorio;
            }
      }
      
      printf("\n        Listo!\n");
      printf("\n----------------------------------------\n");
}

//****************
void imprimir_vector(int vector[], char nombre_vector[])
{

    printf("\n----------------------------------------\n");
    printf("\n     IMPRIMIENDO VECTOR: %s ....\n\n", nombre_vector); 

    for(int i = 0; i < 15; i++)
    {
        printf("\n%d\n", vector[i]);
    }

    printf("\n----------------------------------------\n");
}

//****************
void imprimir_matriz(int matriz[4][4], char nombre_matriz[])
{

    printf("\n----------------------------------------\n");
    printf("\n     IMPRIMIENDO MATRIZ: %s ....\n\n", nombre_matriz); 

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

//****************
void ordenar_vector(int vector[])
{

      printf("\n----------------------------------------\n");
      printf("\n     ORDENANDO VECTOR \n\n"); 

      int temp;

      for(int i = 0; i < 15; i++)
      {
            for(int j = 0; j < 15 - 1; j++)
            {
                  if(vector[j] > vector[j+1])
                  {
                        temp = vector[j];
                        vector[j] = vector[j+1];
                        vector[j+1] =  temp;
                  }
            }
      }

      printf("\n     LISTO! \n\n"); 
      printf("\n----------------------------------------\n");

}

//****************
int buscar_en_vector(int vector[])
{
      printf("\n----------------------------------------\n");
      printf("\n     BUSQUEDA EN VECTOR \n\n"); 

      int buscado;
      int encontrado = 0;
      int i;

      printf("\n Ingresa el numero que buscas en el vector: \n");
      scanf("%d", &buscado);
      
      printf("\n----------------------------------------\n");

      for(i = 0; i < 15; i++)
      {
            if(vector[i] == buscado)
            {
                  encontrado = 1;
                  break;
            }
      }

      if(encontrado)
      {
            printf("\n Valor: %d encontrado en la posicion: %d.\n", buscado, i);
      }
      else
      {
            printf(" \n Valor no encontrado. \n");
      }

      printf("\n----------------------------------------\n");
}
