#include <stdio.h>
#include <stdlib.h>

/* Las siguientes funciones son el soporte del taller de cadenas 
   en el lenguaje c */


/* Longitud de una cadena */
int longCadena( char*  cad)
{
	int n = 0; 
	while ( cad[n] != '\0' )
	{
		n++;
	}
	return n; 
}


/* Copiar cadena*/

void copiarcadena(char* cadOrigen, char* cadDestino)
{
	int m = longCadena(cadOrigen);
	int i;
	for (i=0; i <= m; i++)
	{
		cadDestino[i] = cadOrigen[i];
	}
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


char *copiarSub (char *cadOrigen, char *cadDestino, int n, int m)
{
	int i;
	int j = 0;

	for (i = n; i <= m; i++)
	{

		cadDestino[j] = cadOrigen[i];
		j++;
	}

	return cadDestino;
}


int compararCadenas (char *cad1, char *cad2)
{
	int i = 0;
	while ((cad1[i] != '\0') || (cad2[i] != '\0' ))
	{
		if (cad1[i] == cad2[i])
		{
			i++;
		}

		else if (cad1[i] < cad2[i])
		{
			return -1;
		}

		else
		{
			return 1;
		}
	}
	return 0;
}


char * concatenarCadenas (char *cad1, char *cad2)
{
	int lon1 = longCadena (cad1);
	int lon2 = longCadena (cad2);
	char *cadFinal = (char *) malloc (lon1+lon2+ 1); 
	int i;
	int j;

	for (i = 0; i < lon1; i++)
	{
		cadFinal[i] = cad1[i];		
	}

	for (j = 0; j <= lon2; j++)
	{
		cadFinal[i] = cad1[j];
		i++;		
	}

	return cadFinal;

}

char *asignarCadena (char *cad, char c)
{
	int i, j;
	int l = longCadena (cad);
	char *cadDestino = (char *) malloc (l+ 1); 

	for (i = 0; i < l; i++)
	{
		cadDestino[i] = cad[i];		
	}
	for (j = 0; j < l; j++)
	{
		cadDestino[i] = c;		
	}

	return cadDestino;

}


char* haciaMayusculas (char *cadOrigen)
{
	int n = longCadena(cadOrigen);
	char* cadDestino = (char *) malloc (n+1);
	cadDestino = cadOrigen;
	char c, nc;  // c = car nc = nuevo car
	int i;

	for (i = 0 ; i < n; i++)
	{
		c = cadOrigen[i];
		nc = c - 32;
		cadDestino[i] = nc;
	}

	return cadDestino;
}


int existecar (char *cad, char car)
{
	int n = longCadena(cad);
	int i;

	for (i = 0 ; i < n; i++)
	{
		if (cad[i] == car)
		{
			return 1;
		}
	}

	return 0;
}

int posInicar (char *cad, char car)
{
	int n = longCadena(cad);
	int i;

	for (i = 0 ; i < n; i++)
	{
		if (cad[i] == car)
		{
			return i;
		}
	}

	return -1;
}

int posFincar (char *cad, char car)
{
	int n = longCadena(cad);
	int i, j;

	for (i = n ; i >= 0; i--)
	{
		if (cad[i] == car)
		{
			return i;
		}
	}

	return -1;
}

int main()
{
	int opcion;
	
	printf("Digte la opcion que desea ejecutar:\n");
	printf("La opcion 1: Longitud de una cadena\n");
	printf("La opcion 2: Copiar una cadena\n");
	printf("La opcion 3: Copiar n caracteres de la cadena\n");
	printf("La opcion 4: Copiar una subcadena\n");
	printf("La opcion 5: Comparar cadenas\n");
	printf("La opcion 6: Concatenar cadenas\n");
	printf("La opcion 7: Cambiar caracteres de la cadena\n");
	printf("La opcion 8: Cambiar caracteres a mayusculas\n");
	printf("La opcion 9: Existe el caracter\n");
	printf("La opcion 10: Posición inicla de un caracter\n");
	printf("La opcion 11: Posición final de un caracter\n\n");
	
	scanf("%d",&opcion);
	char * cadena = (char*) malloc ((sizeof(char))*10);
	printf(" Escriba una palabra o oracion\n");
	scanf("%s",cadena);


	if (opcion == 1)
	{
		int n = longCadena(cadena);
		printf("La longuitud de la palabra es: %d\n",n);
		
	}

	if (opcion == 2)
	{
		char *cad1;
		int n = longCadena(cadena);
		cad1 = (char*) malloc (n+1);
		copiarcadena(cadena,cad1);
		printf("%s > > > %s\n",cadena,cad1);
	}
	
	if (opcion == 3)
	{
		char *cad1 = (char*) malloc((sizeof(char))*10);
		char* c;
		int n = longCadena(cadena);
		cad1 = (char*) malloc(n+1);
		c = copiarN(cadena,cad1);
		printf("%s\n",c);
	}

	if (opcion == 4)
	{
		int m;
		int n;
		printf("Escribir desde que posicion \n");
		scanf("%d",&n);
		printf("Escribir  hasta que posicion \n");
		scanf("%d",&m);
		char *cadDestino = (char *) malloc ((m-n) + 1);
		char *cadsub = (char *) malloc ((m-n) + 1);
		cadsub = copiarSub (cadena , cadDestino, n,m);
		printf("%s\n",cadsub );
	}

	if (opcion == 5)
	{
		char *cad1 = (char*) malloc( (sizeof(char)) *10);
		cadena = cad1;
		char *cad2 = (char*) malloc( (sizeof(char)) *10);
		printf("Escribir la segunda cadena \n" );
		scanf ( "%s", cad2);
		int longc2 = longCadena(cad2);
		int comparacion = compararCadenas(cad1,cad2);
		printf("%d\n",comparacion );
	}

	if (opcion == 6)
	{
		char cadinicial[80];
		printf("Escribir la segunda cadena \n" );
		scanf ( "%s", cadinicial);
		int lon = longCadena(cadinicial);
		char *cadFinal = (char*) malloc(lon+1);
		cadFinal = concatenarCadenas(cadena,cadFinal);
		printf("%s\n",cadFinal);
	}

 	 if (opcion == 7)
	{
		char caracter;
		printf("Escribir el caracter \n" );
		scanf ( "%s", &caracter);
		int l = longCadena(cad);
		char *cad2 =(char*) malloc (l +1);
		cad2 = asignarCadena(cad, caracter);
		printf("%s\n", cad2 );	
	}

	if (opcion == 8)
	{
		int l = longCadena(cad);
		char *cad2 =(char*) malloc (l +1);
		cad2 = haciaMayusculas(cad);
		printf("%s\n", cad2 );
	}

	if (opcion == 9)
	{
		char c;
		printf("Escribir el caracter \n" );
		scanf ( "%s", &c);		
		int existe = existecar(cad, c);
		printf("%d\n", existe);
	}

	if (opcion == 10)
	{
		char c;
		printf("Escribir el caracter \n" );
		scanf ( "%s", &c);		
		int posini = posInicar(cad, c);
		printf("%d\n", posini);
	}

	if (opcion == 11)
	{
		char c;
		printf("Escribir el caracter \n" );
		scanf ( "%s", &c);		
		int posfi = posFincar(cad, c);
		printf("%d\n", posfi );
	}

	return 0;
}