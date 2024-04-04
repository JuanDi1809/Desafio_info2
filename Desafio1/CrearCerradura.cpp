#include <iostream>

bool onEdge(int fila, int columna, int dimension) {
    return (fila == 0 || fila == dimension - 1 || columna == 0 || columna == dimension - 1);
}

bool comparisonCenterCoord (int fil,int col, int dimension ){
    int centerCoord = dimension/2;

    if(fil == col  && fil == centerCoord){
        return true;
    }

    return false;
}

int dimensionMatrix(int fil, int col){
    if(fil > col || fil==col){
        ++fil;
        if(fil % 2 == 0){
            return ++fil;
        }
        return fil;
    }
    else if(fil < col) {
        ++col;
        if(col % 2 == 0){
            return ++col;
        }
        return col;
    }
    else if(fil == 0 || col == 0){
        return 3;
    }
}


int expandedVerify(int fil, int col){
    int dimension = dimensionMatrix(fil, col);
    int verify;

    do{
        std::cout << "Deseas que la matriz sea " << dimension << "*" << dimension << " 0 (no) y 1 (si): ";
        std::cin >> verify;
        if(verify == 1 ){
            return dimension;
        }
        else{
            dimension += 2;
        }

    }while(verify == 1);

    return dimension;
}

int  **comparisonMatrix(int **originalMatrix, int **matrixChange, int posComparisonValue, int fil, int col){

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


