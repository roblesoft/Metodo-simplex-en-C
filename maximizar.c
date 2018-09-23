#include <stdio.h>
#include "metodoSimplex.h"

double mas_menor_columnas = 0;
double mas_menor_filas = 100;
double menor_de_filas;
int columna_pivote, fila_pivote;
double pivote, pivote_de_fila;
int vars[MAX];
int numero_de_tabla = 0;

void variablesBasicas(int vars[MAX]){
	extern int COLUMNAS;
	extern int variables_de_decision;
	for( int i = 0; i < COLUMNAS - 1; i++){
			/* las variables de decision se inician en 0 por ser no basicas */
			if(i < variables_de_decision)
				vars[i] = 0;
			else // y las de holgura o excendete con 1 por ser basicas 
				vars[i] = 1;
		}
}

void maximizar( double matrix[MAX][MAX]){
	extern int FILAS;
	extern int COLUMNAS;
	extern int variables_de_decision;
	mas_menor_columnas = 0;
	mas_menor_filas = 100;
	++numero_de_tabla;

	/* las variables basicas se representan con 1 en su posicion
	   y las no basicas con 0 */
	if( numero_de_tabla == 1)
		variablesBasicas(vars);
	

	/* Encuentra el numero mas negativo de la funcion objetivo  para obtener la columna pivote*/
	for( int i = 0; i < COLUMNAS - 1; i++ ){
		if( matrix[FUNCIONOBJETIVO][i] < 0 ){
			if(  matrix[FUNCIONOBJETIVO][i] < mas_menor_columnas ){
				columna_pivote = i;
				mas_menor_columnas = matrix[FUNCIONOBJETIVO][i];
			}
		}
	}

	// si el valor de la variable mas_menor_columnas sigue siendo significa que el algoritmo a terminado 
	if( mas_menor_columnas == 0 )
		goto terminacion;

	//la columna pivote que entra se convierte en variable basica
	vars[columna_pivote] = 1;
	for( int i = 0; i < COLUMNAS -1; i++)
		printf("vars[%d] = %d", i, vars[i]);
	printf("\n");

	/* Encuentra la fila pivote */
	for( int i = 1; i < FILAS; i++ ){
		/* se comprueba que el columan pivote y el coeficiente de las variables basicas sean mayores que 0 */
		if( matrix[i][COLUMNAS - 1] > 0 && matrix[i][columna_pivote] > 0){ 
			menor_de_filas = matrix[i][COLUMNAS - 1] / matrix[i][columna_pivote];
			if( menor_de_filas < mas_menor_filas ){ 
				mas_menor_filas = menor_de_filas; 
				fila_pivote = i; 
			}
		}
	}

	// si la variable mas_menor_filas sigue siendo 100 significa que el PL tiene una solucion no acotada 
	// ya que las variables debajo de la variable de entrada tienen coefieciente negativo
	if( mas_menor_filas == 100)
		goto solucionNoAcotada;

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
	//muestra la siguiente tabla si hay otra iteracion 
	printf("\t========Tabla #%d========\n",numero_de_tabla);
	impresionDeDatos(matrix);

	/* Verifica que no haya numero menor a cero en la funcion objetivo */
	for( int i = 0; i < COLUMNAS; i++ )
		if( matrix[FUNCIONOBJETIVO][i] < 0 )//si sigue habiendo numeros negativos en el renglon 0 el algoritmo se vuelve a ejecutar
			maximizar(matrix);

	solucionNoAcotada:
		if( mas_menor_filas == 100)
			printf("Solucion no acotada\n");

	for( int i = 0; i < variables_de_decision ; i++){
		if( vars[i] == 0 && matrix[FUNCIONOBJETIVO][i] == 0)
			printf("Solucion multiple\n");
	}

	terminacion: 
		printf("terminacion\n");
}
