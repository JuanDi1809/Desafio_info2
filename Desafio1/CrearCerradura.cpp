#include <iostream>
/*
bool comparisonCenterCoord (int fil,int col ){
    int centerCoord = dimension/2;

    if(fil == col  && fil == centerCoord){
        return true;
    }

    return false;
}
*/
int dimensionMatrix(int fil, int col){
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
    //verifyCenter = comparisonCenterCoord(fil, col);

    switch(posComparisonValue){

    case -1:
        if(originalMatrix[fil][col] < matrixChange[fil][col]){
            std::cout << originalMatrix[fil][col] << ' ' << matrixChange[fil][col];
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


