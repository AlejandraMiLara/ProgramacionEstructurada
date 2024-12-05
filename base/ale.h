// CYNDY ALEJANDRA MIRANDA LARA
// DESC: 
// Fecha: 
// CAML_ACT0x_xx.cpp

#include <stdio.h>
#include <stdlib.h>


/***********************************************
 *                                               *
 *                                               *
 *                PROTOTIPOS                     *
 *                                               *
 *                                               *
 ***********************************************/


// Funciones de limpieza y presentacion
int msges();
void menu();

// Funciones de validacion


// Funciones principales




/***********************************************
 *                                               *
 *                                               *
 *          DESARROLLO DE FUNCIONES              *
 *                                               *
 *                                               *
 ***********************************************/

/***********************************************
 * Funciones de limpieza y presentacion         *
 ***********************************************/


int msges()
{ int op;
  system ("CLS");
  printf ("   M  E   N   U \n");
  printf("1.-  \n");
  printf("0.- SALIR  \n");
  printf("ESCOGE UNA OPCION: ");
  scanf ("%d",&op);
  return op;
}

void menu()
{
  int op;
  do{
      op=msges();
      switch (op)
      {
        case 1:

              break;
        case 2:

              break;
        case 3:

              break;

      }

    }while (op != 0);


}


/***********************************************
 * Funciones validacion                        *
 ***********************************************/

/**
 * 
 * 
 * 
 * 
 *
 */