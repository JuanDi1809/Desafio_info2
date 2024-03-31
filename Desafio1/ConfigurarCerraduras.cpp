#include <iostream>
#include "CrearMatrices.h"

int dimension = 0;
bool verifyCenter;

int ***arrayCreateMatrix(int *arrayKey, int dimension){

    int numbofMatrix = dimension - 1;
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






