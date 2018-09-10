#include <stdio.h>
#include "metodoSimplex.h"

void impresionDeDatos(double matrix[MAX][MAX]){
	extern int FILAS;
	extern int COLUMNAS;
	for( int i = 0; i < FILAS; i++){
		for ( int j = 0; j < COLUMNAS; j++ ){
			printf(" | %.2f", matrix[i][j]);
		}
		printf("\n");
	}
}
