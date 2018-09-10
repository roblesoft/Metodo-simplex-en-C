#include <stdio.h>
#include <stdlib.h>
#include "metodoSimplex.h"

void leerDatos(double matrix[MAX][MAX]){
	extern int FILAS;
	extern int COLUMNAS;
	printf("\t\t===Introduzca la matriz===\n\n\n");
	for( int i = 0; i < FILAS; i ++ ){
		if( i == FUNCIONOBJETIVO )
			printf("\t\t===FUNCION OBJETIVO===\n");
		if ( i == 1 )
			printf("\t\t===SUJETO A===\n");
		for( int j = 0; j < COLUMNAS; j++ ){
			printf("Dato[%d][%d] = ", i + 1, j + 1);
			scanf("%lf", &matrix[i][j]);
		}
	}
}
