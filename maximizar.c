#include <stdio.h>
#include "metodoSimplex.h"

int mas_menor_columnas = 0;
float mas_menor_filas = 100;
int columna_pivote, fila_pivote;

void maximizar( int matrix[MAX][MAX]){
	extern int FILAS;
	extern int COLUMNAS;
	while( seguir == 1 ){
		/* Encuentra el numero mas negativo de la funcion objetivo  para obtener la columna pivote*/
		for( int i = 0; i < COLUMNAS; i++ ){
			if( matrix[FUNCIONOBJETIVO][i] < 0 ){
				columna_pivote = i;
				if(  matrix[FUNCIONOBJETIVO][i] < mas_menor_columnas ){
					columna_pivote = i;
					mas_menor = matrix[FUNCIONOBJETIVO][i];
				}
			}
		}
		/* Encuentra la fila pivote */
		for( int i = 1; i < FILAS; i++ ){
			if( matrix[i][FILAS-1] >= 0){
				menor_de_filas = matrix[i][COLUMNAS - 1] / matrix[i][columna_pivote];
				if( menor_de_filas < mas_menor_filas ){
					mas_menor_filas = menor_de_filas;
					filas_pivote = i; 
				}
			}
		}

		/* divide entre la fila pivote entre el pivote */
		for( int i = 0; i < COLUMNAS; i++ )
			matrix[fila_pivote] /= matrix[fila_pivote][columna_pivote];
		
		for( int i = 0; i < FILAS; i++){
			if( !(i == fila_pivote) ){
				for( int j = 0; j < COLUMNAS; j++){
					/*             fila vieja   -   (pivote de la fila   * fila entrantei ) */
					matrix[i][j] = matrix[i][j] - ( matrix[i][columna_pivote] * matrix[fila_pivote][j])
				}
			}
		}
		/* Verifica que no haya numero menor a cero en la funcion objetivo */
		for( int i = 0; i < COLUMNAS; i++ ){
			if( matrix[FUNCIONOBJETIVO][i] )
				seguir = 1;
			else 
				seguir = 0;
		}
	}
}