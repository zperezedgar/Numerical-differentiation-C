#include <stdio.h>
#include <stdlib.h>

int n, c, i, j, k, d;
double elemento, Xmed;

int main(int argc, char *argv[]) 
{
	printf("\nBIENVENIDO AL CALCULO DE LA DERIVADA PARA DATOS TABULADOS\n");
	printf("\nIngrese el Numero de Puntos\n");
	scanf("%i", &n);

	FILE* fichero;
	fichero=fopen("resultados.txt","wt");

	double x[]={0,1,2,3,4,5};
	double y[]={0,2,8,18,32,50};
	
	/*c=1;
	for(i=0; i<n; i++) //Peticion de puntos
	{
		printf("\nIngrese X%i\n", c);
		scanf("%lf", &elemento);
		x[i]=elemento;
		
		printf("\nIngrese Y%i\n", c);
		scanf("%lf", &elemento);
		y[i]=elemento;
		c++;
	}*/
	

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
	c=1;
	for(i=0; i<3; i++)	//Hasta la tercera derivada, si queremos mas derivadas solo cambiamos el limite en el for!
	{
		printf("\nX\tDerivada %i\n", c);
		fprintf(fichero,"\nX\tDerivada %i\n", c);
		d=c;
		
		k=1;
		for(j=0; j<(n-c); j++)
		{
			Xmed=(x[d]+x[j])/2;
			d++;
			
		/*	if(Diferencias[j+1][c]==0)
			{
				printf("%g\t\t%g", Xmed, Diferencias[k+i][c]);
			}
			else*/
			printf("%g\t%g", Xmed, Diferencias[k+i][c]);
			fprintf(fichero,"%g\t%g", Xmed, Diferencias[k+i][c]);
			
			printf("\n", c);
			fprintf(fichero,"\n", c);
			k++;
		}
		c++;
	}
	
	printf("\n");
	fclose(fichero);
	
	system("PAUSE");
	return 0;
}	
