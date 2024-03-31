#ifndef CONFIGURARCERRADURAS_H
#define CONFIGURARCERRADURAS_H

/**
 * @brief arrayCreateMatrix Esta funcion me crea un arreglo de matrices
 * @param arrayKey El puntero a un arreglo con los valores de la clave
 * @param dimension La dimension del arreglo de la llave
 * @return El puntero al arreglo de matrices
 */
int ***arrayCreateMatrix(int *arrayKey[], int dimension);

/**
 * @brief addMatrix Es una funcion que me agregra una matriz en un arreglo de matrices
 * @param arrayMatrix El puntero al arreglo de matrices
 * @param newMatrix El puntero de la matriz a agregar
 * @param index La posicion en la que va a estar la matriz en el arreglo
 */
void addMatrix(int ***arrayMatrix, int **newMatrix, int index );

/**
 * @brief comparisonCenterCoord
 * @param fil
 * @param col
 * @return
 */
bool comparisonCenterCoord (int fil,int col );

#endif // CONFIGURARCERRADURAS_H
