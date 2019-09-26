#include <stdio.h>
#include <stdlib.h>

int n, c, i, j, interpolar;
double valor, elemento, producto, suma, Xmed;

int main(int argc, char *argv[]) 
{
	printf("\nBIENVENIDO AL CALCULO DE LA DERIVADA PARA DATOS TABULADOS\n");
	printf("Ingrese el Numero de puntos\n");
	scanf("%i", &n);

	double x[n];
	double y[n];

	c=1;
	for(i=0; i<n; i++) //Peticion de puntos
	{
		printf("\nIngrese X%i\n", c);
		scanf("%lf", &elemento);
		x[i]=elemento;
		
		printf("\nIngrese Y%i\n", c);
		scanf("%lf", &elemento);
		y[i]=elemento;
		c++;
	}

	system("cls");
	
	
	//Construimos las diferencias Divididas
	double Diferencias[n][n];
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			Diferencias[i][j]=0;	//Inicializamos la matriz con ceros
		}
	}
	
	for(i=0; i<n; i++)
	{
		Diferencias[i][0]=y[i];
	}
	
	for(i=1; i<n; i++)
	{
		for(j=1; j<=i; j++)
		{
			Diferencias[i][j]=(Diferencias[i][j-1]-Diferencias[i-1][j-1])/(x[i]-x[i-j]);
		}
	}
	
	//Imprimimos 
	printf("\tX");
	for(i=1; i<4; i++)
	{
		printf("\tDerivada %i", i);
	}
	printf("\n");

	for(i=1; i<n; i++)
	{
		Xmed=(x[i]+x[i-1])/2;
		printf("\t%g", Xmed);
		
		for(j=1; j<=4; j++)
		{
			printf("\t%g", Diferencias[i][j]);
		}
		
		printf("\n");
	}


	system("PAUSE");
	return 0;
}	
