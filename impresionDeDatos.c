#include <stdio.h>
#include "metodoSimplex.h"

void impresionDeDatos(double matrix[MAX][MAX]){
	extern int FILAS;
	extern int COLUMNAS;
	for( int i = 0; i < FILAS; i++){
		if( i == 0 ){
			for( int w = 0; w < COLUMNAS; w++ ){
				if( w == 0 )
					printf("\t");
				printf("----------");
			}
			printf("\n");
		}
		printf("\t");
		for ( int j = 0; j < COLUMNAS; j++ ){
			if(matrix[i][j] >= 100 || matrix[i][j] <= -10)
				printf("| %.2lf  ", matrix[i][j]);
			else if( matrix[i][j] >= 10  || matrix[i][j] < 0)
				printf("| %.2lf   ", matrix[i][j]);
			else if( matrix[i][j] < 10 )
				printf("| %.2lf    ", matrix[i][j]);
			if( j == COLUMNAS - 1){
				if(matrix[i][j] >= 100)
					printf("|", matrix[i][j]);
				else if( matrix[i][j] >= 10 )
					printf("|", matrix[i][j]);
				else if( matrix[i][j] < 10 )
					printf("|", matrix[i][j]);
			}
		}
		printf("\n");
		for( int w = 0; w < COLUMNAS; w++ ){
			if( w == 0 )
				printf("\t");
			printf("----------");
		}
		printf("\n");
	}
}
