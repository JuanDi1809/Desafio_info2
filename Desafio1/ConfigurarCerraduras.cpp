#include <iostream>
#include "CrearMatrices.h"

int ***arrayMatrices(int arrayLock[], int dimension){
    int ***matrices = new int**[dimension];

    for(int i = 0; i < dimension; i++){
        matrices[i] = createMatrix(arrayLock[i]);
    }

    return matrices;
}
