// CYNDY ALEJANDRA MIRANDA LARA
// DESC: realizar un programa con 9 salidas distintas de la palabra ENSENADA
// Fecha: 12/03/2024 terminado: 16/03/2024
// CAML_ACT07_01.cpp

#include <stdio.h>
#include <stdlib.h>



//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void leer_cadena(char cad[]);
void imp_original(char cad[]); //1
void imp_salto(char cad[]); //2
void imp_rev(char cad[]); //3
int tam_cad(char cad[]);
void imp_salto_rev(char cad[]); //4
void imp_incomp_fin(char cad[]); //5
void imp_incomp_rev_inicio(char cad[]); //6
void imp_incomp_inicio(char cad[]); //7
void imp_incomp_rev_fin(char cad[]); //8
void sin_vocales(char cad[]); //9
void sin_consonantes(char cad[]); //10


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
    printf("1.- SALIDA 1 \n");
    printf("2.- SALIDA 2 \n");
    printf("3.- SALIDA 3 \n");
    printf("4.- SALIDA 4 \n");
    printf("5.- SALIDA 5 \n");
    printf("6.- SALIDA 6 \n");
    printf("7.- SALIDA 7 \n");
    printf("8.- SALIDA 8 \n");
    printf("9.- SALIDA 9 \n");
    printf("10.- SALIDA 10 \n");
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
		imp_original(cad);
              break;
        case 2:
		imp_rev(cad);
              break;
        case 3:
		imp_salto(cad);
              break;
        case 4:
		imp_salto_rev(cad);
              break;
        case 5:
		imp_incomp_fin(cad);
              break;
        case 6:
		imp_incomp_rev_inicio(cad);
              break;
        case 7:
		imp_incomp_inicio(cad);
              break;
		case 8:
		imp_incomp_rev_fin(cad);
			  break;
		case 9:
		sin_vocales(cad);
			  break;
		case 10:
		sin_consonantes(cad);
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

void imp_original(char cad[]) //1
{
	printf("\n\n%s\n\n", cad);
}

void imp_rev(char cad[]) //2
{
	int n = tam_cad(cad);
	
	printf("\n");

	for(int i = n; i >= 0 ; i--)
	{	
		printf("%c", cad[i]);
	}
	
	printf("\n");
}

void imp_salto(char cad[]) //3
{
	int n = tam_cad(cad);
	
	for(int i = 0; i <= n ; i++)
	{	
		printf("%c \n", cad[i]);
	}
	
	printf("\n");
}


void imp_salto_rev(char cad[]) //4
{
	int n = tam_cad(cad);

	printf("\n");
	
	for(int i = n; i >= 0 ; i--)
	{	
		printf("%c \n", cad[i]);
	}
	
	printf("\n");
}

void imp_incomp_fin(char cad[]) 
{
    int n = tam_cad(cad); 
    printf("\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < (n - i); j++)
        {
            printf("%c", cad[j]);
        }
        printf("\n");
    }
    
    printf("\n");
}


void imp_incomp_rev_inicio(char cad[])
{
    int n = tam_cad(cad); 
    printf("\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < (n - i); j++)
        {
            printf("%c", cad[n - j - 1]);
        }
        printf("\n");
    }
    
    printf("\n");
}


void imp_incomp_inicio(char cad[])
{
    int n = tam_cad(cad);
    printf("\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            printf("%c", cad[j]);
        }
        printf("\n");
    }
    
    printf("\n");
}


void imp_incomp_rev_fin(char cad[])
{
    int n = tam_cad(cad);
    printf("\n");

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= i; j--)
        {
            printf("%c", cad[j]);
        }
        printf("\n");
    }

    printf("\n");
}


void sin_vocales(char cad[]) //9
{
	int n = tam_cad(cad); 
	char nueva_cad[50];
	char vocales[] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'}; 

	printf("\n");

	int indice_nueva_cad = 0; 

    for (int i = 0; i < n; i++)
	{
        int es_vocal = 0; 
        for(int j = 0; j < 10; j++)
		{
            if(cad[i] == vocales[j])
			{
                es_vocal = 1; 
                break; 
            }
        }

        if (!es_vocal)
		{
            nueva_cad[indice_nueva_cad] = cad[i];
            indice_nueva_cad++; 
        }
    }

    nueva_cad[indice_nueva_cad] = '\0';

    printf("%s\n", nueva_cad);

	printf("\n");

}


void sin_consonantes(char cad[])
{
    int n = tam_cad(cad); 
    char nueva_cad[50];
    char consonantes[] = {'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'X', 'Y', 'Z', 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'x', 'y', 'z'}; 

    printf("\n");

    int indice_nueva_cad = 0; 

    for (int i = 0; i < n; i++)
    {
        int es_consonante = 0; 
        for(int j = 0; j < 42; j++)
        {
            if(cad[i] == consonantes[j])
            {
                es_consonante = 1; 
                break; 
            }
        }

        if (!es_consonante)
        {
            nueva_cad[indice_nueva_cad] = cad[i];
            indice_nueva_cad++; 
        }
    }

    nueva_cad[indice_nueva_cad] = '\0';

    printf("%s\n", nueva_cad);

    printf("\n");
}