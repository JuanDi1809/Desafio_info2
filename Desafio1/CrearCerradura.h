#ifndef CREARCERRADURA_H
#define CREARCERRADURA_H

/**
 * @brief estaEnBorde
 * @param fila
 * @param columna
 * @param filas
 * @param columnas
 * @return
 */
bool onEdge(int fila, int columna, int dimension);

/**
 * @brief comparisonCenterCoord
 * @param fil
 * @param col
 * @return
 */
bool comparisonCenterCoord (int fil,int col, int dimension );

/**
 * @brief dimension Funcion que me crea la dimension de una matriz cuadrada impar
 * @param fil Una fila de la matriz
 * @param col Una columna de la matriz
 * @return La dimension de la matriz
 */
int dimensionMatrix(int fil, int col);

/**
 * @brief expandedVerify
 * @param fil
 * @param col
 * @return
 */
int expandedVerify(int dimension);

/**
 * @brief comparisonMatrix Me compara el valor en la misma posicion de las dos matrices
 * @param originalMatrix El puntero a la matriz original
 * @param matrixChange El puntero de la matriz a la que se ha realizado un cambio
 * @param posComparisonValue El valor para determinar la comparacion entre los valores de las matrices
 * @param fil Fila donde esta el valor en la matriz
 * @param col Columna donde esta el valor en la matriz
 * @return El puntero de la matriz cambiada o un puntero nulo
 */
int  **comparisonMatrix(int **originalMatrix, int **matrixChange, int posComparisonValue, int fil, int col,int dimension);

/**
 * @brief oputa
 * @param k
 * @return
 */
int* createKeyArray(int k);

int findKeyDimension();

/**
 * @brief value1
 * @param originalMatrix
 * @param matrix
 * @param arrayLock
 * @param fila
 * @param columna
 * @param dimension
 * @param posComparisonValue
 */
void value1(int **originalMatrix, int **matrix, int ***arrayLock, int *fila, int *columna, int *dimension, int posComparisonValue);

int returnAmplifyMatrix();

/**
 * @brief valueMinus1
 * @param originalMatrix
 * @param matrix
 * @param arrayLock
 * @param fila
 * @param columna
 * @param dimension
 * @param posComparisonValue
 */
void valueMinus1(int **originalMatrix, int **matrix, int ***arrayLock, int *fila, int *columna, int *dimension, int posComparisonValue);

/**
 * @brief valueisZero
 * @param originalMatrix
 * @param arrayLock
 */
void valueisZero(int **originalMatrix, int ***arrayLock);
#endif // CREARCERRADURA_H
