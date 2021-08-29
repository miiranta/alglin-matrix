#include <iostream>
#include "handler.hpp"

using namespace std;

//LOOP?
int loop = 1;

int main(){
    
    int close = 0, option = 0, Aset = 0, Bset = 0;

    do{

        displayOptions();
        fflush(stdin);
        cin >> option;

        if(option == 0){close = 1;}

        if(option == 1){
            setMatrix();
            cin >> option;
            if(option == 1){Aset = setMatrixA();}
            if(option == 2 && Aset >= 1){Bset = setMatrixB();}
        }

        if(option == 2 && Aset >= 2){displayTransposedMatrix();}

        if(option == 3 && Aset >= 2){displayCofactorMatrix();}

        if(option == 4 && Aset >= 2){
            displayInverseMatrix();
            cin >> option;
            if(option == 1){displayInverseMatrixByCofactor();}
            if(option == 2){displayInverseMatrixByScaling();}
        }

        if(option == 5 && Aset >= 2){
            displayDeterminant();
            cin >> option;
            if(option == 1){displayDeterminantByPermutation();}
            if(option == 2){displayDeterminantByTriangle();}
        }

    }while(loop == 1 && close == 0);

    
}



