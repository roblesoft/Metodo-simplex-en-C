#include <stdio.h>
#include "metodoSimplex.h"

void impresionDeDatos(double matrix[MAX][MAX]){
	extern int FILAS;
	extern int COLUMNAS;
	for( int i = 0; i < FILAS; i++){
		if( i == 0 ){
			for( int w = 0; w < COLUMNAS; w++ ){
				if( w == 0 )
					printf("\t\t  ");
				printf("----------------");
			}
			printf("\n");
		}
		for ( int j = 0; j < COLUMNAS; j++ ){
			printf("\t\t | %.2lf", matrix[i][j]);
			if( j == COLUMNAS - 1)
				printf("        |");
		}
		printf("\n");
		for( int w = 0; w < COLUMNAS; w++ ){
			if( w == 0 )
				printf("\t\t  ");
			printf("----------------");
		}
		printf("\n");
	}
}
