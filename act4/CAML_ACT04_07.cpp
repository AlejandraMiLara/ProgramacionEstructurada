/*
   CYNDY ALEJANDRA MIRANDA LARA
   DESC: En la materia programación estructurada se aplican 5 exámenes, calcular el
   promedio final de la materia donde la calificación menor de los exámenes se anula y
   el promedio se calcula en base a 4 exámenes.
   Fecha: 25/02/2024 
   CAML_ACT04_07.cpp
*/

#include <stdio.h>

int main()
{

    int c1, c2, c3, c4, c5; //calificaciones
    int menor;
    int calc;

    printf("Ingresa la calificacion 1\n");
    scanf("%d", &c1);
    printf("Ingresa la calificacion 2\n");
    scanf("%d", &c2);
    printf("Ingresa la calificacion 3\n");
    scanf("%d", &c3); 
    printf("Ingresa la calificacion 4\n");
    scanf("%d", &c4);
    printf("Ingresa la calificacion 5\n");
    scanf("%d", &c5);

    if(c1 < c2)
    {
        if(c1 < c3)
        {
            if(c1 < c4)
            {
                if(c1 < c5)
                {
                    menor = c1;
                    calc = (c2 + c3 + c4 + c5)/4;
                }

                else
                {
                    menor = c5;
                    calc = (c1 + c2 + c3 + c4)/4;
                }
            }

            else
            {
                if(c4 < c5)
                {
                    menor = c4;
                    calc = (c1 + c2 + c3 + c5)/4;
                }

                else
                {
                    menor = c5;
                    calc = (c1 + c2 + c3 + c4)/4;
                }
            }
        }

        else
        {
            if(c3 < c4)
            {
                if(c3 < c5)
                {
                    menor = c3;
                    calc = (c1 + c2 + c4 + c5)/4;
                }

                else
                {
                    menor = c5;
                    calc = (c1 + c2 + c3 + c4)/4;
                }
            }

            else
            {
                if(c4 < c5)
                {
                    menor = c4;
                    calc = (c1 + c2 + c3 + c5)/4;
                }

                else
                {
                    menor = c5;
                    calc = (c1 + c2 + c3 + c4)/4;
                }
            }
        }
    }

    else
    {
        if(c2 < c3)
        {
            if(c2 < c4)
            {
                if(c2 < c5)
                {
                    menor = c2;
                    calc = (c1 + c3 + c4 + c5)/4;
                }

                else
                {
                    menor = c5;
                    calc = (c1 + c2 + c3 + c4)/4;
                }
            }

            else
            {
                if(c4 < c5)
                {
                    menor = c4;
                    calc = (c1 + c2 + c3 + c5)/4;
                }

                else
                {
                    menor = c5;
                    calc = (c1 + c2 + c3 + c4)/4;
                }
            }
        }

        else
        {
            if(c3 < c4)
            {
                if(c3 < c5)
                {
                    menor = c3;
                    calc = (c1 + c2 + c4 + c5)/4;
                }

                else
                {
                    menor = c5;
                    calc = (c1 + c2 + c3 + c4)/4;
                }
            }

            else
            {
                if(c4 < c5)
                {
                    menor = c4;
                    calc = (c1 + c2 + c3 + c5)/4;
                }

                else
                {
                    menor = c5;
                    calc = (c1 + c2 + c3 + c4)/4;
                }
            }
        }
    }

    printf("\n\n Promedio: %d  Calificacion menor descartada: %d \n", calc, menor);


}