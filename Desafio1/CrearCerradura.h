#ifndef CREARCERRADURA_H
#define CREARCERRADURA_H

/**
 * @brief estaEnBorde Determina si el valor esta en el borde de la matriz
 * @param fila El valor de la fila en donde esta ubicado
 * @param columna El valor en la columna donde esta ubicado
 * @param dimension Dimension de la matriz
 * @return Puede retornar true o false
 */
bool onEdge(int fila, int columna, int dimension);

/**
 * @brief comparisonCenterCoord Analiza si el valor en la matriz esta en el centro
 * @param fil El valor de la fila en donde esta ubicado
 * @param col El valor de la columna en donde esta ubicado
 * @return Pede retornar true o false
 */
bool comparisonCenterCoord (int fil,int col, int dimension );

/**
 * @brief expandedVerify Pregunta al usuario que dimension quiere que sea la matriz
 * @return La dimension de la matriz que el usuario a seleccionado
 */
int expandedVerify(int dimension);

/**
 * @brief comparisonMatrix  Compara dos matrices y devuelve una nueva matriz si se cumple cierta condición
 * @param originalMatrix La matriz original a comparar
 * @param matrixChange La matriz que ha cambiado para la comparación
 * @param posComparisonValue El valor de comparación (1, 0, -1)
 * @param fil  La fila de la matriz a comparar
 * @param col  La columna de la matriz a comparar
 * @return  Una nueva matriz si se cumple la condición de comparación, o nullptr si no
 */
int  **comparisonMatrix(int **originalMatrix, int **matrixChange, int posComparisonValue, int fil, int col,int dimension);

/**
 * @brief createKeyArray Me crea el arreglo de la llave
 * @param dimension La dimension que va a tener la llave
 * @return Arreglo unidimensional que va a tner los valores de la llave
 */
int *createKeyArray(int dimension);

/**
 * @brief findKeyDimension Me envia la dimension de la llave
 * @return Dimension de la llave
 */
int findKeyDimension();

/**
 * @brief value1 Modifica las matrices y realiza operac1iones según el valor de comparación 1
 * @param originalMatrix La matriz original a modificar
 * @param matrix La matriz actual a modificar y comparar
 * @param arrayLock El arreglo tridimensional para almacenar matrices resultantes
 * @param fila El puntero a la fila actual en la matriz
 * @param columna El puntero a la columna actual en la matriz
 * @param dimension El puntero a la dimensión de las matrices
 * @param posComparisonValue El valor de comparación para determinar las operaciones a realizar
 */
void value1(int **originalMatrix, int **matrix, int ***arrayLock, int *fila, int *columna, int *dimension, int posComparisonValue);

int returnAmplifyMatrix();

/**
 * @brief valueMinus1  Modifica las matrices y realiza operac1iones según el valor de comparación 1
 * @param originalMatrix  La matriz original a modificar
 * @param matrix La matriz actual a modificar y comparar
 * @param arrayLock El arreglo tridimensional para almacenar matrices resultantes
 * @param fila  El puntero a la fila actual en la matriz
 * @param columna  El puntero a la columna actual en la matriz
 * @param dimension El puntero a la dimensión de las matrices
 * @param posComparisonValue El valor de comparación para determinar las operaciones a realizar
 */
void valueMinus1(int **originalMatrix, int **matrix, int ***arrayLock, int *fila, int *columna, int *dimension, int posComparisonValue);

/**
 * @brief valueisZero Comparaciones cuando el valor de comparacion es 0, como el valor tiene que ser igual solo agrega la matriz originalMatrix
 * @param originalMatrix La matrizz original a agregar
 * @param arrayLock El arreglo tridimensional para almacenar matrices resultantes
 */
void valueisZero(int **originalMatrix, int ***arrayLock);
#endif // CREARCERRADURA_H
