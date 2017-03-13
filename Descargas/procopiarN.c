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

/* Copiar cadena hasta N caracteres*/
char* copiarN(char* cadOrigen, char* cadDestino)
{
	int i; 
	int m = longCadena(cadOrigen);
	int n;
	printf("Digite la cantidad de caracteres a copiar \n" );
	scanf("%d",&n);

	for(i=0; i<n; i++)
	{
		cadDestino[i]= cadOrigen[i];
	}

	return cadDestino;

}

int main(int argc, char* argv[])
{
	char* cadEntrada = argv[1];
	char* cadn = argv[2];
	int n = atoi(cadn);
	char* cadSalida = (char*) malloc(n+1);
	printf("\n%s\n",cadSalida);
	return 0; 
}








