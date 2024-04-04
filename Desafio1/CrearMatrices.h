#ifndef CREARMATRICES_H
#define CREARMATRICES_H

/**
 * @brief createMatrix Me crea una matriz
 * @param dimension La dimension que va a tener la matriz
 * @return EL puntero a la matriz creada
 */
int **createMatrix(int dimension);

/**
 * @brief deleteMemoryUsed Me libera el espacio de la memoria reservada para la matriz
 * @param matrix EL puntero a la matriz
 * @param dimension La dimension de la matriz
 */
void deleteMemoryUsed(int **matrix, int dimension);

/**
 * @brief changeMatrix Esta funcion me permite rotar una matriz 90 grados a la izquierda
 * @param defaultMatrix Puntero a la matriz que quiero rotar
 * @param dimension Dimension de la matriz
 * @return Puntero a la matriz rotada
 */
int **changeMatrix(int **defaultMatrix, int dimension);

/**
 * @brief showMatrix
 * @param matrix
 * @param dimension
 */
void showMatrix(int **matrix, int dimension);
#endif // CREARMATRICES_H
