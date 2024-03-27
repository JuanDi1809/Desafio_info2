#include <iostream>

int  **comparisonArray(int **originalMatrix, int **matrixChange, int posComparisonValue, int array[]);
int **changeMatrix(int **defaultMatrix, int dimension);
int **createMatrix(int dimension);

int main()
{
    int arr[] = {1,0,1,1};
    int **dataMatrix = createMatrix(3);
    int **dataMatrixChange = changeMatrix(dataMatrix, 3);

    int **validMatrix = comparisonArray(dataMatrix, dataMatrixChange, -1, arr);

    if(validMatrix == nullptr){
        std::cout << "Hola mundo";
    }



}



int **createMatrix(int dimension){
    //Función encargada de crear una matriz de cualquier dimensión
    //recibe un dato entero que especifica la dimensión de la matriz
    //retorna la matriz creada

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

int **changeMatrix(int **defaultMatrix, int dimension){
    //Esta función se encarga de hacer el giro de la matriz 90 grados
    //recibe un puntero que apunta a un array de arrays
    //retorna la matriz modificada

    int **oldMatrix = createMatrix(dimension);

    int staticColumns = dimension-1;
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            *(*(defaultMatrix+i)+j) = *(*(oldMatrix+j)+staticColumns);
            //cambio de valores con un valor estatico
        }
        staticColumns--;
    }
    return defaultMatrix;
}

int  **comparisonArray(int **originalMatrix, int **matrixChange, int posComparisonValue, int array[]){
    //Funcion que compara los valores de las matrices respecto a la clave

    int fil = array[0], col = array[1]; //Fila y columna en donde esta el valor en cada matriz
    //verifyCenter = comparisonCenterCoord(fil, col);

    switch(posComparisonValue){

    case -1:
        if(originalMatrix[fil][col] < matrixChange[fil][col]){
            return matrixChange;
        }

    case 0:
        if(originalMatrix[fil][col] == matrixChange[fil][col]){
            return matrixChange;
        }

    case 1:
        if(originalMatrix[fil][col] > matrixChange[fil][col]){
            return matrixChange;
        }

    default:
        return nullptr;
    }
}
