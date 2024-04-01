#include <iostream>
#include "ConfigurarCerraduras.h"
#include "CrearCerradura.h"
#include "CrearMatrices.h"

int main(){

    int key[] = {4,3,1,-1,1};
    int *ptrKey = key;
    int const keyDimension = 5;
    int index = 0;

    int ***arrayLocks = arrayCreateMatrix(keyDimension);
    int fila = ptrKey[0];
    int columna = ptrKey[1];
    int dimension = dimensionMatrix(fila, columna);
    int **matrix = createMatrix(dimension);
    int **originalMatrix = matrix;
    showMatrix(matrix, dimension);

    addMatrix(arrayLocks, matrix, index);

    for(int i = 2; i < keyDimension; i++){
        int comparisonValue = ptrKey[i];

        if(comparisonValue == -1 || comparisonValue == 1){
            int **verifyMatrix = nullptr;
            int contRotatedMatrix = 1;

            while(verifyMatrix == nullptr){
                int **rotatedMatrix = changeMatrix(matrix, dimension);
                showMatrix(rotatedMatrix,dimension);
                verifyMatrix = comparisonMatrix(originalMatrix, rotatedMatrix, comparisonValue, fila, columna);

                if(verifyMatrix != nullptr){
                    showMatrix(verifyMatrix,dimension);
                    addMatrix(arrayLocks, verifyMatrix, index);
                    matrix = rotatedMatrix;
                    originalMatrix = rotatedMatrix;
                    index++;
                    break;
                }
                else if(contRotatedMatrix < 3){
                    matrix = rotatedMatrix;
                    contRotatedMatrix++;
                }
                else{
                    dimension += 2;
                    matrix = createMatrix(dimension);
                }

            }
        }
        else{
            std::cout << "Hola";
        }
    }



    return 0;

}


