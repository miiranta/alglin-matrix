#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int factorial(int n);
int makePermuts(int *permuts , int size);
float makeDeterminant(int print, int size, float matrixA[100][100]);

int main(){

//vars
int i, j;
int size = 1;
float matrixA[100][100], matrixAt[100][100], determinant; 


cout << "\n================================\n\n";

    //Get size
    cout << "Insert matrix size NxN: ";
    cin >> size;

cout << "\n================================\n\n";

    //Get elements
    cout << "Insert matrix elements (separated by enter):\n";

    for(i=0; i<size; i++){
        cout << "Column " << i+1 << ":" << endl;
        for(j=0; j<size; j++){
            cout << " ";
            cin >> matrixA[j][i];
        }
    }

cout << "\n================================\n\n";

    //Print A
    cout << "Matrix A:";
    for(i=0; i<size; i++){
        cout << endl;
        for(j=0; j<size; j++){
            cout << matrixA[i][j] << " ";
        }
    }

    //Print A transpose
    cout << "\n\nMatrix A Transpose:";
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            matrixAt[j][i] = matrixA[i][j];
        }
    }
    for(i=0; i<size; i++){
        cout << endl;
        for(j=0; j<size; j++){
            cout << matrixAt[i][j] << " ";
        }
    }

cout << "\n\n================================\n\n";

    cout << "Determinant: \n";

    //Determinant
    determinant = makeDeterminant(1, size, matrixA);

cout << "\n\n================================\n\n";

    
}



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

int makePermuts(int *permuts, int n){
    int i, j;
    int a[n+1];

    for(i = 0; i < n; i++){
        a[i] = i;
    }

    sort(a, a+n);

    j = 0;
    do {
        for(int i = 0; i<n; i++){
            permuts[i+j*n] = a[i];
        }
        j++;
    } while(next_permutation(a, a+n));

    return 0;

}

float makeDeterminant(int print, int size, float matrixA[100][100]){

    float determinant = 0, matrixElement = 1;
    int inv = 1, i, j, k, l, p;
    int permuts[10000];
    int permutations = factorial(size);
    makePermuts(permuts, size);

    for(j=0; j<permutations; j++){

        matrixElement = 1;
        if(print == 1){cout << " + ";}

        for(i=0; i<size; i++){
            p = permuts[j*size+i];
            matrixElement = matrixElement*matrixA[i][p];
            if(print == 1) {cout << "a" << i+1 << p+1;}
        }

        inv = 1;
        for(k = 0; k < size; k++){
            for(l = 0; l < size-k; l++){
                if(permuts[j*size+k]>permuts[j*size+k+l]){
                    inv = -inv;
                }
            }
        }

        if(print == 1) {cout << "      " << matrixElement*inv << endl;}
        
        determinant = matrixElement*inv + determinant;
    }

    if(print == 1) {cout << "\n = " << determinant;}

    return determinant;
}