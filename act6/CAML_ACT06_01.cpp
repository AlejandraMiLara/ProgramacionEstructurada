// CYNDY ALEJANDRA MIRANDA LARA
// DESC: SUBIR UN PROGRAMA QUE LLAME LOS 3 EJERCICIOS Y CON CADA UNA DE LAS SENTENCIAS.
// Fecha: 05/03/2024
// CAML_ACT06_01.cpp


#include <stdio.h>
#include <stdlib.h>
#include <time.h>



//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void fibonacci_for();
void fibonacci_while();
void fibonacci_do_while();
void factorial_for();
void factorial_while();
void factorial_do_while();
void digitos_for();
void digitos_while();
void digitos_do_while();


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
  printf("1.- Fibonacci FOR \n");
  printf("2.- Fibonacci WHILE \n");
  printf("3.- Fibonacci DO WHILE \n");
  printf("4.- Factorial FOR \n");
  printf("5.- Factorial WHILE \n");
  printf("6.- Factorial DO WHILE \n");
  printf("7.- Digitos FOR \n");
  printf("8.- Digitos WHILE \n");
  printf("9.- Digitos DO WHILE \n");
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
              fibonacci_for();
              break;
        case 2:
              fibonacci_while();
              break;
        case 3:
              fibonacci_do_while();
              break;
        case 4:
              factorial_for();
              break;
        case 5:
              factorial_while();
              break;
        case 6:
              factorial_do_while();
              break;
        case 7:
              digitos_for();
              break;
        case 8:
              digitos_while();
              break;
        case 9:
              digitos_do_while();
              break;
      }

    }while (op != 0);


}

//*********************//

void fibonacci_for()
{
    int i, n, siguiente, primero, segundo;

    printf("\nCuantas veces quieres que se repita el ciclo?\n");
    scanf("%d", &n);
    printf("\n");

    primero = 0; 
    segundo = 1;

    for (i = 0; i < n; i++)
    {
        printf(" %d ", primero);
        siguiente = primero + segundo;
        primero = segundo;
        segundo = siguiente;
    }
}

//*********************//

void fibonacci_while()
{
    int i, n, siguiente, primero, segundo, bandera;

    printf("\nCuantas veces quieres que se repita el ciclo?\n");
    scanf("%d", &n);
    printf("\n");

    primero = 0; 
    segundo = 1;
    bandera = 1;
    i=0;
    
    while(bandera)
    {
        printf(" %d ", primero);
        siguiente = primero + segundo;
        primero = segundo;
        segundo = siguiente;
        i++;
        
        if(i >= n)
        {
            bandera = 0;
        }
    }
    
}

//*********************//


void fibonacci_do_while()
{
    int i, n, siguiente, primero, segundo, bandera;

    printf("\nCuantas veces quieres que se repita el ciclo?\n");
    scanf("%d", &n);
    printf("\n");

    primero = 0; 
    segundo = 1;
    bandera = 1;
    i=0;
    
    do
    {
        printf(" %d ", primero);
        siguiente = primero + segundo;
        primero = segundo;
        segundo = siguiente;
        i++;
        
        if(i >= n)
        {
            bandera = 0;
        }
    }while(bandera);
}


//*********************//

void factorial_for() 
{
    int i, n, res;
    res = 1;
    
    printf("\nDame el numero para obtener el factorial\n");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        res *= (i + 1);
    }
    
    printf("\nResultado: %d\n\n", res);
}

//*********************//

void factorial_while()
{
    int i, n, res, a;
    res = 1;
    a = 1;
    i = 1;
    
    printf("\nDame el numero para obtener el factorial\n");
    scanf("%d", &n);
    
    while(i <= n)
    {
        res *= i;
        i++;
    }
    
    printf("\nResultado: %d\n\n", res);
}


//*********************//

void factorial_do_while()
{
    int i, n, res, a;
    i = 1;
    res = 1;
    a = 1;
    
    printf("\nDame el numero para obtener el factorial\n");
    scanf("%d", &n);
    
    do
    {
        res *= i;
        i++;
    } while (i <= n);
    
    printf("\nResultado: %d\n\n", res);
}

//*********************//
void digitos_for()
{
    int num, i;
    i = 0;

    printf("Escribe un numero grande para contarlo\n");
    scanf("%d", &num);

    while (num != 0)
    {
        num = num / 10;
        i++;
    }

    printf("\nTiene: %d digitos\n", i);
}


//*********************//
void digitos_while()
{
    int num, calc, band, i;
    band = 1;
    calc = 0;
    i = 0;

    printf("Escribe un numero grande para contarlo\n");
    scanf("%d", &num);

    while(band)
    {
        calc = num/10;
        num = calc;
        i++;
        
        if(calc < 1)
        {
            band = 0;
        }
    }

    printf("\nTiene: %d digitos\n", i);
}

//*********************//
void digitos_do_while()
{
    int num, calc, band, i;
    band = 1;
    calc = 0;
    i = 0;

    printf("Escribe un numero grande para contarlo\n");
    scanf("%d", &num);

    do
    {
        calc = num/10;
        num = calc;
        i++;
        
        if(calc < 1)
        {
            band = 0;
        }
    }while(band);

    printf("\nTiene: %d digitos\n", i);
}