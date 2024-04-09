#include <iostream>
#include "ConfigurarCerraduras.h"
#include "CrearCerradura.h"
#include "CrearMatrices.h"

int newAmplifyMatrix = 0;

int main(){

    const int MINDIMENSION = 3;
    int size = 0;
    int *arrayDimension = nullptr;
    int dimension = expandedVerify(MINDIMENSION);
    int **originalMatrix = createMatrix(dimension);
    int **matrix = copyMatrix(originalMatrix, dimension);
    int ***arrayLock = arrayCreateMatrix(dimension);
    addMatrix(arrayLock, originalMatrix, 0);


    int *key = createKeyArray(dimension); //Recibe de la dimension de la matriz para verificar que la fila y columna que ingresa en la llave no se salga
    const int keyDimension = findKeyDimension();
    int fila = key[0] - 1;
    int columna = key[1] - 1;

    for(int i = 2; i < keyDimension; i++){
        int posComparisonValue = key[i];

        if(posComparisonValue == 1){
            if(matrix[fila][columna] == 1){
                std::cout << "No se puede crear cerradura";
                break;
            }
            else{
                int **newMatrix = value1(originalMatrix, matrix, arrayLock, &fila, &columna, &dimension, posComparisonValue);
                newAmplifyMatrix = returnAmplifyMatrix();
                if(newAmplifyMatrix == 2){
                    std::cout << "No se puede crear cerradura";
                    break;
                }
                originalMatrix = newMatrix;
                matrix = copyMatrix(originalMatrix, dimension);
                showMatrix(originalMatrix, dimension);
                newAmplifyMatrix = 0;
                arrayDimension = resultDimensionsArray(arrayDimension, size, dimension);
            }

        }
        else if(posComparisonValue == -1){
            int **newMatrix = valueMinus1(originalMatrix, matrix, arrayLock, &fila, &columna, &dimension, posComparisonValue);
            originalMatrix = newMatrix;
            matrix = copyMatrix(originalMatrix, dimension);
            showMatrix(originalMatrix,dimension);
            arrayDimension = resultDimensionsArray(arrayDimension, size, dimension);
        }
        else{
            valueisZero(originalMatrix, arrayLock);
            showMatrix(originalMatrix, dimension);
            arrayDimension = resultDimensionsArray(arrayDimension, size, dimension);
        }

    }

    //muestra el array de las matrices que cumplen cerradura
    std::cout<<"\nDimensiones: "<<std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << arrayDimension[i] << " ";
    }

    //Liberar originalMatrix
    deleteMatrix(originalMatrix, dimension);

    //Liberar matrix
    deleteMatrix(matrix, dimension);


    // Liberar key
    delete[] key;

}


