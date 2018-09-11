#include <stdio.h>
#include "metodoSimplex.h"

double mas_menor_columnas = 0;
double mas_menor_filas = 100;
double menor_de_filas;
int columna_pivote, fila_pivote;
double pivote, pivote_de_fila;
int seguir = 1;

void maximizar( double matrix[MAX][MAX]){
	extern int FILAS;
	extern int COLUMNAS;
		/* Encuentra el numero mas negativo de la funcion objetivo  para obtener la columna pivote*/
	mas_menor_columnas = 0;
	mas_menor_filas = 100;
	for( int i = 0; i < COLUMNAS - 1; i++ ){
		if( matrix[FUNCIONOBJETIVO][i] < 0 ){
			if(  matrix[FUNCIONOBJETIVO][i] < mas_menor_columnas ){
				columna_pivote = i;
				mas_menor_columnas = matrix[FUNCIONOBJETIVO][i];
			}
		}
	}

	/* Encuentra la fila pivote */
	for( int i = 1; i < FILAS; i++ ){
		if( matrix[i][COLUMNAS - 1] > 0){ 
			menor_de_filas = matrix[i][COLUMNAS - 1] / matrix[i][columna_pivote];
			if( menor_de_filas < mas_menor_filas ){ 
				mas_menor_filas = menor_de_filas; 
				fila_pivote = i; 
			}
		}
	}

	/* divide entre la fila pivote entre el pivote */
	pivote = matrix[fila_pivote][columna_pivote];
	for( int i = 0; i < COLUMNAS; i++ )
		matrix[fila_pivote][i] =  matrix[fila_pivote][i] / pivote;
		
	for( int i = 0; i < FILAS; i++){
		if( i != fila_pivote ){
			pivote_de_fila = matrix[i][columna_pivote];
			for( int j = 0; j < COLUMNAS; j++){
				 matrix[i][j] = matrix[i][j] - ( pivote_de_fila * matrix[fila_pivote][j]);
			}
		}
	}

	/* Verifica que no haya numero menor a cero en la funcion objetivo */
	for( int i = 0; i < COLUMNAS; i++ )
		if( matrix[FUNCIONOBJETIVO][i] < 0 )
			maximizar(matrix);
}
