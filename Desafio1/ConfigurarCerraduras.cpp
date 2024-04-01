#include <iostream>

int ***arrayCreateMatrix(int dimension){

    int numbofMatrix = dimension - 1;
    int ***matrices = new int **[numbofMatrix];

    return matrices;
}

void addMatrix(int ***arrayMatrix, int **newMatrix, int index ){ //El valor del index lo ponemos en el ciclo donde verificamos si la matriz es valida para agregar
    arrayMatrix[index] = newMatrix;
}








