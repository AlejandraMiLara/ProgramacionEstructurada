// CYNDY ALEJANDRA MIRANDA LARA
// DESC: realizar un programa con 9 salidas distintas 
// Fecha: 16/03/2024
// CAML_ACT07_02.cpp

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void leer_cadena(char cad[]);
int tam_cad(char cad[]);
void mayusculas(char cad[]);
void minusculas(char cad[]);
void capitalizar(char cad[]);
void num_letras(char cad[]);
void inversa(char cad[]);
void sin_espacios(char cad[]);
void validar(char cad[]);
void mix(char cad[]);
void palindromo(char cad[]);


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
    printf("1.- CADENA A MAYUSCULAS \n");
    printf("2.- CADENA A MINUSCULAS \n");
    printf("3.- CADENA A CAPITAL \n");
    printf("4.- NUMERO DE LETRAS \n");
    printf("5.- A LA INVERSA \n");
    printf("6.- SIN ESPACIOS \n");
    printf("7.- VALIDAR \n");
    printf("8.-MIX \n");
    printf("9.- PALINDROMO \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf ("%d",&op);
    return op;
}
//****************
void menu()
{
  int op;
  char cad[30];
  leer_cadena(cad);
  
  do{
      op=msges();
      switch (op)
      {
        case 1:
		mayusculas(cad);
              break;
        case 2:
		minusculas(cad);
              break;
        case 3:
		capitalizar(cad);
              break;
        case 4:
		num_letras(cad);
              break;
        case 5:
		inversa(cad);
              break;
        case 6:
		sin_espacios(cad);
              break;
        case 7:
		validar(cad);
              break;
		case 8:
		mix(cad);
			  break;
		case 9:
		palindromo(cad);
			  break;
      }

    }while (op != 0);


}

//*********************//

void leer_cadena(char cad[])
{
	system("cls");
	printf("\n\nIngresa la cadena\n\n");
	fflush(stdin);
	gets(cad);
}

int tam_cad(char cad[])
{	
	
	int i;
	for(i = 0; cad[i] != '\0' ; i++);
	return i;

}

//*********************//

void mayusculas(char cad[]) {
    int n = tam_cad(cad); 

    for (int i = 0; i < n; i++)
	{
        if (cad[i] >= 'a' && cad[i] <= 'z')
		{
            cad[i] -= 32;
        }
    }

    printf("\n%s\n", cad);
}

void minusculas(char cad[]) {
    int n = tam_cad(cad); 

    for (int i = 0; i < n; i++)
	{
        if (cad[i] >= 'A' && cad[i] <= 'Z')
		{
            cad[i] += 32;
        }
    }

    printf("\n%s\n", cad);
}

void capitalizar(char cad[])
{
    int n = tam_cad(cad);

    for (int i = 0; i < n; i++) {
        if (cad[i] >= 'A' && cad[i] <= 'Z')
		{
            cad[i] += 32;
        }
    }

    for (int i = 0; i < n; i++)
	{
        if (i == 0 || cad[i - 1] == ' ')
		{
            if (cad[i] >= 'a' && cad[i] <= 'z')
			{
                cad[i] -= 32; 
            }
        }
    }

    printf("\n%s\n", cad);
}

void num_letras(char cad[])
{
	int n = tam_cad(cad);

	printf("\nNumero de caracteres de %s: %d\n", cad, n);
}

void inversa(char cad[])
{
	int n = tam_cad(cad);
	
	printf("\n");

	for(int i = n; i >= 0 ; i--)
	{	
		printf("%c", cad[i]);
	}
	
	printf("\n");
}

void sin_espacios(char cad[])
{
    int n = tam_cad(cad);

    char nueva_cad[50];
    int indice_nueva_cad = 0;

    for(int i = 0; i < n; i++)
	{
        if (cad[i] != ' ')
		{
            nueva_cad[indice_nueva_cad] = cad[i];
            indice_nueva_cad++;
        }
    }

    nueva_cad[indice_nueva_cad] = '\0';

    printf("\n%s\n", nueva_cad);
}

void validar(char cad[]) 
{
    int n = tam_cad(cad);
    char nueva_cad[50];
    int indice_nueva_cad = 0;
    int espacio_consecutivo = 0;

    for (int i = 0; i < n; i++)
	{
        if ((cad[i] >= 'A' && cad[i] <= 'Z') || (cad[i] >= 'a' && cad[i] <= 'z'))
		{
            nueva_cad[indice_nueva_cad] = cad[i];
            indice_nueva_cad++;
            espacio_consecutivo = 0; 
        }
		
		else
		{
            if(cad[i] == ' ')
			{
                if(!espacio_consecutivo)
				{
                    nueva_cad[indice_nueva_cad] = cad[i];
                    indice_nueva_cad++;
                    espacio_consecutivo = 1; 
                }
            }
        }
    }

    if (nueva_cad[indice_nueva_cad - 1] == ' ')
	{
        indice_nueva_cad--;
    }

    nueva_cad[indice_nueva_cad] = '\0';

    printf("\n%s\n", nueva_cad);
}


void mix(char cad[])
{
	int n = tam_cad(cad);

    for (int i = 0; i < n; i++)
	{
        if (cad[i] >= 'a' && cad[i] <= 'z')
		{
            cad[i] -= 32;
        }
    }

    printf("\nMAYUSCULAS: %s\n", cad);


    for (int i = 0; i < n; i++)
	{
        if (cad[i] >= 'A' && cad[i] <= 'Z')
		{
            cad[i] += 32;
        }
    }

    printf("\n MINUSCULAS: %s\n", cad);

    for (int i = 0; i < n; i++) {
        if (cad[i] >= 'A' && cad[i] <= 'Z')
		{
            cad[i] += 32;
        }
    }

    for (int i = 0; i < n; i++)
	{
        if (i == 0 || cad[i - 1] == ' ')
		{
            if (cad[i] >= 'a' && cad[i] <= 'z')
			{
                cad[i] -= 32; 
            }
        }
    }

    printf("\n CAPITAL: %s\n", cad);


    char nueva_cad[50];
    int indice_nueva_cad = 0;

    for(int i = 0; i < n; i++)
	{
        if (cad[i] != ' ')
		{
            nueva_cad[indice_nueva_cad] = cad[i];
            indice_nueva_cad++;
        }
    }

    nueva_cad[indice_nueva_cad] = '\0';

    printf("\nSIN ESPACIOS: %s\n", nueva_cad);

	printf("\n AL REVES:");

	for(int i = n; i >= 0 ; i--)
	{	
		printf("%c", cad[i]);
	}
	
	printf("\n");

}


void palindromo(char cad[])
{
    int n = 0;
    for (int i = 0; cad[i] != '\0'; i++) {
        if (isalpha(cad[i])) {
            cad[n++] = toupper(cad[i]);
        } else if (cad[i] == ' ' && (i == 0 || cad[i - 1] != ' ')) {
            cad[n++] = ' ';
        }
    }
    cad[n] = '\0';

    int inicio = 0, fin = n - 1;
    while (inicio < fin) {
        if (cad[inicio] != cad[fin]) {
            printf("\"%s\" no es palindromo\n", cad);
            return;
        }
        inicio++;
        fin--;
    }
    printf("\"%s\" es palindromo\n", cad);
}