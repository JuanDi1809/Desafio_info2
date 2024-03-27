#ifndef CONFIGURARCERRADURAS_H
#define CONFIGURARCERRADURAS_H
/**
 * @brief arrayMatrices
 * @param arrayLock
 * @param dimension
 * @return
 */
int ***arrayMatrices(int arrayLock[], int dimension);

/**
 * @brief comparisonArray
 * @param originalMatrix
 * @param matrixChange
 * @param posComparisonValue
 * @param array
 * @return
 */
int  **comparisonArray(int **originalMatrix, int **matrixChange, int posComparisonValue, int array[]);

/**
 * @brief comparisonCenterCoord
 * @param fil
 * @param col
 * @return
 */
bool comparisonCenterCoord (int fil,int col );
#endif // CONFIGURARCERRADURAS_H
