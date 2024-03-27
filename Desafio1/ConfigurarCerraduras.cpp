#include <iostream>
#include "CrearMatrices.h"

int dimension = 0;
bool verifyCenter;

int ***arrayMatrices(int arrayLock[], int dimension){
    int ***matrices = new int**[dimension];

    for(int i = 0; i < dimension; i++){
        matrices[i] = createMatrix(arrayLock[i]);
    }

    return matrices;
}


bool comparisonCenterCoord (int fil,int col ){
    int centerCoord = dimension/2;

    if(fil == col  && fil == centerCoord){
        return true;
    }

    return false;
}

int  **comparisonArray(int **originalMatrix, int **matrixChange, int posComparisonValue, int array[]){
    //Funcion que compara los valores de las matrices respecto a la clave

    int fil = array[0], col = array[1]; //Fila y columna en donde esta el valor en cada matriz
    verifyCenter = comparisonCenterCoord(fil, col);

    switch(posComparisonValue){

    case -1:
        if(originalMatrix[fil][col] < matrixChange[fil][col]){
            return matrixChange;
        }
        return nullptr;

    case 0:
        if(originalMatrix[fil][col] == matrixChange[fil][col]){
            return matrixChange;
        }
        return nullptr;

    case 1:
        if(originalMatrix[fil][col] > matrixChange[fil][col]){
            return matrixChange;
        }
        return nullptr;

    default:
        return nullptr;
    }
}




