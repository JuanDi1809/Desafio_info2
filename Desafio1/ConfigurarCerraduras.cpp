#include <iostream>
#include "CrearMatrices.h"

int dimension = 0;
bool verifyCenter;

int ***arrayCreateMatrix(int *arrayKey){

    int numbofMatrix = sizeof(arrayKey)/sizeof(arrayKey[0]) - 1;
    int ***matrices = new int **[numbofMatrix];

    return matrices;
}

void addMatrix(int ***arrayMatrix, int **newMatrix, int index ){ //El valor del index lo ponemos en el ciclo donde verificamos si la matriz es valida para agregar
    arrayMatrix[index] = newMatrix;
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




