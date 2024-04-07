#include <iostream>
#include "ConfigurarCerraduras.h"
#include "CrearCerradura.h"
#include "CrearMatrices.h"

int newAmplifyMatrix = 0;

int main(){

    const int MINDIMENSION = 3;
    int dimension = expandedVerify(MINDIMENSION);
    int **originalMatrix = createMatrix(dimension);
    int **matrix = copyMatrix(originalMatrix, dimension);
    int ***arrayLock = arrayCreateMatrix(dimension);


    int *key = createKeyArray(dimension); //Recibe de la dimension de la matriz para verificar que la fila y columna que ingresa en la llave no se salga
    const int keyDimension = findKeyDimension();
    int fila = key[0] - 1;
    int columna = key[1] - 1;

    for(int i = 2; i < keyDimension; i++){
        int posComparisonValue = key[i];

        if(posComparisonValue == 1){
            if(matrix[fila][columna] == 1){
                std::cout << "No hay cerradura";
                break;
            }
            else{
                value1(originalMatrix, matrix, arrayLock, &fila, &columna, &dimension, posComparisonValue);
                newAmplifyMatrix = returnAmplifyMatrix();
                if(newAmplifyMatrix == 2){
                    std::cout << "No se puede crear cerradura";
                    break;
                }
                newAmplifyMatrix = 0;
            }

        }
        else if(posComparisonValue == -1){
            valueMinus1(originalMatrix, matrix, arrayLock, &fila, &columna, &dimension, posComparisonValue);
            showMatrix(matrix, dimension);
        }
        else{
            valueisZero(originalMatrix, arrayLock);
        }

    }

    // Liberar memoria de originalMatrix
    deleteMatrix(originalMatrix, dimension);

    // Liberar memoria de matrix
    deleteMatrix(matrix, dimension);

    // Liberar arrayLock
    deleteArrayLock(arrayLock, dimension);

    // Liberar key
    delete[] key;

}


