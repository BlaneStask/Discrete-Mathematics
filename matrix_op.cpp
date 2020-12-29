// Description - This program implements matrix operations without using
// built-in functions/libraries that perform matrix operations. The matrix
// operations are transposition, symmetric, summation, and product.

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tranpose(vector<vector<int>> A){
    int nrow = A.size();
    int ncol = A[0].size();
    vector<vector<int>> AT(ncol, vector<int> (nrow));
    for(int i = 0; i < nrow; i++)
        for(int j = 0; j < ncol; j++)
            AT[j][i] = A[i][j];
    return AT;
}

bool isSymmetric(vector<vector<int>> A){
    int nrow = A.size();
    int ncol = A[0].size();
    for(int i = 0; i < nrow; i++)
        for(int j = i + 1; j < ncol; j++)
            if(A[i][j] != A[j][i]) return false;
    return true;
}

vector<vector<int>> addMat(vector<vector<int>> A, vector<vector<int>> B){
    //assuming the dimensions are compatible
    int nrow = A.size();
    int ncol = A[0].size();
    vector<vector<int>> C = A;
    for(int i = 0; i < nrow; i++)
        for(int j = 0; j < ncol; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

vector<vector<int>> multMat(vector<vector<int>> A, vector<vector<int>> B){
    //assuming the dimensions are compatible
    int Arow = A.size();
    int Acol = A[0].size();
    int Bcol = B[0].size();
    vector<vector<int>> C(Arow, vector<int> (Bcol));
    for(int i = 0; i < Arow; i++)
        for(int j = 0; j < Bcol; j++)
            for(int k = 0; k < Acol; k++)
                C[i][j] +=  A[i][k] * B[k][j];
    return C;
}

void printMatrix(vector<vector<int>> A){
    int nrow = A.size();
    int ncol = A[0].size();
    for (int i = 0; i < nrow; i++){
        for (int j = 0; j < ncol; j++){
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){

    vector<vector<int>> A = {    {1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9} };
    cout << "Matrix A: " << endl;
    printMatrix(A);
    cout << "Tranposed: " << endl;
    printMatrix(tranpose(A));

    vector<vector<int>> B = {    { 1, 1, 0 },
                                { 1, 0, 2 },
                                { 0, 2, 3 } };
    cout << "Matrix B: " << endl;
    printMatrix(B);
    cout << "B is " << (isSymmetric(B) ? "" : "NOT ") << "symmetric" << endl;
    cout << "A is " << (isSymmetric(A) ? "" : "NOT ") << "symmetric" << endl;
    cout << "A + B = " << endl;
    printMatrix(addMat(A, B));
    cout << "A * B = " << endl;
    printMatrix(multMat(A, B));
    return 0;
}
