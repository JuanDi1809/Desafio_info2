#ifndef CREARMATRICES_H
#define CREARMATRICES_H

/**
 * @brief createMatrix
 * @param dimension
 * @return
 */
int **createMatrix(int dimension);

/**
 * @brief deleteMemoryUsed
 * @param matrix
 * @param dimension
 */
void deleteMemoryUsed(int **matrix, int dimension);

/**
 * @brief changeMatrix
 * @param defaultMatrix
 * @param dimension
 * @return
 */
int **changeMatrix(int **defaultMatrix, int dimension);

void showMatrix(int **matrix, int dimension);
#endif // CREARMATRICES_H
