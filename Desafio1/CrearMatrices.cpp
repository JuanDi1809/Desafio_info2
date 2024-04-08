#include <iostream>
//int countRotationsValue = 0;

int **createMatrix(int dimension){

    int **newMatrix = new int *[dimension];
    int centerCoord = dimension / 2, value = 1;

    for(int i = 0; i < dimension; i++){
        newMatrix[i] = new int[dimension];

        for(int j = 0; j < dimension; j++){
            if(i == centerCoord && j == centerCoord){
                newMatrix[i][j] = 0; //cambio
            }else{
                newMatrix[i][j] = value;
                value++;
            }
        }
    }
    return newMatrix;
}

void deleteMatrix(int **matrix, int dimension){
    for(int i = 0; i < dimension; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}

void deleteArrayLock(int ***arrayLock, int dimension) {
    for (int i = 0; i < dimension - 1; i++) {
        for (int j = 0; j < dimension - 1; j++) {
            delete[] arrayLock[i][j];
        }
        delete[] arrayLock[i];
    }
    delete[] arrayLock;
    arrayLock = nullptr;
}

int **changeMatrix(int **defaultMatrix, int dimension){

    int **rotatedMatrix = new int *[dimension];
    int staticColumns = dimension-1;

    for(int i = 0; i < dimension; i++){
        rotatedMatrix[i] = new int[dimension];
        for(int j = 0; j < dimension; j++){
            rotatedMatrix[i][j] = defaultMatrix[j][staticColumns];
        }
        staticColumns--;
    }

    return rotatedMatrix;
}

void showMatrix(int **matrix, int dimension){

    for(int i = 0; i < dimension;i++){
        for(int j = 0; j < dimension; j++){
            std::cout << matrix[i][j] << ' ';
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

int **copyMatrix (int **originalMatrix, int dimension){
    int **copiedMatrix = createMatrix(dimension);

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            copiedMatrix[i][j] = originalMatrix[i][j];
        }
    }
    return copiedMatrix;
}
