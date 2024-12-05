// CYNDY ALEJANDRA MIRANDA LARA
// DESC: Programa en C que sirva para el juego del CHINCHAMPU (Piedra, Papel, Tijera)
// para 1 jugador y la computadora SELECCION MULTIPLE
// Fecha: 25/02/2024
// CAML_ACT04_08.cpp

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int opc, maquina;
    printf("CHINCHAMPU\n--------------\n\n Elige: \n 0. Piedra  1. Papel  2. Tijera\n\n ");
    scanf("%d", &opc);

	srand(time(NULL)); 
	maquina = rand() % 3; 

    switch (opc)
    {
        case 0:
            switch(maquina)
            {
                case 0:
                    printf("Computadora eligio: %d -> EMPATE\n", maquina);
                    break;
                case 1:
                    printf("Computadora eligio: %d -> PIERDES\n", maquina);
                    break;
                case 2:
                    printf("Computadora eligio: %d -> GANAS\n", maquina);
                    break;
                default:
                printf("Error");
                break;
            }
            break;

        case 1:
            switch(maquina)
            {
                case 0:
                    printf("Computadora eligio: %d -> GANAS\n", maquina);
                    break;
                case 1:
                    printf("Computadora eligio: %d -> EMPATE\n", maquina);
                    break;
                case 2:
                    printf("Computadora eligio: %d -> PIERDES\n", maquina);
                    break;
                default:
                printf("Error");
                break;
            }
            break;
        
        case 2:
            switch(maquina)
            {
                case 0:
                    printf("Computadora eligio: %d -> PIERDES\n", maquina);
                    break;
                case 1:
                    printf("Computadora eligio: %d -> GANAS\n", maquina);
                    break;
                case 2:
                    printf("Computadora eligio: %d -> EMPATE\n", maquina);
                    break;
                default:
                printf("Error");
                break;
            }
            break;

        default:
            printf("Error");
            break;
    }

}