#include <stdio.h>
#include <stdlib.h>
#include "metodoSimplex.h"

void leerDatos(double matrix[MAX][MAX]){
	extern int FILAS;
	extern int COLUMNAS;
	printf("Introduzca la matriz en su forma estandar\n");
	for( int i = 0; i < FILAS; i ++ ){
		for( int j = 0; j < COLUMNAS; j++ ){
			printf("Dato[%d][%d] = ", i + 1, j + 1);
			scanf("%lf", &matrix[i][j]);
		}
	}
}
