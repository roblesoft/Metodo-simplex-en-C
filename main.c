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
int variables_de_decision;
int variables_artificiales;

int main(){
	printf("Metodo Simplex\n");
	printf("De cuantas filas es la matriz?\n");
	scanf("%d", &FILAS);
	printf("De cunatas columnas es la matriz?\n");
	scanf("%d", &COLUMNAS);
	printf("Cuantas variables de decision tiene?\t");
	scanf("%d", &variables_de_decision);
	printf("Hay variables artificiales?(si: 1/ no: 0)\n");
	scanf("%d", &variables_artificiales);
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
	return 0;
}
