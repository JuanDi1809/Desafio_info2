#include <iostream>
#include "CrearMatrices.h"
#include <ConfigurarCerraduras.h>

int dimension(int fil, int col){
    if(fil > col){
        if(fil % 2 == 0){
            return ++fil;
        }
        else{
            return fil;
        }
    }
    else if(col % 2 == 0){
        return ++col;
    }
    else{
        return col;
    }
}

int  **comparisonMatrix(int **originalMatrix, int **matrixChange, int posComparisonValue, int fil, int col){
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
