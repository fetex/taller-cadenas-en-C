#include <stdio.h>
#include <stdlib.h>

/* Longitud de una cadena */
int longCadena( char* cad)
{
	int n = 0; 
	while (cad[n] != '\0')
	{
		n++;
	}
	return n; 
}

/* Programa longCadena*/

int main (int argc, char* argv[])
{
	char* cadEntrada = argv[1];
	int n = longCadena(cadEntrada); 
	printf("\n%d\n",n);
}
