/******************************************************************************
CYNDY ALEJANDRA MIRANDA LARA MATR: 365544
DESCR: Algoritmo que lea 3 calificaciones calcule el promedio del alumno y desplegar
FECHA: 20/02/2024  MODIF: 21/02/2024
CAML_ACT3_01.cpp

*******************************************************************************/

#include <stdio.h>

int main()
{
	int calif1, calif2, calif3, prom;
    printf("Dame la calificacion 1\n");
	scanf("%d", &calif1);
    printf("Dame la calificacion 2\n");
	scanf("%d", &calif2);
    printf("Dame la calificacion 3\n");
	scanf("%d", &calif3);
	
	prom = (calif1 + calif2 + calif3)/3;
	
	if(prom < 80)
	{
		if(prom < 60)
		{
			if(prom < 30)
			{
				printf("repetir");
			}
			
			else
			{
				printf("extraordinario");
			}
		}
		
		else
		{
			if(prom < 70)
			{
				printf("suficiente");
			}
			
			else
			{
				printf("regular");
			}
		}
	}
	
	else
	{
		if(prom < 98)
		{
			if(prom < 90)
			{
				printf("bien");
			}
			
			else
			{
				printf("muy bien");
			}
		}
		
		else
		{
			if(prom <= 100)
			{
				printf("excelente");
			}
			
			else
			{
				printf("error");
			}
		}
	}

    return 0;
}
