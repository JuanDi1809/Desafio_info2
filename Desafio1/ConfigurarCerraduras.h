#ifndef CONFIGURARCERRADURAS_H
#define CONFIGURARCERRADURAS_H

/**
 * @brief arrayCreateMatrix Esta funcion me crea un arreglo de matrices
 * @param dimension La dimension del arreglo de la llave
 * @return El puntero al arreglo de matrices
 */
int ***arrayCreateMatrix( int dimension);

/**
 * @brief addMatrix Es una funcion que me agregra una matriz en un arreglo de matrices
 * @param arrayMatrix El arreglo tridimensional para almacenar matrices resultantes
 * @param newMatrix L matriz a agregar
 */
void addMatrix(int ***arrayMatrix, int **newMatrix);


#endif // CONFIGURARCERRADURAS_H
