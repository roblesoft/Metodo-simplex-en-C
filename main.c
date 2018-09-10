#include <stdio.h>
#include "metodoSimplex.h"

int FILAS, COLUMNAS, operacion; 

int main(){
	printf("Metodo Siplex\n");
	printf("De cuantas filas es la matriz?\n");
	scanf("%d", &FILAS);
	printf("De cunatas columnas es la matriz?\n");
	scanf("%d", &COLUMNAS);
	int matrix[FILAS][COLUMNAS];
	leerDatos(matrix); 
	printf("Desea Maximizar, o Minimizar");
	scanf("%d", &operacion);
	if( operacion == 1 ){
		maximizar( matrix );
	}
	impresionDeDatos(matrix);
	return 0;
}
