#include <iostream>
#include <math.h>
#include <algorithm>
#define MAXSIZE 100
#define MAXPERMUTS 100000

using namespace std;

int factorial(int n);
int makePermuts(int *permuts , int size);
float makeTransposeMatrix(int print, int size, float matrixA[MAXSIZE][MAXSIZE], float matrixAt[MAXSIZE][MAXSIZE]);
float makeCofactorMatrix(int print, int size, float matrixA[MAXSIZE][MAXSIZE], float matrixCo[MAXSIZE][MAXSIZE]);
float makeInverseMatrix(int print, int size, float matrixA[MAXSIZE][MAXSIZE], float matrixInv[MAXSIZE][MAXSIZE]);
float findCofactor(int print, int size, float matrixA[MAXSIZE][MAXSIZE], int line, int column);
float findDeterminant(int print, int size, float matrixA[MAXSIZE][MAXSIZE]);
float printMatrix(int size, float matrixA[MAXSIZE][MAXSIZE]);
float getMatrix(int *sizePointer, float matrix[MAXSIZE][MAXSIZE]);


int factorial(int n = 0){
    int res = 1; 
    if(n != 0){
        for(int i = 1; i<=n; i++){
            res = res*i;
        }
    }
    else if(n == 0){res = 1;}
    return res;
}

int makePermuts(int *permuts, int size){
    int i, j;
    int a[size+1];

    for(i = 0; i < size; i++){
        a[i] = i;
    }

    sort(a, a+size);

    j = 0;
    do {
        for(int i = 0; i<size; i++){
            permuts[i+j*size] = a[i];
        }
        j++;
    } while(next_permutation(a, a+size));

    return 0;
}

float makeTransposeMatrix(int print, int size, float matrixA[MAXSIZE][MAXSIZE], float matrixAt[MAXSIZE][MAXSIZE]){
    int i, j;

    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            matrixAt[j][i] = matrixA[i][j];
        }
    }
    
    return 0;
}

float makeCofactorMatrix(int print, int size, float matrixA[MAXSIZE][MAXSIZE], float matrixCo[MAXSIZE][MAXSIZE]){
    float cofac;
    int i, j;

    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            if(print==1){cout << "\n";}
            cofac = findCofactor(print, size, matrixA, i, j);
            matrixCo[i][j] = cofac;
        }
    }

    return 0;
}

float makeInverseMatrix(int print, int size, float matrixA[MAXSIZE][MAXSIZE], float matrixInv[MAXSIZE][MAXSIZE]){

    float matrixCo[MAXSIZE][MAXSIZE], matrixCoT[MAXSIZE][MAXSIZE], determinant;
    int i,j;

    determinant = findDeterminant(0, size, matrixA);
    if(determinant == 0){
        cout << "There is no inverse!";
        return 0;
    }

    makeCofactorMatrix(0, size, matrixA, matrixCo);
    if(print == 1){
        cout << "Cofactor Matrix:";
        printMatrix(size, matrixCo);
    }

    makeTransposeMatrix(0, size, matrixCo, matrixCoT);
    if(print == 1){
        cout << "\n\nAdjunct Matrix (cofactor transpose):";
        printMatrix(size, matrixCoT);
    }

    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            matrixInv[i][j] = matrixCoT[i][j]/determinant;
        }
    }

    return 0;
}

float findCofactor(int print, int size, float matrixA[MAXSIZE][MAXSIZE], int line, int column){

    int i, j, jumpi, jumpj;
    float matrixCofDet[MAXSIZE][MAXSIZE], determinant, cofac;

    jumpi = 0;
    jumpj = 0;
    for(i = 0; i<size; i++){
        for(j = 0; j<size; j++){
            if(i != line){
                if(j != column){  
                    if(jumpj>=size-1){
                    jumpj = 0; 
                    jumpi++;
                    }
                    matrixCofDet[jumpj][jumpi] = matrixA[i][j];
                    jumpj++;
                }
            }
        }
    }

    if(print==1){
        if(print==1){cout << "---------------- " << "Cofactor a" << line+1 << column+1 << " ----------------";}
        for(i=0; i<size-1; i++){
            if(print==1){cout << endl;}
            for(j=0; j<size-1; j++){
                if(print==1){cout << " " << matrixCofDet[i][j];}
            }
        } 
        if(print==1){cout << "\n\n";}
    }

    if(print==1){cout << " Determinant: \n";}
    determinant = findDeterminant(print, size-1, matrixCofDet);

    cofac = pow((-1),line+column) * determinant;
    if(cofac == -0){cofac = 0;} //bug fix

    if(print==1){
        cout << "\n\n Calculating: \n";
        cout << " "<< determinant << " . (-1)^(" << line+1 <<"+"<< column+1 << ")";
        cout << "\n\n = " << cofac;
        cout << "\n----------------------------------------------";
    }

    return cofac;
}

float findDeterminant(int print, int size, float matrixA[MAXSIZE][MAXSIZE]){

    float determinant = 0, matrixElement = 1;
    int inv = 1, i, j, k, l, p;
    int permuts[MAXPERMUTS];
    int permutations = factorial(size);
    makePermuts(permuts, size);

    for(j=0; j<permutations; j++){

        inv = 1;
        for(k = 0; k < size; k++){
            for(l = 0; l < size-k; l++){
                if(permuts[j*size+k]>permuts[j*size+k+l]){
                    inv = -inv;
                }
            }
        }

        if(print == 1){
            if(inv == 1){
                cout << " + "; 
            }else{
                cout << " - "; 
            }
        }

        matrixElement = 1;
        for(i=0; i<size; i++){
            p = permuts[j*size+i];
            matrixElement = matrixElement*matrixA[i][p];
            if(print == 1) {cout << "a" << i+1 << p+1;}
        }

        if(print == 1) {cout << "      " << matrixElement*inv << endl;}
        
        determinant = matrixElement*inv + determinant;
    }

    if(print == 1) {cout << "\n = " << determinant;}

    return determinant;
}

float printMatrix(int size, float matrixA[MAXSIZE][MAXSIZE]){
    
    int i,j;

    for(i=0; i<size; i++){
        cout << endl;
        for(j=0; j<size; j++){
            cout << matrixA[i][j] << " ";
        }
    }

    return 0; 
}

float getMatrix(int *sizePointer, float matrix[MAXSIZE][MAXSIZE]){

    float matrixA[MAXSIZE][MAXSIZE];
    int i, j, size;
    
    //Get size
    cout << "Insert matrix size NxN: ";
    cin >> size;

    //Get elements
    cout << "\nInsert matrix elements (separated by enter):\n";
    for(i=0; i<size; i++){
        cout << "Column " << i+1 << ":" << endl;
        for(j=0; j<size; j++){
            cout << " ";
            cin >> matrix[j][i];
        }
    }

    *sizePointer = size;

    return 0;
}