// CYNDY ALEJANDRA MIRANDA LARA
// DESC: Función en C que pida al usuario el valor de n, y desplegar todos los números enteros positivos menores de n en orden descendente. 
// Fecha: 27/02/2024 modificado: 02/03/2024
// CAML_ACT05_01.cpp


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//#define N 10
//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void Genera_Numeros_MenoresN_Des();
void Genera_Numeros_Aleatorios();
void Genera_Numeros_Definidos();
void Genera_Tabla_Multiplicar();


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
  //system ("CLS");
  printf ("   M  E   N   U \n");
  printf("1.- GENERAR NUMEROS MENORES QUE N EN ORDEN DESCENDENTE \n");
  printf("2.- GENERAR NUMEROS ALEATORIOS \n");
  printf("3.- GENERAR 35 NUMEROS \n");
  printf("4.- GENERAR TABLA DE MULTIPLICAR DE N NUMEROS \n");
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
              Genera_Numeros_MenoresN_Des();
              break;
        case 2:
              Genera_Numeros_Aleatorios();
              break;
        case 3:
              Genera_Numeros_Definidos();
              break;
        case 4:
              Genera_Tabla_Multiplicar();
              break;
      }

    }while (op != 0);


}

//*********************//

void Genera_Numeros_MenoresN_Des()
{
      int n;
      printf("\n\n GENERAR NUMEROS MENORES QUE N EN ORDEN DESC \n");
      printf("Ingresa un numero N\n");
      scanf("%d", &n);

      if(n > 0)
      {
            for (int i = n; i >= 0; i--)
            {
                  printf("%d\n", i);
            }

            printf("\n");
      }

      else
      {
            printf("No hay numeros positivos!\n\n");
      }

      
}

//*************************//

void Genera_Numeros_Aleatorios()
{
      printf("\n\n 40 NUMEROS ALEATORIOS DE 0-200\n");
      int aleatorio, acum_par, acum_impar;
      float par;
      srand (time(NULL));
      acum_par = 0;
      acum_impar = 0;

      for (int i = 0; i <= 40; i++)
      {
            aleatorio = rand() % 200;
            par = aleatorio % 2;

            if(par == 0)
            {
                  printf("Numero %d: %d,  SI es PAR\n", i,aleatorio);
                  acum_par += 1;
            }
            else
            {
                  printf("Numero %d: %d,  NO es PAR\n", i,aleatorio);
                  acum_impar += 1;
            }
            
      }
      
      printf("\n\n Total de pares: %d --- Total de impares: %d \n\n", acum_par,acum_impar);

}

//*************************//

void Genera_Numeros_Definidos()
{
      printf("\n\n 35 NUMEROS ALEATORIOS DE 100-200\n");
      int aleatorio, mayor, menor;
      srand (time(NULL));
      mayor = 0;
      menor = 200;

      for (int i = 0; i <= 35; i++)
      {
            aleatorio = rand() % 101 + 100;
            printf("\nNumero %d: %d \n", i, aleatorio);

            if(aleatorio > mayor)
            {
                  mayor = aleatorio;
            }

            if(aleatorio < menor)
            {
                  menor = aleatorio;
            }
      } 

      printf("\nMenor: %d --- Mayor: %d \n", menor, mayor);
}


//*************************//

void Genera_Tabla_Multiplicar()
{
      int n;

      printf("TABLA DE MULTIPLICAR DE N NUMERO\n");
      printf("Ingresa un numero del 1 al 20\n");
      scanf("%d", &n);

      if(n > 10)
      {
            if(n <= 20)
            {
                  for (int i = 0; i <= 10; i++)
                  {
                        int calc = n * i;
                        printf("%d X %d = %d\n", n,i,calc);
                  }
            }
            else
            {
                  printf("Debe ser menor que 20\n");
            }
      }
      else
      {
            if(n > 0)
            {
                  for (int i = 0; i <= 10; i++)
                  {
                        int calc = n * i;
                        printf("%d X %d = %d\n", n,i,calc);
                  }
            }
            else
            {
                  printf("Debe ser mayor que 0\n");
            }
      }
}