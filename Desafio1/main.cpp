#include <iostream>
#include "ConfigurarCerraduras.h"
#include "CrearCerradura.h"
#include "CrearMatrices.h"

int newamplifyMatrix = 0;
int main(){

    const int MINDIMENSION = 3;
    int dimension = expandedVerify(MINDIMENSION);
    int **matrix = createMatrix(dimension);
    int **originalMatrix = matrix;
    int ***arrayLock = arrayCreateMatrix(dimension);


    int *key = createKeyArray(dimension); //Recibe de la dimension de la matriz para verificar que la fila y columna que ingresa en la llave no se salga
    const int keyDimension = findKeyDimension();
    int fila = key[0] - 1;
    int columna = key[1] -1;

    for(int i = 2; i < keyDimension; i++){
        int posComparisonValue = key[i];

        if(posComparisonValue == 1){
            if(matrix[fila][columna] == 1){
                std::cout << "No hay cerradura";
                break;
            }
            else{
                value1(originalMatrix, matrix, arrayLock, &fila, &columna, &dimension, key[i]);
                if(newamplifyMatrix == 2){
                    std::cout << "No se puede crear cerradura";
                    break;
                }
                newamplifyMatrix = 0;
            }

        }
        else if(posComparisonValue == -1){
            std::cout << "comparacion para -1";
        }
        else{
            std::cout << "Comparacion para 0";
        }

    }

}


