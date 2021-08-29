#include <iostream>
#include "functions.hpp"
#define MAXSIZE 100
using namespace std;

int i, j;
int sizeA, Aset, Bset, sizeB, linesA, linesB, columnsA, columnsB;
double matrixA[MAXSIZE][MAXSIZE], matrixB[MAXSIZE][MAXSIZE], matrixAt[MAXSIZE][MAXSIZE], matrixCo[MAXSIZE][MAXSIZE], matrixInv[MAXSIZE][MAXSIZE], matrixBuffer[MAXSIZE][MAXSIZE], determinant, cofac; 

void setMatrix(){
    cout << "\n================================\n\n";
    cout << "Select an option:" << endl;
    cout << "1 - Matrix A" << endl;
    if(Aset >= 1){cout << "2 - Matrix B" << endl;}
    cout << "0 - Return" << endl;
    cout << "\n================================\n\n";
}

int setMatrixA(){

    cout << "\n================================\n\n";
    getMatrix(&sizeA, matrixA, &columnsA, &linesA);
    cout << "\n================================\n\n";

    if(columnsA == linesA && linesA != 0){sizeA = linesA;}

    Aset = sizeA+1;
    return sizeA+1;

}

int setMatrixB(){

    cout << "\n================================\n\n";
    getMatrix(&sizeB, matrixB, &columnsB, &linesB);
    cout << "\n================================\n\n";

    if(columnsB == linesB && linesB != 0){sizeB = linesB;};

    Bset = sizeB+1;
    return sizeB+1;
    
}

void displayOptions(){
    cout << "\n================================\n\n";
    if(sizeA > 0){
        cout << "Matrix A:";
        printMatrix(sizeA, matrixA, 0);
        cout << "\n\n";
    }
    if(linesA > 0){
        cout << "Matrix A:";
        printMatrix(linesA, columnsA, matrixA, 0);
        cout << "\n\n";
    }
    if(sizeB > 0){
        cout << "Matrix B:";
        printMatrix(sizeB, matrixB, 0);
        cout << "\n\n";
    }
    if(linesB > 0){
        cout << "Matrix B:";
        printMatrix(linesB, columnsB, matrixB, 0);
        cout << "\n\n";
    }

    cout << "Select an option:" << endl;
    cout << "1 - Set Matrices" << endl;
    if(sizeA > 0){
        cout << "2 - Matrix A: Transpose " << endl;
        cout << "3 - Matrix A: Cofactor " << endl;
        cout << "4 - Matrix A: Inverse" << endl;
        cout << "5 - Matrix A: Determinant" << endl;
    }
    cout << "0 - Close" << endl;

    cout << "\n================================\n\n";
}

void displayDeterminant(){
    cout << "\n================================\n\n";
    cout << "Select an option:" << endl;
    cout << "1 - Using permutation" << endl;
    cout << "2 - Using scaling (triangle matrix)" << endl;
    cout << "0 - Return" << endl;
    cout << "\n================================\n\n";
}

void displayDeterminantByPermutation(){
    cout << "\n================================\n\n";
    cout << "Determinant by permutation: \n";
    determinant = findDeterminant(1, sizeA, matrixA);
    cout << "\n\n================================\n\n";
}

void displayDeterminantByTriangle(){
    cout << "\n================================\n\n";
    cout << "Determinant by scaling: \n";
    findDeterminantByTriangle(1, sizeA, matrixA);
    cout << "\n================================\n\n";
}

void displayTransposedMatrix(){
    cout << "\n================================\n\n";
    cout << "Matrix A Transpose:";
    makeTransposeMatrix(1, sizeA, matrixA, matrixAt);
    printMatrix(sizeA, matrixAt, 0);
    cout << "\n\n================================\n\n";
}

void displayCofactorMatrix(){
    cout << "\n\n================================\n\n";
    cout << "Calculating Cofactors: \n";
    makeCofactorMatrix(1, sizeA, matrixA, matrixCo);
    cout << "\n\nCofactor Matrix:";
    printMatrix(sizeA, matrixCo, 0);
    cout << "\n\n================================\n\n";
}

void displayInverseMatrix(){
    cout << "\n================================\n\n";
    cout << "Select an option:" << endl;
    cout << "1 - Using cofactors" << endl;
    cout << "2 - Using scaling" << endl;
    cout << "0 - Return" << endl;
    cout << "\n================================\n\n";
}

void displayInverseMatrixByCofactor(){
    cout << "\n\n================================\n\n";
    makeInverseMatrix(1, sizeA, matrixA, matrixInv);
    cout << "\n\nInverse Matrix: ";
    printMatrix(sizeA, matrixInv, 0);
    cout << "\n\n================================\n\n";
}

void displayInverseMatrixByScaling(){
    cout << "\n================================\n\n";
    makeInverseMatrixByScaling(1, sizeA, matrixA, matrixInv);
    cout << "\nInverse Matrix: ";
    printMatrix(sizeA, matrixInv, 0);
    cout << "\n\n================================\n\n";
}
