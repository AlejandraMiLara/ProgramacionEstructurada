// CYNDY ALEJANDRA MIRANDA LARA
// DESC: Programa en C que sirva para el juego del CHINCHAMPU (Piedra, Papel, Tijera)
// para 1 jugador y la computadora SELLECCION ANIDADA
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

    if(opc >= 1)
    {
        if(opc > 1)
        {
            if(maquina >= 1)
            {
                if(maquina > 1)
                {
                    printf("Computadora eligio: %d -> EMPATE\n", maquina);
                }

                else
                {
                    printf("Computadora eligio: %d -> GANAS\n", maquina);
                }
            }
            
            else
            {
                printf("Computadora eligio: %d -> PIERDES\n", maquina);
            }
        }
        
        else
        {
            if(maquina >= 1)
            {
                if(maquina > 1)
                {
                    printf("Computadora eligio: %d -> PIERDES\n", maquina);
                }

                else
                {
                    printf("Computadora eligio: %d -> EMPATE\n", maquina);
                }
            }
            
            else
            {
                printf("Computadora eligio: %d -> GANAS\n", maquina);
            }
        }
    }

    else
    {
        if(maquina >= 1)
        {
            if(maquina > 1)
            {
                printf("Computadora eligio: %d -> GANAS\n", maquina);
            }

            else
            {
                printf("Computadora eligio: %d -> PIERDES\n", maquina);
            }
        }

        else
        {
            printf("Computadora eligio: %d -> EMPATE\n", maquina);
        }
    }

}