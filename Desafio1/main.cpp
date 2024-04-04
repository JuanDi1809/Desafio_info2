#include <iostream>
#include "ConfigurarCerraduras.h"
#include "CrearCerradura.h"
#include "CrearMatrices.h"

int main(){

    int key[] = {4,3,1,-1,-1};
    int *ptrKey = key;
    int const keyDimension = 5;
    int index = 0;

    int ***arrayLocks = arrayCreateMatrix(keyDimension);
    int fila = ptrKey[0] - 1;
    int columna = ptrKey[1] - 1;
    int dimension = expandedVerify(fila, columna);
    int **matrix = createMatrix(dimension);
    int **originalMatrix = matrix;

    for(int i = 2; i < keyDimension; i++){};


    return 0;

}


