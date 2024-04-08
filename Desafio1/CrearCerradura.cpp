#include <iostream>
#include "CrearMatrices.h"
#include "ConfigurarCerraduras.h"

int index = 0;
int amplifyMatrix = 0;
int reduceMatrix = 0;
int countArray = 2;

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

int findKeyDimension(){
    return countArray;
}

int expandedVerify(int dimension){
    int verify;
    bool continueLoop = true;

    do {
        std::cout << "Deseas que la matriz sea " << dimension << "*" << dimension << " 0 (no) y 1 (si): ";
        std::cin >> verify;

        while(std::cin.fail()) {
            std::cout << "Error: entrada no valida";
            continueLoop = false;
        }

        if (verify == 1) {
            return dimension;
        } else if(verify == 0){
            dimension += 2;
          }
        else{
            std::cout << "Error: entrada no valida" << std::endl;
        }

    } while (continueLoop);

    return dimension;
}

int  **comparisonMatrix(int **originalMatrix, int **matrixChange, int posComparisonValue, int fil, int col){

    switch(posComparisonValue){

    case -1:
        if(amplifyMatrix == 0){
            if(originalMatrix[fil][col] < matrixChange[fil][col]) return matrixChange;
        }else{
            if(originalMatrix[fil - 1][col - 1] < matrixChange[fil][col]) return matrixChange;
        }
        return nullptr;

    case 0:
        if(originalMatrix[fil][col] == matrixChange[fil][col]){
            return matrixChange;
        }
        return nullptr;

    case 1:

        if(amplifyMatrix == 0 && reduceMatrix == 0){
            if(originalMatrix[fil][col] > matrixChange[fil][col]) return matrixChange;
        }
        else if(amplifyMatrix == 1){
            if(originalMatrix[fil - 1][col - 1] > matrixChange[fil][col]) return matrixChange;
        }
        else if(reduceMatrix == -1){
            if(originalMatrix[fil + 1][col + 1] > matrixChange[fil][col]) return matrixChange;
        }

        return nullptr;

    default:
        return nullptr;
    }
}
int* createKeyArray(int dimension) {
    // Solicitar al usuario los dos primeros valores menores o iguales a dimension
    int firstValue, secondValue;
    do {
        std::cout << "Ingrese el primer valor (menor o igual a " << dimension << "): ";
        std::cin >> firstValue;
    } while (firstValue > dimension);

    do {
        std::cout << "Ingrese el segundo valor (menor o igual a " << dimension << "): ";
        std::cin >> secondValue;
    } while (secondValue > dimension);

    // Creamos un puntero al arreglo con espacio para los dos primeros elementos
    int* array = new int[2];
    array[0] = firstValue;
    array[1] = secondValue;
    int tamanio = 2;

    // Variable para almacenar la respuesta del usuario
    char answer;

    // Bucle para solicitar nuevos datos al usuario
    do {
        // Solicitar nuevo dato al usuario
        int newDate;
        do {
            std::cout << "Ingrese un nuevo numero (-1, 0, 1): ";
            std::cin >> newDate;
        } while (newDate != -1 && newDate != 0 && newDate != 1);

        // Redimensionar el arreglo para agregar el nuevo dato
        int* newArray = new int[tamanio + 1];
        for (int i = 0; i < tamanio; ++i) {
            newArray[i] = array[i];
        }
        newArray[tamanio] = newDate;
        countArray++;
        // Actualizar puntero al nuevo arreglo
        array = newArray;
        ++tamanio;

        // Preguntar al usuario si desea ingresar otro dato
        std::cout << "¿Desea ingresar nuevo numero? S para si, N para no: ";
        std::cin >> answer;
    } while (answer == 'S' || answer == 's');

    return array;
}


int **value1(int **originalMatrix, int **matrix, int ***arrayLock, int *fila, int *columna, int *dimension, int posComparisonValue){
    int contRotatedMatrix = 0;

    if(onEdge(*fila, *columna, *dimension) || *dimension == 3){

        while(contRotatedMatrix < 3){
            matrix = changeMatrix(matrix, *dimension);
            contRotatedMatrix++;

            int **verifyMatrix = comparisonMatrix(originalMatrix, matrix, posComparisonValue, *fila, *columna);

            if(verifyMatrix != nullptr){
                addMatrix(arrayLock, verifyMatrix);
                index++;
                return verifyMatrix;

            }

            if(contRotatedMatrix == 3){
                amplifyMatrix++;

                if(amplifyMatrix == 2) break;

                //aqui se determina cuando se amplia
                contRotatedMatrix = 0;
                *dimension+=2;
                *fila += 1;
                *columna += 1;

                matrix = createMatrix(*dimension);
                int **verifyMatrix = comparisonMatrix(originalMatrix, matrix, posComparisonValue, *fila , *columna);

                if(verifyMatrix != nullptr){
                    addMatrix(arrayLock, verifyMatrix);
                    index++;
                    amplifyMatrix = 0;
                    return verifyMatrix;
                }
            }
        }
    }

    else{
        while(contRotatedMatrix < 3){
            matrix = changeMatrix(matrix, *dimension);
            contRotatedMatrix++;

            int **verifyMatrix = comparisonMatrix(originalMatrix, matrix, posComparisonValue, *fila, *columna);

            if(verifyMatrix != nullptr){
                addMatrix(arrayLock, verifyMatrix);
                index++;
                return verifyMatrix;

            }

            if(contRotatedMatrix == 3){
                reduceMatrix -= 1;

                //aqui se determina cuando se reduce
                contRotatedMatrix = 0;
                *dimension -= 2;
                *fila -= 1;
                *columna -= 1;

                matrix = createMatrix(*dimension);
                int **verifyMatrix = comparisonMatrix(originalMatrix, matrix, posComparisonValue, *fila , *columna);

                if(verifyMatrix != nullptr){

                    addMatrix(arrayLock, verifyMatrix);
                    index++;
                    reduceMatrix = 0;
                    return verifyMatrix;
                }
            }
        }
    }
}

int returnAmplifyMatrix(){
    return amplifyMatrix;
}

int **valueMinus1(int **originalMatrix, int **matrix, int ***arrayLock, int *fila, int *columna, int *dimension, int posComparisonValue){
    int contRotatedMatrix = 0;
    while(contRotatedMatrix < 3){
        matrix = changeMatrix(matrix, *dimension);
        contRotatedMatrix++;

        int **verifyMatrix = comparisonMatrix(originalMatrix, matrix, posComparisonValue, *fila , *columna );

        if(verifyMatrix != nullptr){
            addMatrix(arrayLock, verifyMatrix);
            index++;
            return verifyMatrix;
        }

        if(contRotatedMatrix == 3){
            *dimension += 2;
            matrix = createMatrix(*dimension);
            *fila += 1;
            *columna += 1;

            int **verifyMatrix = comparisonMatrix(originalMatrix, matrix, posComparisonValue, *fila , *columna);

            if(verifyMatrix != nullptr){

                addMatrix(arrayLock, verifyMatrix);
                index++;
                return verifyMatrix;
            }
        }

    }
    return matrix;
}

void valueisZero(int **originalMatrix, int ***arrayLock){
    addMatrix(arrayLock, originalMatrix);
}
