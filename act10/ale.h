// CYNDY ALEJANDRA MIRANDA LARA
// DESC: ESTRUCTURA ALUMNO, GENERAR 500 REGISTROS
// Fecha: 15 DE ABRIL 2024  Terminado: 16 DE ABRIL 2024
// CAML_ACT10_01.cpp

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct
{
  int status;
  int matr;
  int edad;
  int sexo;
  char apellido_paterno[30];
  char apellido_materno[30];
  char nombre[30];
} Alumno;


int msges();
void menu();
void titulo();
void mensajeria(int estado);
void cls();
void pause();
void comenzar();
int validar_num_recursivo(Alumno alumnos[], int ri, int rf);
int retornar_long_alumnos(Alumno alumnos[]);
void agregar_automatico(Alumno alumnos[], char apellidos_generico[][15], char nombres_mujer_generico[][15], char nombres_hombre_generico[][15]);
void agregar_manual(Alumno alumnos[]);
void eliminar_registro(Alumno alumnos[]);
void buscar(Alumno alumnos[]);
void ordenar(Alumno alumnos[]);
void imprimir(Alumno alumnos[]);

int msges()
{
  int op;
  system("CLS");
  printf("   M  E   N   U \n");
  printf("1.- AGREGAR AUTOMATICO \n");
  printf("2.- AGREGAR MANUAL \n");
  printf("3.- ELIMINAR REGISTRO \n");
  printf("4.- BUSCAR \n");
  printf("5.- ORDENAR \n");
  printf("6.- IMPRIMIR \n");
  printf("0.- SALIR  \n");
  printf("ESCOGE UNA OPCION: ");
  scanf("%d", &op);
  return op;
}

void menu()
{
  int op;
  Alumno alumnos[500];

  char apellidos_generico[50][15] = {
      "Gonzalez", "Rodriguez", "Perez", "Lopez", "Martinez", "Hernandez", "Gomez", "Fernandez", "Diaz", "Torres",
      "Vazquez", "Ramos", "Alvarez", "Castillo", "Ruiz", "Sanchez", "Ramirez", "Moreno", "Delgado", "Romero",
      "Navarro", "Ortiz", "Mendoza", "Vargas", "Castro", "Luna", "Villalobos", "Molina", "Aguilar", "Herrera",
      "Silva", "Gallardo", "Cortes", "Pacheco", "Reyes", "Medina", "Guzman", "Salazar", "Pena", "Vega", "Galindo",
      "Maldonado", "Campos", "Rojas", "Benitez", "Fuentes", "Valencia", "Pineda", "Cervantes"};

  char nombres_mujer_generico[50][15] = {
      "Maria", "Laura", "Carmen", "Ana", "Isabel", "Sofia", "Patricia", "Luisa", "Diana", "Elena",
      "Lucia", "Paula", "Marta", "Rosa", "Clara", "Teresa", "Eva", "Beatriz", "Monica", "Pilar",
      "Natalia", "Lorena", "Lourdes", "Silvia", "Dolores", "Julia", "Cristina", "Alejandra", "Marina",
      "Gloria", "Adriana", "Rocio", "MariaJose", "Victoria", "Angela", "Ines", "Raquel", "Miriam",
      "Alicia", "Sara", "Virginia", "Cecilia", "Patrocinio", "Regina", "Esther", "Margarita", "Antonia",
      "Fabiola", "Celia", "Mireya"};

  char nombres_hombre_generico[50][15] = {
      "Juan", "Carlos", "Pedro", "Jose", "Xavier", "Manuel", "Antonio", "Francisco", "Javier", "Miguel",
      "Angel", "Fernando", "Ricardo", "Diego", "Daniel", "Alberto", "Adrian", "Alejandro", "Roberto",
      "Guillermo", "Jesus", "Rafael", "Oscar", "Ramon", "Sergio", "Eduardo", "Mario", "Victor", "Jorge",
      "Pablo", "Andres", "Emilio", "Mariano", "Ignacio", "Hector", "Alfredo", "Israel", "Bruno", "Felipe",
      "Gonzalo", "Raul", "Cesar", "Leonardo", "Rodrigo", "Gustavo", "Samuel", "Joaquin", "Feliciano",
      "Ernesto", "Enrique"};

  do
  {

    comenzar();

    op = msges();
    switch (op)
    {
    case 1:
      cls();
      titulo();
      mensajeria(1);
      agregar_automatico(alumnos, apellidos_generico, nombres_mujer_generico, nombres_hombre_generico);
      pause();
      break;
    case 2:
      cls();
      titulo();
      mensajeria(2);
      agregar_manual(alumnos);
      pause();
      break;
    case 3:
      cls();
      titulo();
      mensajeria(3);
      eliminar_registro(alumnos);
      pause();
      break;
    case 4:
      cls();
      titulo();
      mensajeria(4);
      buscar(alumnos);
      pause();
      break;
    case 5:
      cls();
      titulo();
      mensajeria(5);
      pause();
      ordenar(alumnos);
      pause();
      break;
    case 6:
      cls();
      titulo();
      mensajeria(6);
      imprimir(alumnos);
      pause();
      break;
    }

  } while (op != 0);
}

void titulo()
{
  printf("\n");
  printf("|-------------------------------------------------------------------------------------------- |\n");
  printf("|                                                                                             |\n");
  printf("|                        E S T R U C T U R A S :    A L U M N O S                             |\n");
  printf("|                                                                                             |\n");
  printf("|-------------------------------------------------------------------------------------------- |\n");
}

void mensajeria(int estado)
{

  switch (estado)
  {
  case 0:
    printf("|-------------------------------------------------------------------------------------------- |\n");
    printf("|                      Programa para mantener registro de los alumnos.                        |\n");
    printf("|-------------------------------------------------------------------------------------------- |\n");
    printf("\n\n");
    break;
  case 1:
    printf("|-------------------------------------------------------------------------------------------- |\n");
    printf("|                            Cuantos valores quieres ingresar?                                |\n");
    printf("|-------------------------------------------------------------------------------------------- |\n");
    printf("\n\n");
    break;
  case 2:
    printf("|-------------------------------------------------------------------------------------------- |\n");
    printf("|                            Ingresa los valores solicitados                                  |\n");
    printf("|-------------------------------------------------------------------------------------------- |\n");
    printf("\n\n");
    break;
  case 3:
    printf("|-------------------------------------------------------------------------------------------- |\n");
    printf("|                            Ingresa la matricula a eliminar                                  |\n");
    printf("|-------------------------------------------------------------------------------------------- |\n");
    printf("\n\n");
    break;
  case 4:
    printf("|-------------------------------------------------------------------------------------------- |\n");
    printf("|                             Ingresa la matricula a buscar                                   |\n");
    printf("|-------------------------------------------------------------------------------------------- |\n");
    printf("\n\n");
    break;
  case 5:
    printf("|-------------------------------------------------------------------------------------------- |\n");
    printf("|                                      Ordenando...                                           |\n");
    printf("|-------------------------------------------------------------------------------------------- |\n");
    printf("\n\n");
    break;
  case 6:
    printf("|-------------------------------------------------------------------------------------------- |\n");
    printf("|                               Impresion de alumnos activos:                                 |\n");
    printf("|-------------------------------------------------------------------------------------------- |\n");
    printf("\n\n");
    break;
  }
}

void cls()
{
  system("cls");
}

void pause()
{
  system("pause");
}

void comenzar()
{
  cls();
  titulo();
  mensajeria(0);
  pause();
}

int validar_num_recursivo(Alumno alumnos[], int ri, int rf)
{
  int valido = 0;
  int num;

  do
  {
    valido = 1;
    printf(" -> : ");
    if (scanf("%d", &num) != 1 || num < ri || num > rf)
    {
      if (num > rf)
      {
        printf("\n Numero ingresado excede el limite, ingresa uno menor de %d \n", rf);
      }
      else
      {
        printf("\n Numero no valido, ingresa otro \n");
      }
      valido = 0;
    }

  } while (!valido);

  return num;
}

int retornar_long_alumnos(Alumno alumnos[])
{
  int contador = 0;

  for (int i = 0; i < 500; i++)
  {
    if (alumnos[i].status == 1)
    {
      contador++;
    }
  }

  return contador;
}


void agregar_automatico(Alumno alumnos[], char apellidos_generico[][15], char nombres_mujer_generico[][15], char nombres_hombre_generico[][15])
{
  int indice = retornar_long_alumnos(alumnos);

  if (indice >= 498)
  {
    printf("\nEl registro de alumnos esta lleno. No se pueden agregar mas alumnos.\n");
    return;
  }

  int n = validar_num_recursivo(alumnos, 1, 500 - indice);

  for (int i = 0; i < n; i++)
  {
    alumnos[i].status = 1;
    strcpy(alumnos[i].apellido_paterno, apellidos_generico[rand() % 50]);
    strcpy(alumnos[i].apellido_materno, apellidos_generico[rand() % 50]);
    alumnos[i].edad = 17 + (rand() % 83);
    alumnos[i].matr = 3000 + (rand() % 700000);
    alumnos[i].sexo = rand() % 2;

    if (alumnos[i].sexo)
    {
      strcpy(alumnos[i].nombre, nombres_hombre_generico[rand() % 50]);
    }
    else
    {
      strcpy(alumnos[i].nombre, nombres_mujer_generico[rand() % 50]);
    }
  }

  printf("\n Agregado correctamente! \n");
}

void agregar_manual(Alumno alumnos[])
{
  int indice = retornar_long_alumnos(alumnos);

  if (indice >= 498)
  {
    printf("\nEl registro de alumnos esta lleno. No se pueden agregar mas alumnos.\n");
    return;
  }

  alumnos[indice].status = 1;

  printf("\nIngrese el numero de matricula del alumno -> : ");
  scanf("%d", &alumnos[indice].matr);

  printf("Ingrese el apellido paterno del alumno -> : ");
  scanf("%s", alumnos[indice].apellido_paterno);

  printf("Ingrese el apellido materno del alumno -> : ");
  scanf("%s", alumnos[indice].apellido_materno);

  printf("Ingrese el nombre del alumno -> : ");
  scanf("%s", alumnos[indice].nombre);

  printf("Ingrese la edad del alumno -> : ");
  scanf("%d", &alumnos[indice].edad);

  printf("Ingrese el sexo del alumno (0 para mujer, 1 para hombre) -> : ");
  scanf("%d", &alumnos[indice].sexo);

  printf("\n\nAgregado correctamente! \n");
}

void eliminar_registro(Alumno alumnos[])
{
  int matricula;
  int encontrado = 0;

  scanf("%d", &matricula);

  for (int i = 0; i < 500; i++)
  {
    if (alumnos[i].matr == matricula)
    {
      alumnos[i].status = 0;
      encontrado = 1;
      printf("\nRegistro eliminado correctamente!\n");
      break;
    }
  }

  if (!encontrado)
  {
    printf("\nNo se encontro ningun alumno con la matricula ingresada.\n");
  }
}

void buscar(Alumno alumnos[])
{
  int matricula;
  int encontrado = 0;

  printf("\nIngrese la matricula del alumno que desea buscar: ");
  scanf("%d", &matricula);

  for (int i = 0; i < 500; i++)
  {
    if (alumnos[i].status == 1 && alumnos[i].matr == matricula)
    {
      encontrado = 1;
      printf("\nMatricula: %d\n", alumnos[i].matr);
      printf("Apellido Paterno: %s\n", alumnos[i].apellido_paterno);
      printf("Apellido Materno: %s\n", alumnos[i].apellido_materno);
      printf("Nombre: %s\n", alumnos[i].nombre);
      printf("Edad: %d\n", alumnos[i].edad);

      if (alumnos[i].sexo == 1)
      {
        printf("Sexo: Hombre\n");
      }
      else
      {
        printf("Sexo: Mujer\n");
      }
      break;
    }
  }

  if (!encontrado)
  {
    printf("\nNo se encontro ningun alumno con la matricula ingresada.\n");
  }
}

void ordenar(Alumno alumnos[])
{
  Alumno temp;
  int n = retornar_long_alumnos(alumnos);

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (alumnos[j].matr > alumnos[j + 1].matr)
      {
        temp = alumnos[j];
        alumnos[j] = alumnos[j + 1];
        alumnos[j + 1] = temp;
      }
    }
  }

  printf("\nSe ordeno correctamente!!!\n");
}

void imprimir(Alumno alumnos[])
{
  int n = retornar_long_alumnos(alumnos);

  printf("\n|-------------------------------------------------------------------------------------------- |\n");
  printf("| Matrícula |   Apellido Paterno   |   Apellido Materno   |   Nombre   | Edad | Sexo |\n");
  printf("|-------------------------------------------------------------------------------------------- |\n");

  for (int i = 0; i < n; i++)
  {
    if (alumnos[i].status == 1)
    {
      printf("| %9d | %20s | %20s | %10s | %4d | ", alumnos[i].matr,
             alumnos[i].apellido_paterno,
             alumnos[i].apellido_materno,
             alumnos[i].nombre,
             alumnos[i].edad);

      if (alumnos[i].sexo == 1)
      {
        printf("Hombre |\n");
      }
      else
      {
        printf("Mujer   |\n");
      }
    }
  }

  printf("|-------------------------------------------------------------------------------------------- |\n");
}
