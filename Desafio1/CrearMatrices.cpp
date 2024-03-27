#include <iostream>
int countRotationsValue = 0;

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

void deleteMemoryUsed(int **matrix, int dimension){
    for(int i = 0; i < dimension; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}

/*
int countRotations(){
    //función que se encarga de monitorear las veces que rota la matriz
    //no recibe parametros
    //constantemente se debe llamar para hacer seguimiento usando la variable
    //global

    return countRotationsValue++;
}
*/

int **changeMatrix(int **defaultMatrix, int dimension){
    //Esta función se encarga de hacer el giro de la matriz 90 grados
    //recibe un puntero que apunta a un array de arrays
    //retorna la matriz modificada

    int **rotatedMatrix = new int *[dimension];
    int staticColumns = dimension-1;

    for(int i = 0; i < dimension; i++){
        rotatedMatrix[i] = new int[dimension];
        for(int j = 0; j < dimension; j++){
            rotatedMatrix[i][j] = defaultMatrix[j][staticColumns];
        }
        staticColumns--;
    }
    //countRotations();
    return rotatedMatrix;
}

void showMatrix(int **matrix, int dimension){
    //función que muestra la matriz en consola
    //recibe la dimension de la matriz
    //no retorna datos

    for(int i = 0; i < dimension;i++){
        for(int j = 0; j < dimension; j++){
            std::cout << matrix[i][j] << ' ';
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}
