// CYNDY ALEJANDRA MIRANDA LARA
// DESC: STRUCT Y CURP
// Fecha: 03/05/2024 terminado: 04/05/2024
// CAML_ACT12_01.cpp

typedef struct
{
    int status;
    int matricula;
} Alumno;

typedef struct
{
    char primer_nombre[100];
    char segundo_nombre[100];
    char apellido_paterno[100];
    char apellido_materno[100];
    int edad;
    char genero[5];
    Alumno alumno;
} Persona;

// PROTITPOS
void menu();
int msges();
void cargar(Persona personas[], int *bandera_totalreg, int bandera_ordenado, int *bandera_cargado);
void agregar(Persona personas[], int *bandera_totalreg, int bandera_ordenado, char apellidos_generico[][15], char nombres_mujer_generico[][15], char nombres_hombre_generico[][15]);
void eliminar(Persona personas[], int *bandera_totalreg, int bandera_ordenado);
void buscar(Persona personas[], int bandera_totalreg, int bandera_ordenado);
void ordenar(Persona personas[], int bandera_totalreg, int *bandera_ordenado);
void imprimir(Persona personas[], int bandera_totalreg);
void archivo(Persona personas[], int bandera_totalreg);

int validar_archivo(char nombre[]);
int retorna_matricula(Persona personas[], int bandera_totalreg, int bandera_ordenado, int matricula, int modo);
void qs(int array[], int inicio, int final, int *bandera_ordenado);
void bubblesort(int array[], int tam, int *bandera_ordenado);
int busq(Persona personas[], int bandera_totalreg, int bandera_ordenado, int buscado, int modo_bus);

// FUNCIONES
void menu()
{
    int op;
    int bandera_totalreg = 0;
    int bandera_ordenado = 0;
    int bandera_cargado = 0;

    Persona personas[1500];

    char apellidos_generico[50][15] =
        {
            "Gonzalez", "Rodriguez", "Perez", "Lopez", "Martinez", "Hernandez", "Gomez", "Fernandez", "Diaz", "Torres",
            "Vazquez", "Ramos", "Alvarez", "Castillo", "Ruiz", "Sanchez", "Ramirez", "Moreno", "Delgado", "Romero",
            "Navarro", "Ortiz", "Mendoza", "Vargas", "Castro", "Luna", "Villalobos", "Molina", "Aguilar", "Herrera",
            "Silva", "Gallardo", "Cortes", "Pacheco", "Reyes", "Medina", "Guzman", "Salazar", "Pena", "Vega", "Galindo",
            "Maldonado", "Campos", "Rojas", "Benitez", "Fuentes", "Valencia", "Pineda", "Cervantes"};

    char nombres_mujer_generico[50][15] =
        {
            "Mariana", "Laura", "Carmen", "Ana", "Isabel", "Sofia", "Patricia", "Luisa", "Diana", "Elena",
            "Lucia", "Paula", "Marta", "Rosa", "Clara", "Teresa", "Eva", "Beatriz", "Monica", "Pilar",
            "Natalia", "Lorena", "Lourdes", "Silvia", "Dolores", "Julia", "Cristina", "Alejandra", "Marina",
            "Gloria", "Adriana", "Rocio", "MariaJose", "Victoria", "Angela", "Ines", "Raquel", "Miriam",
            "Alicia", "Sara", "Virginia", "Cecilia", "Patrocinio", "Regina", "Esther", "Margarita", "Antonia",
            "Fabiola", "Celia", "Mireya"};

    char nombres_hombre_generico[50][15] =
        {
            "Juan", "Carlos", "Pedro", "Jacinto", "Fabian", "Manuel", "Antonio", "Francisco", "Javier", "Miguel",
            "Angel", "Fernando", "Ricardo", "Diego", "Daniel", "Alberto", "Adrian", "Alejandro", "Roberto",
            "Guillermo", "Jesus", "Rafael", "Oscar", "Ramon", "Sergio", "Eduardo", "Mario", "Victor", "Jorge",
            "Pablo", "Andres", "Emilio", "Mariano", "Ignacio", "Hector", "Alfredo", "Israel", "Bruno", "Felipe",
            "Gonzalo", "Raul", "Cesar", "Leonardo", "Rodrigo", "Gustavo", "Samuel", "Joaquin", "Feliciano",
            "Ernesto", "Enrique"};

    do
    {
        op = msges();

        switch (op)
        {
        case 1:
            cargar(personas, &bandera_totalreg, bandera_ordenado, &bandera_cargado);
            break;
        case 2:
            agregar(personas, &bandera_totalreg, bandera_ordenado, apellidos_generico, nombres_mujer_generico, nombres_hombre_generico);
            break;
        case 3:
            eliminar(personas, &bandera_totalreg, bandera_ordenado);
            break;
        case 4:
            buscar(personas, bandera_totalreg, bandera_ordenado);
            break;
        case 5:
            ordenar(personas, bandera_totalreg, &bandera_ordenado);
            break;
        case 6:
            imprimir(personas, bandera_totalreg);
            break;
        case 7:
            archivo(personas, bandera_totalreg);
            break;
        }

    } while (op != 0);
}

int msges()
{
    system("cls");
    int op;
    printf("\n");
    printf("   M  E   N   U \n");
    printf("1.- CARGAR DESDE ARCHIVO \n");
    printf("2.- AGREGAR REGISTROS \n");
    printf("3.- ELIMINAR \n");
    printf("4.- BUSCAR \n");
    printf("5.- ORDENAR \n");
    printf("6.- MOSTRAR TODO \n");
    printf("7.- GENERAR ARCHIVO NUEVO\n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    while (getchar() != '\n');
    return op;
}

void cargar(Persona personas[], int *bandera_totalreg, int bandera_ordenado, int *bandera_cargado) {
    if (!*bandera_cargado) {
        FILE *archivo = fopen("datos.txt", "r");
        if (archivo == NULL) {
            printf("Error al abrir el archivo.\n");
            system("pause");
            return;
        }
        char temp[256];
        int cargado = 0;

        while (fgets(temp, 256, archivo) != NULL)
        {
            int status, matricula, edad;
            char apellido_paterno[50], apellido_materno[50], primer_nombre[50], segundo_nombre[50], genero;
            sscanf(temp, "%d %d %s %s %s %s %d %c",
                   &status, &matricula, apellido_paterno, apellido_materno, primer_nombre, segundo_nombre, &edad, &genero);

            personas[*bandera_totalreg].alumno.status = status;
            personas[*bandera_totalreg].alumno.matricula = matricula;
            strcpy(personas[*bandera_totalreg].apellido_paterno, apellido_paterno);
            strcpy(personas[*bandera_totalreg].apellido_materno, apellido_materno);
            strcpy(personas[*bandera_totalreg].primer_nombre, primer_nombre);
            strcpy(personas[*bandera_totalreg].segundo_nombre, segundo_nombre);
            personas[*bandera_totalreg].edad = edad;
            strcpy(personas[*bandera_totalreg].genero, &genero);

            (*bandera_totalreg)++;
            cargado++;
        }
        fclose(archivo);
        *bandera_cargado = 1;
        printf("\nElementos ingresados con exito: %d\n", cargado);
        system("pause");
    }
    else
    {
        printf("\nDenegado: El archivo solo puede ser cargado en la estructura UNA VEZ\n");
        system("pause");
    }
}

void agregar(Persona personas[], int *bandera_totalreg, int bandera_ordenado, char apellidos_generico[][15], char nombres_mujer_generico[][15], char nombres_hombre_generico[][15])
{
    printf("\n Elementos ingresados hasta el momento: %d \n", *bandera_totalreg);

    if (*bandera_totalreg >= 2000)
    {
        printf("\n Ya no hay espacio disponible. \n");
        system("pause");
    }
    else
    {
        int cargar = 0;
        int limite = 1500 - *bandera_totalreg;
        int valido = 0;

        do
        {
            valido = 1;

            cargar = 10;

            if ((*bandera_totalreg + cargar) > 1500)
            {
                printf("\n No puedes cargar: %d. Limite: %d \n", cargar, limite);
                valido = 0;
                break;
            }

            if (cargar < 1)
            {
                printf("\n Ingresa un numero valido \n");
                valido = 0;
                break;
            }

            for (int i = *bandera_totalreg; i < *bandera_totalreg + cargar; i++)
            {
                personas[i].alumno.status = 1;
                personas[i].edad = 17 + rand() % 83;

                strcpy(personas[i].apellido_paterno, apellidos_generico[rand() % 49]);
                strcpy(personas[i].apellido_materno, apellidos_generico[rand() % 49]);

                int valido_matricula = 0;
                do
                {
                    personas[i].alumno.matricula = 300000 + rand() % 700000;
                    valido_matricula = retorna_matricula(personas, *bandera_totalreg, 0, personas[i].alumno.matricula, 0);
                } while (valido_matricula != -1);

                int genero = 1 + rand() % 2;

                if (genero == 1)
                {
                    strcpy(personas[i].genero, "M");
                    strcpy(personas[i].primer_nombre, nombres_mujer_generico[rand() % 50]);
                    strcpy(personas[i].segundo_nombre, nombres_mujer_generico[rand() % 50]);
                }
                else
                {
                    strcpy(personas[i].genero, "H");
                    strcpy(personas[i].primer_nombre, nombres_hombre_generico[rand() % 50]);
                    strcpy(personas[i].segundo_nombre, nombres_hombre_generico[rand() % 50]);
                }

                FILE *archivo = fopen("datos.txt", "a");

                if (archivo != NULL)
                {
                    fprintf(archivo, "%d %d %s %s %s %s %d %s\n",
                            &personas[i].alumno.status,
                            &personas[i].alumno.matricula,
                            personas[i].apellido_paterno,
                            personas[i].apellido_materno,
                            personas[i].primer_nombre,
                            personas[i].segundo_nombre,
                            &personas[i].edad,
                            personas[i].genero);
                    fclose(archivo);
                }
                else
                {
                    printf("\n Error al actualizar archivo \n");
                    system("pause");
                }
            }

            *bandera_totalreg += cargar;
            printf("\n Elementos ingresados con exito: %d \n", cargar);
            system("pause");
        } while (!valido);
    }
}

void eliminar(Persona personas[], int *bandera_totalreg, int bandera_ordenado)
{
    system("cls");

    int valido = 0;
    do
    {
        valido = 1;
        int confirmado = 0;
        int matricula;

        printf("\n Ingresa la matricula a ELIMINAR: \n\n");
        scanf("%d", &matricula);
        while (getchar() != '\n')
            ;

        system("cls");
        printf("\n Eliminar la matricula: %d \n", matricula);
        printf("\n\n Presiona 0 para CANCELAR\n");
        printf(" Presiona 1 para CONFIRMAR\n");
        scanf("%d", &confirmado);
        while (getchar() != '\n')
            ;

        if (confirmado != 0 && confirmado != 1)
        {
            valido = 0;
            printf("La opcion de CONFIRMACION es invalida");
            system("pause");
            break;
        }

        if (!confirmado)
        {
            break;
        }

        int pos_matr = retorna_matricula(personas, *bandera_totalreg, bandera_ordenado, matricula, 0);

        if (pos_matr < 0)
        {
            valido = 0;
            printf("\nMatricula NO ENCONTRADA...\n");
            system("pause");
            break;
        }
        else
        {
            system("cls");
            valido = 1;
            personas[pos_matr].alumno.status = 0;
            printf("\n Matricula: %d ELIMINADA correctamente \n ", matricula);

            FILE *archivo = fopen("datos.txt", "r+");
            if (archivo == NULL)
            {
                printf("\n Error al abrir el archivo \n");
                system("pause");
                return;
            }

            FILE *temporal = fopen("temporal.txt", "w");
            if (temporal == NULL)
            {
                printf("\n Error al abrir el archivo temporal \n");
                fclose(archivo);
                system("pause");
                return;
            }

            char linea[256];
            while (fgets(linea, sizeof(linea), archivo))
            {
                int matricula_archivo;
                sscanf(linea, "%*d %d", &matricula_archivo);
                if (matricula_archivo != matricula)
                {
                    fputs(linea, temporal);
                }
            }

            fclose(archivo);
            fclose(temporal);

            remove("datos.txt");
            rename("temporal.txt", "datos.txt");

            system("pause");
            (*bandera_totalreg)--;
        }

    } while (!valido);
}

void buscar(Persona personas[], int bandera_totalreg, int bandera_ordenado)
{
    system("cls");
    int valido = 0;
    int matriculas[bandera_totalreg];
    int busqueda;

    do
    {
        int buscado;
        printf("\n Buscar por matricula \n\n Ingresa la matricula que deseas buscar \n ->:");
        scanf("%d", &buscado);
        while (getchar() != '\n');

        if (bandera_ordenado)
        {
            if (bandera_totalreg >= 1000)
            {
                busqueda = busq(personas, bandera_totalreg, bandera_ordenado, buscado, 1);

                if (busqueda)
                {
                    valido = 1;
                    system("pause");
                }
                else
                {
                    valido = 0;
                    system("pause");
                    break;
                }
            }
            else
            {
                int busqueda = busq(personas, bandera_totalreg, bandera_ordenado, buscado, 0);

                if (busqueda)
                {
                    valido = 1;
                }
                else
                {
                    valido = 0;
                    break;
                }
            }
        }
        else
        {
            if (bandera_totalreg > 1000)
            {
                for (int i = 0; i < bandera_totalreg; i++)
                {
                    matriculas[i] = personas[i].alumno.matricula;
                }

                printf("\n AVISO: Para esta busqueda se ordenaran los registros automaticamente.\n");
                qs(matriculas, 0, (bandera_totalreg - 1), &bandera_ordenado); // Corrección aquí
                printf("\n... Se ordenaron correctamente!\n");

                busqueda = busq(personas, bandera_totalreg, bandera_ordenado, buscado, 1);

                if (busqueda)
                {
                    valido = 1;
                    system("pause");
                }
                else
                {
                    valido = 0;
                    system("pause");
                    break;
                }
            }
            else
            {
                busqueda = busq(personas, bandera_totalreg, bandera_ordenado, buscado, 0);

                if (busqueda)
                {
                    valido = 1;
                    system("pause");
                }
                else
                {
                    valido = 0;
                    system("pause");
                    break;
                }
            }
        }

    } while (!valido);
}

void ordenar(Persona personas[], int bandera_totalreg, int *bandera_ordenado)
{
    system("cls");
    int matriculas[bandera_totalreg];
    for (int i = 0; i < bandera_totalreg; i++)
    {
        matriculas[i] = personas[i].alumno.matricula;
    }

    if (!(*bandera_ordenado))
    {
        if (bandera_totalreg >= 1000)
        {
            qs(matriculas, 0, (bandera_totalreg - 1), bandera_ordenado);
            *bandera_ordenado = 1;
            printf("\n... Se ordenaron correctamente!\n");
        }
        else
        {
            bubblesort(matriculas, bandera_totalreg, bandera_ordenado);
            *bandera_ordenado = 1;
            printf("\n... Se ordenaron correctamente!\n");
        }
    }
    else
    {
        printf("\n Los datos ya estan ordenados por matricula \n");
    }

    for (int i = 0; i < bandera_totalreg; i++)
    {
        personas[i].alumno.matricula = matriculas[i];
    }

    system("pause");
}

void imprimir(Persona personas[], int bandera_totalreg)
{
    system("cls");
    printf("\nIMPRESION MODO TABLA\n\n");
    printf("%-8s%-12s%-20s%-20s%-15s%-15s%-8s%s\n",
           "Status", "Matricula", "Apellido Paterno", "Apellido Materno", "Primer Nombre", "Segundo Nombre", "Edad", "Género");

    for (int i = 0; i < bandera_totalreg; i++)
    {
        for (int j = strlen(personas[i].apellido_paterno) - 1; j >= 0; j--) {
            if (!isprint(personas[i].apellido_paterno[j])) {
                personas[i].apellido_paterno[j] = '\0';
            } else {
                break;
            }
        }
        printf("%-8d%-12d", personas[i].alumno.status, personas[i].alumno.matricula);
        printf("%-20s%-20s%-15s%-15s", personas[i].apellido_paterno, personas[i].apellido_materno,
               personas[i].primer_nombre, personas[i].segundo_nombre);
        printf("%-8d%c\n", personas[i].edad, personas[i].genero[0]);
    }
    system("pause");
}


void archivo(Persona personas[], int bandera_totalreg) {
    char nombre[50];
    printf("\nGENERAR ARCHIVOS\n\n");
    printf("Elige el nombre del archivo que quieres crear ->: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';
    fflush(stdin);

    char nombreArchivo[54]; // Tamaño suficiente para almacenar el nombre y la extensión
    snprintf(nombreArchivo, sizeof(nombreArchivo), "%s.txt", nombre); // Concatenar la extensión ".txt" al nombre del archivo

    FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.");
        system("pause");
        return;
    }
    else
    {
        for (int i = 0; i < bandera_totalreg; i++)
        {
            fprintf(archivo, "%d %d %s %s %s %s %d %c\n",
                    personas[i].alumno.status,
                    personas[i].alumno.matricula,
                    personas[i].apellido_paterno,
                    personas[i].apellido_materno,
                    personas[i].primer_nombre,
                    personas[i].segundo_nombre,
                    personas[i].edad,
                    personas[i].genero[0]);
        }
        fclose(archivo);
        printf("Archivo generado correctamente.\n");
        system("pause");
    }
}

int retorna_matricula(Persona personas[], int bandera_totalreg, int bandera_ordenado, int matricula, int modo)
{
    switch (modo)
    {
    case 0:
        for (int i = 0; i < bandera_totalreg; i++)
        {
            if (personas[i].alumno.matricula == matricula && personas[i].alumno.status == 1)
            {
                return i;
            }
        }
        return -1;
        break;

    case 1:
        int inicio = 0;
        int fin;
        int mitad;
        int matriculas[bandera_totalreg];

        for (int i = 0; i < bandera_totalreg; i++)
        {
            matriculas[i] = personas[i].alumno.matricula;
        }

        while (inicio <= fin)
        {
            mitad = (inicio + fin) / 2;
            if (matriculas[mitad] == matricula)
            {
                return mitad + 1;
            }

            if (matricula < matriculas[mitad])
            {
                fin = mitad - 1;
            }
            else
            {
                inicio = mitad + 1;
            }
        }
        return -1;
        break;
    }
}

int busq(Persona personas[], int bandera_totalreg, int bandera_ordenado, int buscado, int modo_bus)
{
    int pos_matr = retorna_matricula(personas, bandera_totalreg, bandera_ordenado, buscado, modo_bus);

    if (pos_matr >= 0)
    {
        printf("\n REGISTRO \n\n");
        printf("MATRICULA: %d \n", personas[pos_matr].alumno.matricula);
        printf("PRIMER NOMBRE: %s \n", personas[pos_matr].primer_nombre);
        printf("SEGUNDO NOMBRE: %s \n", personas[pos_matr].segundo_nombre);
        printf("PRIMER APELLIDO: %s \n", personas[pos_matr].apellido_paterno);
        printf("SEGUNDO APELLIDO: %s \n", personas[pos_matr].apellido_materno);
        printf("EDAD: %d \n", personas[pos_matr].edad);
        char genero[20] = {};
        if (strcmp(personas[pos_matr].genero, "M") == 0)
        {
            strcpy(genero, "MUJER");
        }
        else
        {
            strcpy(genero, "HOMBRE");
        }
        printf("GENERO: %s \n", genero);
        printf("\n\n");
        return 1;
    }
    else
    {
        printf("\n Matricula no encontrada ! \n");
        system("pause");
        return 0;
    }
}

void bubblesort(int array[], int tam, int *bandera_ordenado)
{
    *bandera_ordenado = 1;
    for (int i = 0; i < tam - 1; i++)
    {
        for (int j = 0; j < tam - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void qs(int array[], int inicio, int final, int *bandera_ordenado)
{
    *bandera_ordenado = 1;
    int izq, der, pivote, temp;
    izq = inicio;
    der = final;
    pivote = array[(izq + der) / 2];

    do
    {
        while (array[izq] < pivote)
        {
            izq++;
        }

        while (array[der] > pivote)
        {
            der--;
        }

        if (izq <= der)
        {
            temp = array[izq];
            array[izq] = array[der];
            array[der] = temp;
            izq++;
            der--;
        }
    } while (izq <= der);

    if (inicio < der)
    {
        qs(array, inicio, der, bandera_ordenado);
    }

    if (final > izq)
    {
        qs(array, izq, final, bandera_ordenado);
    }
}