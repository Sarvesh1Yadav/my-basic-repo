#include<iostream>
#include"header.h"
using namespace std;
int main() {
    int r1, c1, r2, c2;

    // Prompt the user to input the dimensions of the first matrix
    cout << "Enter the number of rows and columns for Matrix A: ";
    cin >> r1 >> c1;
    Matrix A(r1, c1);
    A.readMatrix();  // Read the matrix elements

    // Prompt the user to input the dimensions of the second matrix
    cout << "Enter the number of rows and columns for Matrix B: ";
    cin >> r2 >> c2;
    Matrix B(r2, c2);
    B.readMatrix();  // Read the matrix elements

    // Check for row matrix and column matrix
    A.rowmatrix();
    A.colmatrix();
    A.squarematrix();
    A.rectmatrix();

    // Get and print dimensions of the matrices
    int rows, cols;
    A.getDimensions(rows, cols);
    cout << "Dimensions of A: " << rows << " x " << cols << endl;

    B.getDimensions(rows, cols);
    cout << "Dimensions of B: " << rows << " x " << cols << endl;

   
    // Check for equal dimensions
    if(A.equalDimensions(r1, c1,r2,c2) == 1){
         // Matrix addition
    try {
        Matrix C = A + B;
        cout << "Matrix A + B:" << endl;
        C.print();
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    // Matrix subtraction
    try {
        Matrix E = A - B;
        cout << "Matrix A - B:" << endl;
        E.print();
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
     // Scalar multiplication
    double scalar;
    cout << "Enter a scalar value for multiplication: ";
    cin >> scalar;
    Matrix F = scalar * A;
    cout << "Matrix A multiplied by scalar " << scalar << ":" << endl;
    F.print();

    } 
   

    if(c1==r2 && r1 == c2){
       // Matrix multiplication
    try {
        Matrix D = A * B;
        cout << "Matrix A * B:" << endl;
        D.print();
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
    try {
        Matrix E = B * A;
        cout << "Matrix B * A:" << endl;
        E.print();
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
    }


     if(c1==r2 && r1 == c2 && r1==c1 && r2==c2){
     try {
        Matrix D = A * B;
        cout << "Matrix A * B:" << endl;
        D.print();
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
    try {
        Matrix E = B * A;
        cout << "Matrix B * A:" << endl;
        E.print();
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
     Matrix D = A * B;
      Matrix E = B * A;
      if(D.isEqual(E))
      cout<<"AB = BA\n";
      else
      cout<<"Its not commutative\n";
    }

    // Perform matrix transpose
    
    cout << "Transposed Matrix A:" << endl;
    A.trans();

    // Perform matrix transpose and multiplication
    cout << "A cross A transpose:" << endl;
    A.trans_mult1();
    cout << "A transpose cross A :" << endl;
    A.trans_mult2();
    // cout << "Transposed and Multiplied Matrix A:" << endl;
    // A.print();
    // Perform matrix operations (e.g., diagonal check, upper triangular, etc.)
    cout << "\nPerforming matrix operations on Matrix A:" << endl;
    A.matrix_op();  // Call matrix operations on Matrix A
    return 0;
}
