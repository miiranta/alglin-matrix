#include <iostream>
#include "functions.hpp"
#define MAXSIZE 100

using namespace std;

int main(){

//vars
int i, j;
int size = 1;
float matrixA[MAXSIZE][MAXSIZE], matrixAt[MAXSIZE][MAXSIZE], matrixCo[MAXSIZE][MAXSIZE], matrixInv[MAXSIZE][MAXSIZE], determinant, cofac; 


cout << "\n================================\n\n";

    getMatrix(&size, matrixA);

cout << "\n================================\n\n";

    //Print A
    cout << "Matrix A:";
    printMatrix(size, matrixA);

    //Print A transpose
    cout << "\n\nMatrix A Transpose:";
    makeTransposeMatrix(1, size, matrixA, matrixAt);
    printMatrix(size, matrixAt);

cout << "\n\n================================\n\n";

    //Determinant
    cout << "Determinant: \n";
    determinant = findDeterminant(1, size, matrixA);

cout << "\n\n================================\n\n";

    //Cofactor
    cout << "Calculating Cofactors: \n";
    makeCofactorMatrix(1, size, matrixA, matrixCo);
    cout << "\n\nCofactor Matrix:";
    printMatrix(size, matrixCo);

cout << "\n\n================================\n\n";
    
    //Inverse
    makeInverseMatrix(1, size, matrixA, matrixInv);
    cout << "\n\nInverse Matrix: ";
    printMatrix(size, matrixInv);

cout << "\n\n================================\n\n";
    
}



