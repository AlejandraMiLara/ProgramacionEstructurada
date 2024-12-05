// CYNDY ALEJANDRA MIRANDA LARA
// DESC: STRUCT Y CURP
// Fecha: 24/04/2024  TERMINADO: 30/04/2024
// CAML_ACT11_01.cpp

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
    char fecha_nac[20];
    int edad;
    char genero[5];
    int estado_nac;
    char curp[20];
    Alumno alumno;
} Persona;

// PROTITPOS
void menu();
int msges();
void cargar(Persona personas[], int *bandera_totalreg, int bandera_ordenado, char apellidos_generico[][15], char nombres_mujer_generico[][15], char nombres_hombre_generico[][15]);
void eliminar(Persona personas[], int *bandera_totalreg, int bandera_ordenado);
void buscar(Persona personas[], int bandera_totalreg, int bandera_ordenado);
void ordenar(Persona personas[], int bandera_totalreg, int *bandera_ordenado);
void imprimir(Persona personas[], int bandera_totalreg);
void archivo(Persona personas[], int bandera_totalreg);
void generar_curp(Persona personas[], int bandera_totalreg, int pos);
char retorna_vocalinterna(char palabra[]);
char retorna_consinterna(char palabra[]);
int retorna_matricula(Persona personas[], int bandera_totalreg, int bandera_ordenado, int matricula, int modo);
void qs(int array[], int inicio, int final, int *bandera_ordenado);
void bubblesort(int array[], int tam, int *bandera_ordenado);
int busq(Persona personas[], int bandera_totalreg, int bandera_ordenado, int buscado, int modo_bus);
void imprime_estado(int cod_estado);

// FUNCIONES
void menu()
{
    int op;
    int bandera_totalreg = 0;
    int bandera_ordenado = 0;

    Persona personas[2000];

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
            cargar(personas, &bandera_totalreg, bandera_ordenado, apellidos_generico, nombres_mujer_generico, nombres_hombre_generico);
            break;
        case 2:
            eliminar(personas, &bandera_totalreg, bandera_ordenado);
            break;
        case 3:
            buscar(personas, bandera_totalreg, bandera_ordenado);
            break;
        case 4:
            ordenar(personas, bandera_totalreg, &bandera_ordenado);
            break;
        case 5:
            imprimir(personas, bandera_totalreg);
            break;
        case 6:
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
    printf("1.- CARGAR \n");
    printf("2.- ELIMINAR \n");
    printf("3.- BUSCAR \n");
    printf("4.- ORDENAR \n");
    printf("5.- IMPRIMIR \n");
    printf("6.- IMPRIMIR EN ARCHIVO \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);

    while (getchar() != '\n')
        ;

    return op;
}

void cargar(Persona personas[], int *bandera_totalreg, int bandera_ordenado, char apellidos_generico[][15], char nombres_mujer_generico[][15], char nombres_hombre_generico[][15])
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
        int limite = 2000 - *bandera_totalreg;
        int valido = 0;

        do
        {
            valido = 1;

            printf("\n Cuantos elementos quieres cargar? Limite: %d \n", limite);
            scanf("%d", &cargar);
            while (getchar() != '\n')
                ;

            if ((*bandera_totalreg + cargar) > 2000)
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

                char fecha[15];
                sprintf(fecha, "%02d/%02d/%04d", 1 + rand() % 31, 1 + rand() % 12, 1900 + rand() % 108);
                strcpy(personas[i].fecha_nac, fecha);

                personas[i].edad = 17 + rand() % 83;
                personas[i].estado_nac = 1 + rand() % 33;

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

                for (int j = 0; personas[i].primer_nombre[j] != '\0'; j++)
                {
                    personas[i].primer_nombre[j] = toupper(personas[i].primer_nombre[j]);
                }
                for (int j = 0; personas[i].segundo_nombre[j] != '\0'; j++)
                {
                    personas[i].segundo_nombre[j] = toupper(personas[i].segundo_nombre[j]);
                }
                for (int j = 0; personas[i].apellido_paterno[j] != '\0'; j++)
                {
                    personas[i].apellido_paterno[j] = toupper(personas[i].apellido_paterno[j]);
                }
                for (int j = 0; personas[i].apellido_materno[j] != '\0'; j++)
                {
                    personas[i].apellido_materno[j] = toupper(personas[i].apellido_materno[j]);
                }

                generar_curp(personas, *bandera_totalreg, i);
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
        while (getchar() != '\n')
            ;

        if (buscado < 300000 || buscado > 999999)
        {
            printf("\nNumero invalido, debe estar en el rango de 300000 a 999999\n");
            system("pause");
            valido = 0;
            break;
        }

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

    int registros_por_pagina = 40;
    int paginas = (bandera_totalreg + registros_por_pagina - 1) / registros_por_pagina;
    int confirmacion;

    int contador = 0;

    for (int pagina = 0; pagina < paginas; pagina++)
    {
        int indice_inicio = pagina * registros_por_pagina;
        int indice_fin = (pagina + 1) * registros_por_pagina;

        if (indice_fin > bandera_totalreg)
        {
            indice_fin = bandera_totalreg;
        }

        printf("\n ----------------PARA VER CURP BUSCAR LA MATRICULA-------------------- \n\n");

        printf("  MATRICULA  |  PR NOMBRE      |  SEG NOMBRE      |  PR APELLIDO      |  SEG APELLIDO      |  FECHA NAC      |  GENERO  |  EDO NAC   \n");
        printf("-------------|-----------------|-----------------|-------------------|-------------------|----------------|----------|------------\n");

        for (int i = indice_inicio; i < indice_fin; i++)
        {
            if (personas[i].alumno.status == 1)
            {
                char genero[20] = {};
                if (strcmp(personas[i].genero, "M") == 0)
                {
                    strcpy(genero, "MUJER");
                }
                else
                {
                    strcpy(genero, "HOMBRE");
                }

                printf("%12d | %-15s | %-15s | %-17s | %-17s | %-14s | %-8s | ", personas[i].alumno.matricula, personas[i].primer_nombre, personas[i].segundo_nombre, personas[i].apellido_paterno, personas[i].apellido_materno, personas[i].fecha_nac, genero);
                imprime_estado(personas[i].estado_nac);
                printf("\n");

                contador++;
            }
        }

        if (contador >= 40)
        {
            printf("\n\n  Quieres continuar con la impresion? \n Presiona 1 para CONTINUAR \n Presiona 0 para SALIR\n ");
            scanf("%d", &confirmacion);
            while (getchar() != '\n')
                ;

            if (confirmacion != 0 && confirmacion != 1)
            {
                printf("\nEleccion incorrecta\n");
                break;
            }

            if (confirmacion == 0)
            {
                break;
            }

            contador = 0;
        }
    }

    system("pause");
}

void archivo(Persona personas[], int bandera_totalreg)
{
    FILE *archivo = fopen("basurita.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.");
        system("pause");
        return;
    }

    int registros_por_pagina = 40;
    int paginas = (bandera_totalreg + registros_por_pagina - 1) / registros_por_pagina;
    int confirmacion;

    int contador = 0;

    for (int pagina = 0; pagina < paginas; pagina++) {
        int indice_inicio = pagina * registros_por_pagina;
        int indice_fin = (pagina + 1) * registros_por_pagina;

        if (indice_fin > bandera_totalreg) {
            indice_fin = bandera_totalreg;
        }

        fprintf(archivo, "\n-----------------------------\n");
        fprintf(archivo, "   MATRICULA  |  PR NOMBRE      |  SEG NOMBRE      |  PR APELLIDO      |  SEG APELLIDO      |  FECHA NAC      |  GENERO  |  EDO NAC\n");
        fprintf(archivo, "--------------|-----------------|-----------------|-------------------|-------------------|----------------|----------|------------\n");

        for (int i = indice_inicio; i < indice_fin; i++) {
            if (personas[i].alumno.status == 1) {
                char genero[20] = {};
                if (strcmp(personas[i].genero, "M") == 0) {
                    strcpy(genero, "MUJER");
                } else {
                    strcpy(genero, "HOMBRE");
                }

                fprintf(archivo, "%12d | %-15s | %-15s | %-17s | %-17s | %-14s | %-8s | ", personas[i].alumno.matricula, personas[i].primer_nombre, personas[i].segundo_nombre, personas[i].apellido_paterno, personas[i].apellido_materno, personas[i].fecha_nac, genero);
                fprintf(archivo, "%d\n", personas[i].estado_nac);

                contador++;
            }
        }

        if (contador >= 40) {
            printf("\n\nQuieres imprimir mas registros?\nPresiona 1 para CONTINUAR\nPresiona 0 para SALIR\n");
            scanf("%d", &confirmacion);
            while (getchar() != '\n');

            if (confirmacion != 0 && confirmacion != 1) {
                printf("\nEleccion incorrecta\n");
                system("pause");
                break;
            }

            if (confirmacion == 0) {
                break;
            }

            contador = 0;
        }

        printf("\n\n Archivado correctamente!\n");
        system("pause");
    }

    fclose(archivo);
}

void generar_curp(Persona personas[], int bandera_totalreg, int pos)
{
    personas[pos].curp[0] = personas[pos].apellido_paterno[0];
    personas[pos].curp[1] = retorna_vocalinterna(personas[pos].apellido_paterno);
    personas[pos].curp[2] = personas[pos].apellido_materno[0];
    personas[pos].curp[3] = personas[pos].primer_nombre[0];

    personas[pos].curp[8] = personas[pos].fecha_nac[0];
    personas[pos].curp[9] = personas[pos].fecha_nac[1];
    personas[pos].curp[6] = personas[pos].fecha_nac[3];
    personas[pos].curp[7] = personas[pos].fecha_nac[4];
    personas[pos].curp[4] = personas[pos].fecha_nac[8];
    personas[pos].curp[5] = personas[pos].fecha_nac[9];

    personas[pos].curp[10] = personas[pos].genero[0];

    char estado_abrev[3];
    switch (personas[pos].estado_nac) {
        case 1: estado_abrev[0] = 'A'; estado_abrev[1] = 'S'; break;
        case 2: estado_abrev[0] = 'B'; estado_abrev[1] = 'C'; break;
        case 3: estado_abrev[0] = 'B'; estado_abrev[1] = 'S'; break;
        case 4: estado_abrev[0] = 'C'; estado_abrev[1] = 'C'; break;
        case 5: estado_abrev[0] = 'C'; estado_abrev[1] = 'L'; break;
        case 6: estado_abrev[0] = 'C'; estado_abrev[1] = 'M'; break;
        case 7: estado_abrev[0] = 'C'; estado_abrev[1] = 'S'; break;
        case 8: estado_abrev[0] = 'C'; estado_abrev[1] = 'H'; break;
        case 9: estado_abrev[0] = 'D'; estado_abrev[1] = 'F'; break;
        case 10: estado_abrev[0] = 'D'; estado_abrev[1] = 'G'; break;
        case 11: estado_abrev[0] = 'G'; estado_abrev[1] = 'T'; break;
        case 12: estado_abrev[0] = 'G'; estado_abrev[1] = 'R'; break;
        case 13: estado_abrev[0] = 'H'; estado_abrev[1] = 'G'; break;
        case 14: estado_abrev[0] = 'J'; estado_abrev[1] = 'C'; break;
        case 15: estado_abrev[0] = 'M'; estado_abrev[1] = 'C'; break;
        case 16: estado_abrev[0] = 'M'; estado_abrev[1] = 'N'; break;
        case 17: estado_abrev[0] = 'M'; estado_abrev[1] = 'S'; break;
        case 18: estado_abrev[0] = 'N'; estado_abrev[1] = 'T'; break;
        case 19: estado_abrev[0] = 'N'; estado_abrev[1] = 'L'; break;
        case 20: estado_abrev[0] = 'O'; estado_abrev[1] = 'C'; break;
        case 21: estado_abrev[0] = 'P'; estado_abrev[1] = 'L'; break;
        case 22: estado_abrev[0] = 'Q'; estado_abrev[1] = 'T'; break;
        case 23: estado_abrev[0] = 'Q'; estado_abrev[1] = 'R'; break;
        case 24: estado_abrev[0] = 'S'; estado_abrev[1] = 'P'; break;
        case 25: estado_abrev[0] = 'S'; estado_abrev[1] = 'L'; break;
        case 26: estado_abrev[0] = 'S'; estado_abrev[1] = 'R'; break;
        case 27: estado_abrev[0] = 'T'; estado_abrev[1] = 'C'; break;
        case 28: estado_abrev[0] = 'T'; estado_abrev[1] = 'S'; break;
        case 29: estado_abrev[0] = 'T'; estado_abrev[1] = 'L'; break;
        case 30: estado_abrev[0] = 'V'; estado_abrev[1] = 'Z'; break;
        case 31: estado_abrev[0] = 'Y'; estado_abrev[1] = 'N'; break;
        case 32: estado_abrev[0] = 'Z'; estado_abrev[1] = 'S'; break;
        case 33: estado_abrev[0] = 'N'; estado_abrev[1] = 'E'; break;
    }


    estado_abrev[2] = '\0';

    personas[pos].curp[11] = estado_abrev[0];
    personas[pos].curp[12] = estado_abrev[1];

    personas[pos].curp[13] = retorna_consinterna(personas[pos].apellido_paterno);
    personas[pos].curp[14] = retorna_consinterna(personas[pos].apellido_materno);
    personas[pos].curp[15] = retorna_consinterna(personas[pos].primer_nombre);

    int anio = atoi(personas[pos].fecha_nac + 6);

    char dieciseis = '0';

    if (anio >= 2000 && anio <= 2010)
    {
        dieciseis = 'A';
    }
    if (anio >= 2011 && anio <= 2020)
    {
        dieciseis = 'B';
    }
    if (anio >= 2021 && anio <= 2030)
    {
        dieciseis = 'C';
    }

    personas[pos].curp[16] = dieciseis;

    if (anio < 2000)
    {
        personas[pos].curp[17] = '0';
    }
    else
    {
        int valor = (anio - 2000) / 5 + 1;
        personas[pos].curp[17] = valor + '0';
    }
}

char retorna_vocalinterna(char palabra[])
{
    int longitud = strlen(palabra);
    for (int i = 1; i < longitud; i++)
    {
        if (palabra[i] == 'A' || palabra[i] == 'E' || palabra[i] == 'O' || palabra[i] == 'U')
        {
            return palabra[i];
        }
    }
}

char retorna_consinterna(char palabra[])
{
    int longitud = strlen(palabra);
    for (int i = 1; i < longitud; i++)
    {
        if (palabra[i] != 'A' && palabra[i] != 'E' && palabra[i] != 'O' && palabra[i] != 'U')
        {
            return palabra[i];
        }
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
        printf("FECHA NAC: %s \n", personas[pos_matr].fecha_nac);
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
        printf("LUG NAC: ");
        imprime_estado(personas[pos_matr].estado_nac);
        printf("\n CURP: %s \n", personas[pos_matr].curp);
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

void imprime_estado(int cod_estado)
{
    switch (cod_estado) {
        case 1: printf("AGUASCALIENTES"); break;
        case 2: printf("BAJA CALIFORNIA"); break;
        case 3: printf("BAJA CALIFORNIA SUR"); break;
        case 4: printf("CAMPECHE"); break;
        case 5: printf("COAHUILA DE ZARAGOZA"); break;
        case 6: printf("COLIMA"); break;
        case 7: printf("CHIAPAS"); break;
        case 8: printf("CHIHUAHUA"); break;
        case 9: printf("CIUDAD DE MEXICO"); break;
        case 10: printf("DURANGO"); break;
        case 11: printf("GUANAJUATO"); break;
        case 12: printf("GUERRERO"); break;
        case 13: printf("HIDALGO"); break;
        case 14: printf("JALISCO"); break;
        case 15: printf("MEXICO"); break;
        case 16: printf("MICHOACAN DE OCAMPO"); break;
        case 17: printf("MORELOS"); break;
        case 18: printf("NAYARIT"); break;
        case 19: printf("NUEVO LEON"); break;
        case 20: printf("OAXACA"); break;
        case 21: printf("PUEBLA"); break;
        case 22: printf("QUERETARO"); break;
        case 23: printf("QUINTANA ROO"); break;
        case 24: printf("SAN LUIS POTOSI"); break;
        case 25: printf("SINALOA"); break;
        case 26: printf("SONORA"); break;
        case 27: printf("TABASCO"); break;
        case 28: printf("TAMAULIPAS"); break;
        case 29: printf("TLAXCALA"); break;
        case 30: printf("VERACRUZ DE IGNACIO DE LA LLAVE"); break;
        case 31: printf("YUCATAN"); break;
        case 32: printf("ZACATECAS"); break;
        case 33: printf("NACIDO EN EL EXTRANJERO"); break;
    }

}