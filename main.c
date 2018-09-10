/*************************************************

			PROGRAMA::Metodo Simplex
			PROPOSITO::resolver un problema de 
					   programacion lineal 
					   utilizando el metodo 
					   simplex
			AUTOR:: URIEL R
			FECHA::9/9/18 23:12:38

*************************************************/
#include <stdio.h>
#include "metodoSimplex.h"

int FILAS, COLUMNAS, operacion; 

int main(){
	printf("Metodo Simplex\n");
	printf("De cuantas filas es la matriz?\n");
	scanf("%d", &FILAS);
	printf("De cunatas columnas es la matriz?\n");
	scanf("%d", &COLUMNAS);
	/* se declara la matriz */
	double matrix[FILAS][COLUMNAS];
	leerDatos(matrix); 
	impresionDeDatos(matrix);
	printf("Desea Maximizar, o Minimizar\n");
	scanf("%d", &operacion);
	if( operacion == 1 ){
		/* se hace el metodo simplex para maximizar */
		maximizar( matrix );
	}
	impresionDeDatos(matrix);
	return 0;
}
