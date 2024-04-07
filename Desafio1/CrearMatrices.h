#ifndef CREARMATRICES_H
#define CREARMATRICES_H

/**
 * @brief createMatrix Me crea una matriz
 * @param dimension La dimension que va a tener la matriz
 * @return La matriz creada
 */
int **createMatrix(int dimension);

/**
 * @brief deleteMatrix Libera la memoria que he asignado de forma dinamica a las matrices
 * @param matrix La matriz que quiero liberar
 * @param dimension La dimension de la matriz
 */
void deleteMatrix(int **matrix, int dimension);

/**
 * @brief deleteArrayLock Libera la memoria que he asignado de forma dinamica a al arreglo de matrices
 * @param arrayLock El arreglo tridimensional que se quiere liberar
 * @param dimension Dimenison del arreglo
 */
void deleteArrayLock(int ***arrayLock, int dimension);

/**
 * @brief changeMatrix Esta funcion me permite rotar una matriz 90 grados a la izquierda
 * @param defaultMatrix La matriz que quiero rotar
 * @param dimension Dimension de la matriz
 * @return La matriz rotada
 */
int **changeMatrix(int **defaultMatrix, int dimension);

/**
 * @brief copyMatrix Me genera una copia de una matriz
 * @param originalMatrix La matriz a la que le quiero hacer la copia
 * @param dimension Dimension de la matriz
 * @return
 */
int **copyMatrix (int **originalMatrix, int dimension);

/**
 * @brief showMatrix Me muestra el contenido de la matriz
 * @param matrix La matriz a la que quiero ver el contenido
 * @param dimension Dimension de la matriz
 */
void showMatrix(int **matrix, int dimension);
#endif // CREARMATRICES_H
