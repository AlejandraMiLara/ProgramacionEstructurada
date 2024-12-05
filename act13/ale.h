// CYNDY ALEJANDRA MIRANDA LARA
// DESC: STRUCT typedef tkey
// Fecha: 15/05/2024
// CAML_ACT13_01.cpp

typedef int Tkey;

typedef struct
{
    int clave;
    int status;
    char primer_nombre[100];
    char segundo_nombre[100];
    char apellido_paterno[100];
    char apellido_materno[100];
    int edad;
    char genero[5];
} Empleado;

// PROTITPOS
void menu();
int msges();

void agregar(Empleado empleados[], int *bandera_totalreg, int bandera_ordenado, char apellidos_generico[][15], char nombres_mujer_generico[][15], char nombres_hombre_generico[][15]);
void editar(Empleado empleados[], int *bandera_totalreg, int bandera_ordenado);
void eliminar(Empleado empleados[], int *bandera_totalreg, int bandera_ordenado);
void buscar(Empleado empleados[], int bandera_totalreg, int bandera_ordenado);
void ordenar(Empleado empleados[], int bandera_totalreg, int *bandera_ordenado);
void imprimir(Empleado empleados[], int bandera_totalreg);
void generar_archtxt(Empleado empleados[], int bandera_totalreg);
void ver_archtxt();
void generar_archbin(Empleado empleados[], int bandera_totalreg);
void cargar_archbin(Empleado empleados[], int *bandera_totalreg, int *bandera_cargado);
void borrados_archbin();

int retorna_clave(Empleado empleados[], int bandera_totalreg, int bandera_ordenado, int clave, int modo);
void vali_char(char *cadena);

void qs(int array[], int inicio, int final, int *bandera_ordenado);
void bubblesort(int array[], int tam, int *bandera_ordenado);
int busq(Empleado empleados[], int bandera_totalreg, int bandera_ordenado, int buscado, int modo_bus);

// FUNCIONES
void menu()
{
    int op;
    int bandera_totalreg = 0;
    int bandera_ordenado = 0;
    int bandera_cargado = 0;

    Empleado empleados[1500];

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
                agregar(empleados, &bandera_totalreg, bandera_ordenado, apellidos_generico, nombres_mujer_generico, nombres_hombre_generico);
                break;
            case 2:
                editar(empleados, &bandera_totalreg, bandera_ordenado);
            break;
            case 3:
                eliminar(empleados, &bandera_totalreg, bandera_ordenado);
            break;
            case 4:
                buscar(empleados, bandera_totalreg, bandera_ordenado);
            break;
            case 5:
            //call function ordenar()
            ordenar(empleados, bandera_totalreg, &bandera_ordenado);
            break;
            case 6:
                imprimir(empleados, bandera_totalreg);
            break;
            case 7:
                generar_archtxt(empleados, bandera_totalreg);
            break;
            case 8:
                ver_archtxt();
            break;
            case 9:
                generar_archbin(empleados, bandera_totalreg);
            break;
            case 10:
                cargar_archbin(empleados, &bandera_totalreg, &bandera_cargado);
            break;
            case 11:
                borrados_archbin();
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
    printf("1.- AGREGAR 100 REG\n");
    printf("2.- EDITAR\n");
    printf("3.- ELIMINAR\n");
    printf("4.- BUSCAR\n");
    printf("5.- ORDENAR\n");
    printf("6.- IMPRIMIR\n");
    printf("7.- GENERAR ARCHIVO TEXTO\n");
    printf("8.- VER ARCHIVO TEXTO\n");
    printf("9.- GENERAR ARCHIVO BINARIO\n");
    printf("10.- CARGAR ARCHIVO BINARIO\n");
    printf("11.- MOSTRAR BORRADOS\n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    while (getchar() != '\n');
    return op;
}

void agregar(Empleado empleados[], int *bandera_totalreg, int bandera_ordenado, char apellidos_generico[][15], char nombres_mujer_generico[][15], char nombres_hombre_generico[][15])
{
    printf("\n Elementos ingresados hasta el momento: %d \n", *bandera_totalreg);

    if (*bandera_totalreg >= 1500)
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

            cargar = 100;

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
                empleados[i].status = 1;
                empleados[i].edad = 17 + rand() % 83;

                strcpy(empleados[i].apellido_paterno, apellidos_generico[rand() % 49]);
                strcpy(empleados[i].apellido_materno, apellidos_generico[rand() % 49]);

                int valido_clave = 0;
                do
                {
                    empleados[i].clave = 300000 + rand() % 700000;
                    valido_clave = retorna_clave(empleados, *bandera_totalreg, 0, empleados[i].clave, 0);
                } while (valido_clave != -1);

                int genero = 1 + rand() % 2;

                if (genero == 1)
                {
                    strcpy(empleados[i].genero, "M");
                    strcpy(empleados[i].primer_nombre, nombres_mujer_generico[rand() % 50]);
                    strcpy(empleados[i].segundo_nombre, nombres_mujer_generico[rand() % 50]);
                }
                else
                {
                    strcpy(empleados[i].genero, "H");
                    strcpy(empleados[i].primer_nombre, nombres_hombre_generico[rand() % 50]);
                    strcpy(empleados[i].segundo_nombre, nombres_hombre_generico[rand() % 50]);
                }

                FILE *archivo = fopen("datos.txt", "a");

                if (archivo != NULL)
                {
                    fprintf(archivo, "%d %d %s %s %s %s %d %s\n",
                            &empleados[i].status,
                            &empleados[i].clave,
                            empleados[i].apellido_paterno,
                            empleados[i].apellido_materno,
                            empleados[i].primer_nombre,
                            empleados[i].segundo_nombre,
                            &empleados[i].edad,
                            empleados[i].genero);
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

void editar(Empleado empleados[], int *bandera_totalreg, int bandera_ordenado)
{
    system("cls");
    int valido = 0;

    do {
        valido = 1;
        int clave;

        printf("\n Ingresa la CLAVE a EDITAR: \n\n");
        scanf("%d", &clave);
        while (getchar() != '\n'); 

        int pos_clave = retorna_clave(empleados, *bandera_totalreg, bandera_ordenado, clave, 0);

        if (pos_clave < 0)
        {
            valido = 0;
            printf("\nCLAVE NO ENCONTRADA...\n");
            system("pause");
            break;
        }
        else
        {
            if(empleados[pos_clave].status == 0)
            {
                valido = 0;
                printf("\nEsa CLAVE fue eliminada anteriormente...\n");
                system("pause");
                break;
            }
            else
            {
                // Editar datos
                char pr_nombre[100];
                char sg_nombre[100];
                char pr_ape[100];
                char sg_ape[100];
                int edad;

                printf("\n Ingresa el primer nombre \n");
                vali_char(pr_nombre);
                strcpy(empleados[pos_clave].primer_nombre, pr_nombre);

                printf("\n Ingresa el segundo nombre \n");
                vali_char(sg_nombre);
                strcpy(empleados[pos_clave].segundo_nombre, sg_nombre);

                printf("\n Ingresa el primer apellido \n");
                vali_char(pr_ape);
                strcpy(empleados[pos_clave].apellido_paterno, pr_ape);

                printf("\n Ingresa el segundo apellido \n");
                vali_char(sg_ape);
                strcpy(empleados[pos_clave].apellido_materno, sg_ape);

                printf("\n Ingresa la edad \n");
                scanf("%d", &edad);
                empleados[pos_clave].edad = edad;

                printf("\n Empleado editado exitosamente\n");
                system("pause");
            }
        }
    } while (!valido);
}

void eliminar(Empleado empleados[], int *bandera_totalreg, int bandera_ordenado)
{
    system("cls");

    int valido = 0;
    do
    {
        valido = 1;
        int confirmado = 0;
        int clave;

        printf("\n Ingresa la CLAVE a ELIMINAR: \n\n");
        scanf("%d", &clave);
        while (getchar() != '\n');

        system("cls");
        printf("\n Eliminar la CLAVE: %d \n", clave);
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

        int pos_clave = retorna_clave(empleados, *bandera_totalreg, bandera_ordenado, clave, 0);

        if (pos_clave < 0)
        {
            valido = 0;
            printf("\nCLAVE NO ENCONTRADA...\n");
            system("pause");
            break;
        }
        else
        {
            system("cls");
            valido = 1;
            empleados[pos_clave].status = 0;
            printf("\n CLAVE: %d ELIMINADA correctamente \n ",clave);

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
                int clave_archivo;
                sscanf(linea, "%*d %d", &clave_archivo);
                if (clave_archivo != clave)
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

void buscar(Empleado empleados[], int bandera_totalreg, int bandera_ordenado)
{
    system("cls");
    int valido = 0;
    int claves[bandera_totalreg];
    int busqueda;

    do
    {
        int buscado;
        printf("\n Buscar por clave\n\n Ingresa la clave que deseas buscar \n ->:");
        scanf("%d", &buscado);
        while (getchar() != '\n');

        if (bandera_ordenado)
        {
            if (bandera_totalreg >= 1000)
            {
                busqueda = busq(empleados, bandera_totalreg, bandera_ordenado, buscado, 1);

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
                busqueda = busq(empleados, bandera_totalreg, bandera_ordenado, buscado, 0);

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
                    claves[i] = empleados[i].clave;
                }

                printf("\n AVISO: Para esta busqueda se ordenaran los registros automaticamente.\n");
                qs(claves, 0, (bandera_totalreg - 1), &bandera_ordenado); // Corrección aquí
                printf("\n... Se ordenaron correctamente!\n");

                busqueda = busq(empleados, bandera_totalreg, bandera_ordenado, buscado, 1);

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
                busqueda = busq(empleados, bandera_totalreg, bandera_ordenado, buscado, 0);

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

void ordenar(Empleado empleados[], int bandera_totalreg, int *bandera_ordenado)
{
    system("cls");
    int claves[bandera_totalreg];
    for (int i = 0; i < bandera_totalreg; i++)
    {
        claves[i] = empleados[i].clave;
    }

    if (!(*bandera_ordenado))
    {
        if (bandera_totalreg >= 1000)
        {
            qs(claves, 0, (bandera_totalreg - 1), bandera_ordenado);
            *bandera_ordenado = 1;
            printf("\n... Se ordenaron correctamente!\n");
        }
        else
        {
            bubblesort(claves, bandera_totalreg, bandera_ordenado);
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
        empleados[i].clave = claves[i];
    }

    system("pause");
}

void imprimir(Empleado empleados[], int bandera_totalreg)
{
    system("cls");
    printf("\nIMPRESION MODO TABLA\n\n");
    printf("%-8s%-12s%-20s%-20s%-15s%-15s%-8s%s\n",
           "Status", "CLAVE", "Apellido Paterno", "Apellido Materno", "Primer Nombre", "Segundo Nombre", "Edad", "Genero");

    for (int i = 0; i < bandera_totalreg; i++)
    {
        for (int j = strlen(empleados[i].apellido_paterno) - 1; j >= 0; j--) {
            if (!isprint(empleados[i].apellido_paterno[j])) {
                empleados[i].apellido_paterno[j] = '\0';
            } else {
                break;
            }
        }
        printf("%-8d%-12d", empleados[i].status, empleados[i].clave);
        printf("%-20s%-20s%-15s%-15s", empleados[i].apellido_paterno, empleados[i].apellido_materno,
               empleados[i].primer_nombre, empleados[i].segundo_nombre);
        printf("%-8d%c\n", empleados[i].edad, empleados[i].genero[0]);
    }
    system("pause");
}


void generar_archtxt(Empleado empleados[], int bandera_totalreg) {
    char nombre[50];
    printf("\nGENERAR ARCHIVOS\n\n");
    printf("Elige el nombre del archivo que quieres crear ->: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';
    fflush(stdin);

    char nombre_archivo[50];
    strcpy(nombre_archivo, nombre);
    strcat(nombre_archivo, ".txt");

    FILE *archivo = fopen(nombre_archivo, "w");
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
                    empleados[i].status,
                    empleados[i].clave,
                    empleados[i].apellido_paterno,
                    empleados[i].apellido_materno,
                    empleados[i].primer_nombre,
                    empleados[i].segundo_nombre,
                    empleados[i].edad,
                    empleados[i].genero[0]);
        }
        fclose(archivo);
        printf("Archivo generado correctamente.\n");
        system("pause");
    }
}

void ver_archtxt()
{
    system("cls");
    char nombre[50];
    printf("\nLEER ARCHIVOS\n\n");
    printf("Elige el nombre del archivo que quieres leer ->: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';
    fflush(stdin);

    char nombre_archivo[50];
    strcpy(nombre_archivo, nombre);
    strcat(nombre_archivo, ".txt");

    FILE *archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.");
        system("pause");
        return;
    }
    else
    {
        char linea[256];
        while (fgets(linea, sizeof(linea), archivo) != NULL) {
            printf("%s", linea);
        }
        fclose(archivo);
    }

    system("pause");
}

void generar_archbin(Empleado empleados[], int bandera_totalreg) {
    if (bandera_totalreg == 0) {
        printf("No hay registros en el vector.\n");
        system("pause");
        return;
    }

    FILE *archivo_bin = fopen("datos.dll", "wb");
    if (archivo_bin == NULL) {
        perror("Error al crear el archivo binario");
        system("pause");
        return;
    }

    FILE *archivo_respaldo = fopen("datos.tmp", "wb");
    if (archivo_respaldo == NULL) {
        perror("Error al crear el archivo de respaldo");
        fclose(archivo_bin);
        system("pause");
        return;
    }

    for (int i = 0; i < bandera_totalreg; i++) {
        fwrite(&empleados[i], sizeof(Empleado), 1, archivo_bin);
        fwrite(&empleados[i], sizeof(Empleado), 1, archivo_respaldo);
    }

    fclose(archivo_bin);
    fclose(archivo_respaldo);

    printf("Archivo binario generado exitosamente.\n");
    system("pause");
}

void cargar_archbin(Empleado empleados[], int *bandera_totalreg, int *bandera_cargado) {
    if (*bandera_cargado) {
        printf("El archivo binario ya fue cargado.\n");
        system("pause");
        return;
    }

    FILE *archivo_bin = fopen("datos.dll", "rb");
    if (archivo_bin == NULL) {
        perror("Error al abrir el archivo binario");
        system("pause");
        return;
    }

    *bandera_totalreg = 0;
    while (fread(&empleados[*bandera_totalreg], sizeof(Empleado), 1, archivo_bin)) {
        (*bandera_totalreg)++;
    }

    fclose(archivo_bin);
    *bandera_cargado = 1;

    printf("Archivo binario cargado exitosamente.\n");
    system("pause");
}

void borrados_archbin() {
    FILE *archivo_bin = fopen("datos.dll", "rb");
    if (archivo_bin == NULL) {
        perror("Error al abrir el archivo binario");
        return;
    }

    Empleado empleado;
    int encontrados = 0;

    while (fread(&empleado, sizeof(Empleado), 1, archivo_bin)) {
        if (empleado.status == 0) {
            printf("Clave: %d, Nombre: %s %s %s %s, Edad: %d, Genero: %s\n",
                   empleado.clave,
                   empleado.primer_nombre, empleado.segundo_nombre,
                   empleado.apellido_paterno, empleado.apellido_materno,
                   empleado.edad, empleado.genero);
            encontrados++;
            system("pause");
        }
    }

    fclose(archivo_bin);

    if (encontrados == 0) {
        printf("No se encontraron registros eliminados.\n");
        system("pause");
    }
}

int retorna_clave(Empleado empleados[], int bandera_totalreg, int bandera_ordenado, int clave, int modo)
{
    switch (modo)
    {
    case 0:
        for (int i = 0; i < bandera_totalreg; i++)
        {
            if (empleados[i].clave == clave && empleados[i].status == 1)
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
        int claves[bandera_totalreg];

        for (int i = 0; i < bandera_totalreg; i++)
        {
            claves[i] = empleados[i].clave;
        }

        while (inicio <= fin)
        {
            mitad = (inicio + fin) / 2;
            if (claves[mitad] == clave)
            {
                return mitad + 1;
            }

            if (clave < claves[mitad])
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

int busq(Empleado empleados[], int bandera_totalreg, int bandera_ordenado, int buscado, int modo_bus)
{
    int pos_clave = retorna_clave(empleados, bandera_totalreg, bandera_ordenado, buscado, modo_bus);

    if (pos_clave >= 0)
    {
        printf("\n REGISTRO \n\n");
        printf("MATRICULA: %d \n", empleados[pos_clave].clave);
        printf("PRIMER NOMBRE: %s \n", empleados[pos_clave].primer_nombre);
        printf("SEGUNDO NOMBRE: %s \n", empleados[pos_clave].segundo_nombre);
        printf("PRIMER APELLIDO: %s \n", empleados[pos_clave].apellido_paterno);
        printf("SEGUNDO APELLIDO: %s \n", empleados[pos_clave].apellido_materno);
        printf("EDAD: %d \n", empleados[pos_clave].edad);
        char genero[20] = {};
        if (strcmp(empleados[pos_clave].genero, "M") == 0)
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
        printf("\n CLAVE no encontrada ! \n");
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

void vali_char(char *cadena)
{
    int valido = 0;
    while (!valido) {
        printf("Ingresa un valor: ");
        fgets(cadena, 100, stdin);
    
        if (cadena[strlen(cadena) - 1] == '\n') {
            cadena[strlen(cadena) - 1] = '\0';
        }

        int start = 0, end = strlen(cadena) - 1;
        while (isspace((unsigned char)cadena[start])) start++;
        while (end >= start && isspace((unsigned char)cadena[end])) end--;
        for (int i = start; i <= end; i++) {
            cadena[i - start] = cadena[i];
        }
        cadena[end - start + 1] = '\0';

        if (strlen(cadena) > 0) {
            valido = 1;
        } else {
            printf("El valor no puede estar vacio ni tener espacios al principio o al final.\n");
        }
    }
}