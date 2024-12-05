#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float tiempos;
} Datos;

// Prototipos
int msges();
void menu();
void cargar(Datos datos[], int *num_datos);
void imprimir(Datos datos[], int *num_datos);
void media(Datos datos[], int *num_datos);
void mediana(Datos datos[], int *num_datos);

int msges() {
    system("cls");
    int op;
    printf("\n M E N U \n");
    printf("1. Cargar muestra \n");
    printf("2. Imprimir muestra \n");
    printf("3. Media \n");
    printf("4. Mediana\n");
    printf("0. S A L I R \n");
    printf("\nSelecciona una opcion ->: ");
    scanf("%d", &op);
    while(getchar() != '\n');
    return op;
}

void menu() {
    int op;
    Datos datos[50];
    int num_datos = 0; 

    do {
        op = msges();

        switch(op) {
            case 1:
                cargar(datos, &num_datos); 
                break;
            case 2:
                imprimir(datos, &num_datos); 
                break;
            case 3:
                media(datos, &num_datos);
                break;
            case 4:
                mediana(datos, &num_datos);
                break;
        }
    } while(op != 0);
}

void cargar(Datos datos[], int *num_datos)
{ 
    FILE *archivo;
    archivo = fopen("tiempos_5k_teem_potros.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }

    int i = 0;
    while (fscanf(archivo, "%f", &datos[i].tiempos) == 1)
    { 
        i++;
        (*num_datos)++;
    }

    fclose(archivo);
    printf("Datos cargados\n");
    system("pause");
}

void imprimir(Datos datos[], int *num_datos)
{

        FILE *archivo;
        archivo = fopen("tiempos_5k_teem_potros.txt", "r");
        if (archivo == NULL) {
            printf("Error al abrir el archivo\n");
            return;
        }

        printf("Datos cargados:\n");

        for (int i = 0; i < *num_datos; i++) {
            float valor;
            if (fscanf(archivo, "%f", &valor) == 1) 
            {
                printf("%.2f\n", valor);
            }
            else
            {
                printf("Error al leer el archivo\n");
                break;
            }
        }

        fclose(archivo);

    system("pause");
}

void media(Datos datos[], int *num_datos)
{
    printf("\n Media aritmetica \n");

    float acum = 0.0;

    for(int i = 0; i < *num_datos; i++)
    {
        acum += datos[i].tiempos;
    }

    float media = acum / *num_datos;
    printf("La media es %.2f\n", media);

    system("pause");
}


void mediana(Datos datos[], int *num_datos)
{
    printf("\n Mediana \n");

    for(int i = 0; i < *num_datos - 1; i++)
    {
        for(int j = 0; j < *num_datos - i - 1; j++)
        {
            if(datos[j].tiempos > datos[j+1].tiempos)
            {
                float temp = datos[j].tiempos;
                datos[j].tiempos = datos[j+1].tiempos;
                datos[j+1].tiempos = temp;
            }
        }
    }

    float mediana;
    if (*num_datos % 2 == 0) 
    {
        mediana = (datos[*num_datos / 2 - 1].tiempos + datos[*num_datos / 2].tiempos) / 2.0;
    }
    else 
    {
        mediana = datos[*num_datos / 2].tiempos;
    }

    printf("La mediana es %.2f\n", mediana);
    system("pause");

    
}
