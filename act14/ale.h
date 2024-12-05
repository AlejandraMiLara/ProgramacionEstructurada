// CYNDY ALEJANDRA MIRANDA LARA
// DESC: Archivos indexados
// Fecha terminado: 24/05/2024
// CAML_ACT14_01.cpp

typedef struct
{
    int matricula;
    int indice;
    int status;
} Persona;

void menu();
int msges();
int verifica_matricula(Persona personas[], int registros);
void cargar_inicializacion(Persona personas[], int *registros);
void cargar(Persona personas[], int *registros);
void buscar(Persona personas[], int registros);
int bsq_secuencial(Persona personas[], int registros, int buscado);
int bsq_binaria(Persona personas[], int registros, int buscado);
void eliminar(Persona personas[], int registros, int ordenado);
void ordenar(Persona personas[], int *registros, int *ordenado);
void quicksort(Persona personas[], int izq, int der);
void mergesort(Persona personas[], int inicio, int fin);
void merge(Persona personas[], int inicio, int medio, int fin);
void heapsort(Persona personas[], int n);
void heapify(Persona personas[], int n, int i);
void mostrar(int ordenado);
void generar_archtxt(Persona personas[], int registros, int ordenado);
void empaquetar(Persona personas[], int registros);

void menu()
{
    int op;

    Persona personas[1500];
    int registros = 0;
    int ordenado = 0;

    cargar_inicializacion(personas, &registros);

    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            cargar(personas, &registros);
            break;
        case 2:
            eliminar(personas, registros, ordenado);
            break;
        case 3:
            buscar(personas, registros);
            break;
        case 4:
            ordenar(personas, &registros, &ordenado);
            break;
        case 5:
            generar_archtxt(personas, registros, ordenado);
            break;
        case 6:
            mostrar(ordenado);
            break;
        case 7:
            empaquetar(personas, registros);
            break;
        case 0:
            printf("Salir\n");
            system("pause");
            break;
        default:
            printf("Opcion invalida\n");
            system("pause");
            break;
        }
    } while (op != 0);
}

int msges()
{
    system("cls");
    int op;
    printf("\n M  E  N  U: \n");
    printf("1. Cargar\n");
    printf("2. Eliminar\n");
    printf("3. Buscar\n");
    printf("4. Ordenar\n");
    printf("5. Generar archivo\n");
    printf("6. Mostrar\n");
    printf("7. Empaquetar\n");
    printf("0. S A L I R\n");
    printf("Ingrese una opcion ->: ");
    scanf("%d", &op);
    while (getchar() != '\n')
        ;
    return op;
}

void cargar(Persona personas[], int *registros)
{
    system("cls");
    printf("\n Se ha cargado un elemento a la estructura automaticamente... \n");

    if (*registros < 1500)
    {
        int matricula = verifica_matricula(personas, *registros);

        personas[*registros].matricula = matricula;
        personas[*registros].indice = *registros;
        personas[*registros].status = 1;

        FILE *archivo = fopen("registros.dat", "rb+");
        if (!archivo)
        {
            archivo = fopen("registros.dat", "wb+");
            if (!archivo)
            {
                printf("\n Error: Imposible acceder al archivo. \n");
                system("pause");
                return;
            }
        }

        fseek(archivo, 0, SEEK_END);
        fwrite(&personas[*registros], sizeof(Persona), 1, archivo);
        fclose(archivo);

        (*registros)++;
        printf("\nElemento cargado correctamente.\n");
        system("pause");
    }
    else
    {
        printf("\n Error: Ya no hay mas espacio para utilizar \n");
        system("pause");
    }
}

int verifica_matricula(Persona personas[], int registros)
{
    int repetido;
    int matricula;

    do
    {
        repetido = 0;
        matricula = rand() % 5000 + 5000;

        for (int i = 0; i < registros; i++)
        {
            if (personas[i].matricula == matricula)
            {
                repetido = 1;
                break;
            }
        }
    } while (repetido);

    return matricula;
}

void cargar_inicializacion(Persona personas[], int *registros)
{
    for (int i = 0; i < 1000; i++)
    {
        int matricula = verifica_matricula(personas, *registros);
        personas[*registros].matricula = matricula;
        personas[*registros].indice = i;
        personas[*registros].status = (i < 700) ? 1 : 0;
        (*registros)++;
    }

    FILE *archivo = fopen("registros.dat", "wb");
    if (!archivo)
    {
        printf("\n Error: Imposible acceder al archivo. \n");
        system("pause");
        return;
    }

    fwrite(personas, sizeof(Persona), *registros, archivo);
    fclose(archivo);

    printf("\n Se ha creado y cargado el archivo automaticamente \n\n");
    system("pause");
}

void buscar(Persona personas[], int registros)
{
    system("cls");
    int valido = 0;
    int busqueda;

    do
    {
        int buscado;
        printf("\n Buscar por matricula\n\n Ingresa la matricula que deseas buscar \n ->:");
        scanf("%d", &buscado);
        while (getchar() != '\n')
            ;

        if (buscado <= 4999)
        {
            valido = 0;
            printf("\n BUSQUEDA FUERA DE RANGO \n");
            system("pause");
            break;
        }

        if (registros < 1250)
        {
            busqueda = bsq_secuencial(personas, registros, buscado);

            if (busqueda)
            {
                valido = 1;
                printf("\n ENCONTRADA \n");
                printf("Matricula: %d\nIndice: %d\nStatus: %d\n", personas[busqueda].matricula, personas[busqueda].indice, personas[busqueda].status);
                system("pause");
                break;
            }
            else
            {
                valido = 0;
                printf("\n NO ENCONTRADA \n");
                system("pause");
                break;
            }
        }
        else
        {
            busqueda = bsq_binaria(personas, registros, buscado);

            if (busqueda)
            {
                valido = 1;
                printf("\n ENCONTRADA \n");
                printf("Matricula: %d\nIndice: %d\nStatus: %d\n", personas[busqueda].matricula, personas[busqueda].indice, personas[busqueda].status);
                system("pause");
                break;
            }
            else
            {
                valido = 0;
                printf("\n NO ENCONTRADA \n");
                system("pause");
                break;
            }
        }
    } while (!valido);
}

int bsq_secuencial(Persona personas[], int registros, int buscado)
{
    for (int i = 0; i < registros; i++)
    {
        if (personas[i].matricula == buscado)
        {
            return i;
        }
    }
    return -99;
}

int bsq_binaria(Persona personas[], int registros, int buscado)
{
    int izquierda = 0, derecha = registros - 1;
    while (izquierda <= derecha)
    {
        int medio = izquierda + (derecha - izquierda) / 2;
        if (personas[medio].matricula == buscado)
        {
            return medio;
        }
        if (personas[medio].matricula < buscado)
        {
            izquierda = medio + 1;
        }
        else
        {
            derecha = medio - 1;
        }
    }
    return -99;
}

void ordenar(Persona personas[], int *registros, int *ordenado)
{
    system("cls");
    printf("\n Intentando ordenar... \n");

    if (!(*ordenado))
    {
        if (*registros < 1200)
        {
            mergesort(personas, 0, *registros - 1);
        }
        else
        {
            if (*registros < 1400)
            {
                heapsort(personas, *registros);
            }
            else
            {
                quicksort(personas, 0, *registros - 1);
            }
        }

        printf("\n La estructura fue ordenada correctamente \n");
        *ordenado = 1;

        FILE *archivo = fopen("registros_ord.dat", "wb");
        if (!archivo)
        {
            printf("\n Error: Imposible acceder al archivo. \n");
            system("pause");
            return;
        }

        fwrite(personas, sizeof(Persona), *registros, archivo);
        fclose(archivo);

        system("pause");
    }
    else
    {
        printf("\n La estructura ya habia sido ordenada previamente... \n");
        system("pause");
    }
}

void quicksort(Persona personas[], int izq, int der)
{
    int i = izq, j = der;
    int pivote = personas[(izq + der) / 2].matricula;

    while (i <= j)
    {
        while (personas[i].matricula < pivote)
            i++;
        while (personas[j].matricula > pivote)
            j--;
        if (i <= j)
        {
            Persona temp = personas[i];
            personas[i] = personas[j];
            personas[j] = temp;
            i++;
            j--;
        }
    }

    if (izq < j)
        quicksort(personas, izq, j);
    if (i < der)
        quicksort(personas, i, der);
}

void mergesort(Persona personas[], int inicio, int fin)
{
    if (inicio < fin)
    {
        int medio = (inicio + fin) / 2;
        mergesort(personas, inicio, medio);
        mergesort(personas, medio + 1, fin);
        merge(personas, inicio, medio, fin);
    }
}

void merge(Persona personas[], int inicio, int medio, int fin)
{
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;

    Persona izquierda[n1], derecha[n2];

    for (int i = 0; i < n1; i++)
        izquierda[i] = personas[inicio + i];
    for (int j = 0; j < n2; j++)
        derecha[j] = personas[medio + 1 + j];

    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2)
    {
        if (izquierda[i].matricula <= derecha[j].matricula)
        {
            personas[k] = izquierda[i];
            i++;
        }
        else
        {
            personas[k] = derecha[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        personas[k] = izquierda[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        personas[k] = derecha[j];
        j++;
        k++;
    }
}

void heapsort(Persona personas[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(personas, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        Persona temp = personas[0];
        personas[0] = personas[i];
        personas[i] = temp;

        heapify(personas, i, 0);
    }
}

void heapify(Persona personas[], int n, int i)
{
    int mayor = i;
    int izq = 2 * i + 1;
    int der = 2 * i + 2;

    if (izq < n && personas[izq].matricula > personas[mayor].matricula)
        mayor = izq;

    if (der < n && personas[der].matricula > personas[mayor].matricula)
        mayor = der;

    if (mayor != i)
    {
        Persona temp = personas[i];
        personas[i] = personas[mayor];
        personas[mayor] = temp;

        heapify(personas, n, mayor);
    }
}

void mostrar(int ordenado)
{
    int opc;
    system("cls");
    printf("\nMostrar registros:\n");
    printf("1. Mostrar registros en orden normal\n");
    printf("2. Mostrar registros ordenados\n");
    printf("Seleccione una opcion ->: ");
    scanf("%d", &opc);

    if (opc == 2) // ord
    {
        if (ordenado == 0)
        {
            printf("\n Error: Antes de mostrar los registros ordenados, primero ordene la estructura. \n");
            system("pause");
            return;
        }
        else
        {
            FILE *archivo = fopen("registros_ord.dat", "rb");
            if (!archivo)
            {
                printf("\n Error: No se puede acceder al archivo de registros ordenados. \n");
                system("pause");
                return;
            }

            printf("\nMatricula\tIndice\tStatus\n");
            Persona temp;
            while (fread(&temp, sizeof(Persona), 1, archivo))
            {
                printf("%d\t\t%d\t%d\n", temp.matricula, temp.indice, temp.status);
            }

            fclose(archivo);

            system("pause");
        }
    }
    else // desord
    {
        FILE *archivo = fopen("registros.dat", "rb");
        if (!archivo)
        {
            printf("\nError: No se puede acceder al archivo de registros.\n");
            system("pause");
            return;
        }

        printf("\nMatricula\tIndice\tStatus\n");
        Persona temp;
        while (fread(&temp, sizeof(Persona), 1, archivo))
        {
            printf("%d\t\t%d\t%d\n", temp.matricula, temp.indice, temp.status);
        }

        fclose(archivo);

        system("pause");
    }

    if (opc != 1 && opc != 2)
    {
        printf("\n Opcion invalida \n");
        system("pause");
    }
}

void eliminar(Persona personas[], int registros, int ordenado)
{
    int valido = 0;
    int busqueda;

    do
    {
        int buscado;
        printf("\n Eliminar registro por matricula\n\nIngrese la matricula del registro a eliminar ->: ");
        scanf("%d", &buscado);
        while (getchar() != '\n');

        if(buscado <= 4999)
        {
            printf("\n Error: Matricula invalida \n");
            system("pause");
            break;
        }

        if (registros < 1250)
        {
            busqueda = bsq_secuencial(personas, registros, buscado);
        }
        else
        {
            busqueda = bsq_binaria(personas, registros, buscado);
        }

        if (busqueda != -99)
        {
            valido = 1;
            printf("\nRegistro encontrado:\n");
            printf("Matricula: %d\nIndice: %d\nStatus: %d\n", personas[busqueda].matricula, personas[busqueda].indice, personas[busqueda].status);

            personas[busqueda].status = 0;

            FILE *archivo_registros = fopen("registros.dat", "rb+");
            if (!archivo_registros)
            {
                printf("\nError: No se puede acceder al archivo de registros.\n");
                system("pause");
                return;
            }
            fseek(archivo_registros, sizeof(Persona) * busqueda, SEEK_SET);
            fwrite(&personas[busqueda], sizeof(Persona), 1, archivo_registros);
            fclose(archivo_registros);

            if (ordenado)
            {
                FILE *archivo_registros_ord = fopen("registros_ord.dat", "rb+");
                if (!archivo_registros_ord)
                {
                    printf("\nError: No se puede acceder al archivo de registros ordenados.\n");
                    system("pause");
                    return;
                }
                fseek(archivo_registros_ord, sizeof(Persona) * busqueda, SEEK_SET);
                fwrite(&personas[busqueda], sizeof(Persona), 1, archivo_registros_ord);
                fclose(archivo_registros_ord);
            }

            printf("\n Registro eliminado correctamente \n");
            system("pause");
        }
        else
        {
            valido = 0;
            printf("\n No se encontro ningun registro con esa matricula \n");
            system("pause");
            break;
        }
    } while (!valido);
}

void generar_archtxt(Persona personas[], int registros, int ordenado)
{
    char nombre_archivo[100];
    int opc;

    printf("Ingrese el nombre del archivo a generar (sin extension)->:  ");
    scanf("%s", nombre_archivo);
    strcat(nombre_archivo, ".txt");

    printf("\nDesea los registros en orden o normal?\n");
    printf("1. Normal\n");
    printf("2. Ordenado\n");
    printf("Ingrese una opcion ->: ");
    scanf("%d", &opc);
    while (getchar() != '\n');

    if (opc == 1)
    {
        FILE *archivo_txt = fopen(nombre_archivo, "w");
        if (!archivo_txt)
        {
            printf("\nError: No se pudo crear el archivo de texto\n");
            system("pause");
            return;
        }

        FILE *archivo_bin = fopen("registros.dat", "rb");
        if (!archivo_bin)
        {
            printf("\nError: No se pudo abrir el archivo binario\n");
            fclose(archivo_txt);
            system("pause");
            return;
        }

        fprintf(archivo_txt, "Matricula\tIndice\tStatus\n");
        for (int i = 0; i < registros; i++)
        {
            if (personas[i].status == 1)
            {
                fprintf(archivo_txt, "%d\t%d\t%d\n", personas[i].matricula, personas[i].indice, personas[i].status);
            }
        }

        fclose(archivo_bin);
        fclose(archivo_txt);

        printf("\nArchivo de texto '%s' generado correctamente\n", nombre_archivo);
    }
    else
    {
        if (opc == 2)
        {
            if (!ordenado)
            {
                printf("\nError: La estructura no esta ordenada. Ordena la estructura antes de generar el archivo de texto ordenado \n");
            }
            else
            {
                FILE *archivo_txt = fopen(nombre_archivo, "w");
                if (!archivo_txt)
                {
                    printf("\nError: No se pudo crear el archivo de texto \n");
                    system("pause");
                    return;
                }

                FILE *archivo_bin = fopen("registros_ord.dat", "rb");
                if (!archivo_bin)
                {
                    printf("\nError: No se pudo abrir el archivo binario \n");
                    fclose(archivo_txt);
                    system("pause");
                    return;
                }

                fprintf(archivo_txt, "Matricula\tIndice\tStatus\n");
                for (int i = 0; i < registros; i++)
                {
                    if (personas[i].status == 1)
                    {
                        fprintf(archivo_txt, "%d\t%d\t%d\n", personas[i].matricula, personas[i].indice, personas[i].status);
                    }
                }

                fclose(archivo_bin);
                fclose(archivo_txt);

                printf("\nArchivo de texto '%s' generado correctamente \n", nombre_archivo);
            }
        }
        else
        {
            printf("\nOpcion invalida \n");
        }
    }

    system("pause");
}

void empaquetar(Persona personas[], int registros)
{
    system("cls");
    printf("Empaquetando registros...\n");

    FILE *archivo_empaquetado = fopen("empaquetado.dat", "wb");
    if (archivo_empaquetado == NULL)
    {
        printf("Error al crear el archivo empaquetado.dat\n");
        return;
    }

    for (int i = 0; i < registros; i++)
    {
        if (personas[i].status == 1)
        {
            fwrite(&personas[i], sizeof(Persona), 1, archivo_empaquetado);
        }
    }

    fclose(archivo_empaquetado);

    printf("\nArchivo empaquetado.dat creado correctamente\n");
    system("pause");
}