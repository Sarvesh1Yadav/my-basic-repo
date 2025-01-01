#include"header.h"
#include <iostream>
#include<cmath>
using namespace std;


// Constructor to initialize matrix with given rows and columns
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    data = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols]();
    }
}

// Destructor to free dynamically allocated memory
Matrix::~Matrix() {
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

// Get dimensions of the matrix
void Matrix::getDimensions(int &r, int &c) const {
    r = rows;
    c = cols;
}

// Read matrix data from user
void Matrix::readMatrix() {
    cout << "Enter elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> data[i][j];
        }
    }
}

// Check if it is a row matrix
void Matrix::rowmatrix() {
    if (rows == 1) {
        cout << "This is a row matrix." << endl;
    } else {
        cout << "This is not a row matrix." << endl;
    }
}

// Check if it is a column matrix
void Matrix::colmatrix() {
    if (cols == 1) {
        cout << "This is a column matrix." << endl;
    } else {
        cout << "This is not a column matrix." << endl;
    }
}

// Check if it is a square matrix
void Matrix::squarematrix() {
    if (rows == cols) {
        cout << "This is a square matrix." << endl;
    } else {
        cout << "This is not a square matrix." << endl;
    }
}

// Check if it is a rectangular matrix
void Matrix::rectmatrix() {
    if (rows != cols) {
        cout << "This is a rectangular matrix." << endl;
    } else {
        cout << "This is not a rectangular matrix." << endl;
    }
}

// Check if two matrices have equal dimensions
int Matrix::equalDimensions(int &r, int &c,int &p, int &q) const {
    if (p == r && q == c) {
        cout << "Dimensions are equal." << endl;
        return 1;
    } else {
        cout << "Dimensions are not equal." << endl;
    }
}

// Matrix addition
Matrix operator+(const Matrix &A, const Matrix &B) {
    Matrix result(A.rows, A.cols);
    for (int i = 0; i < A.rows; ++i) {
        for (int j = 0; j < A.cols; ++j) {
            result.data[i][j] = A.data[i][j] + B.data[i][j];
        }
    }
    return result;
}

// Matrix subtraction
Matrix operator-(const Matrix &A, const Matrix &B) {
    Matrix result(A.rows, A.cols);
    for (int i = 0; i < A.rows; ++i) {
        for (int j = 0; j < A.cols; ++j) {
            result.data[i][j] = A.data[i][j] - B.data[i][j];
        }
    }
    return result;
}

// Scalar multiplication
Matrix operator*(double c, const Matrix &A) {
    Matrix result(A.rows, A.cols);
    for (int i = 0; i < A.rows; ++i) {
        for (int j = 0; j < A.cols; ++j) {
            result.data[i][j] = c * A.data[i][j];
        }
    }
    return result;
}

// Matrix multiplication
Matrix operator*(Matrix &A, Matrix &B) {
    Matrix result(A.rows, B.cols);
    for (int i = 0; i < A.rows; ++i) {
        for (int j = 0; j < B.cols; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < A.cols; ++k) {
                result.data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }
    return result;
}
//AB = BA
bool Matrix::isEqual(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            return false;
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (data[i][j] != other.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }


// Transpose of matrix
void Matrix::trans() {
    Matrix transposed(cols, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed.data[j][i] = data[i][j];
        }
    }
   for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout<<transposed.data[i][j]<<" ";
        }
        cout<<endl;
    }
}

// Transpose multiplication of matrix
void Matrix::trans_mult1() {
    Matrix transposed(cols, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed.data[j][i] = data[i][j];
        }
    }
    // Matrix result = * this * transposed;
    // *this = result;
    Matrix result=*this*transposed;
    result.print();
}
void Matrix::trans_mult2() {
    Matrix transposed(cols, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed.data[j][i] = data[i][j];
        }
    }
    Matrix result=transposed**this;
    result.print();
}


// Print the matrix
void Matrix::print() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

void Matrix::matrix_op() {
    int choice;
    cout << "Select an operation to perform on the matrix:\n";
    cout << "1. Check if Diagonal Matrix\n";
    cout << "2. Check if Upper Triangular Matrix\n";
    cout << "3. Check if Lower Triangular Matrix\n";
    cout << "4. Calculate Trace\n";
    cout << "5. Calculate Determinant\n";
    cout << "6. Calculate Cofactor\n";
    cout << "7. Calculate Inverse\n";
    cout << "8. Check symmetric\n";
    cout << "9. Check identity\n";
    cout<<"10. To calculate squre of matrix\n";
    cout << "Enter your choice (1-10): ";
    cin >> choice;

    switch (choice) {
        case 1:
            checkDiagonal();
            break;
        case 2:
            checkUpperTriangular();
            break;
        case 3:
            checkLowerTriangular();
            break;
        case 4:
            calculateTrace();
            break;
        case 5:
            cout << "Determinant: " << calculateDeterminant(data, rows) << endl;
            break;
        case 6:
            calculateCofactor().print();
            break;
        case 7:
            if (calculateDeterminant(data, rows) != 0) {
                calculateInverse().print();
            } else {
                cout << "Inverse cannot be calculated (determinant is zero)." << endl;
            }
            break;
            case 8:
             isSymmetric();
             break;

             case 9:
             ident();
             break;
             case 10:
             square();
             break;
        default:
            cout << "Invalid choice. Please select a valid operation." << endl;
    }
}

// Helper function to check if matrix is diagonal
void Matrix::checkDiagonal() {
    
    if(rows != cols) {  // Check for square matrix
        cout << "Matrix is not square, so it can't be diagonal." << endl;
        return;
    }

    bool isDiagonal = true;
    for (int i = 0; i < rows && isDiagonal; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i != j && data[i][j] != 0) {  // Check off-diagonal elements
                isDiagonal = false;
                break;
            }
        }
    }
    
    if (isDiagonal) {
        cout << "Matrix is diagonal." << endl;
    }
    else{
     cout << "Matrix is not diagonal." << endl;
    }
}


// Helper function to check if matrix is upper triangular
void Matrix::checkUpperTriangular() {
    bool isUpperTriangular = true;
    for (int i = 1; i < rows && isUpperTriangular; ++i) {
        for (int j = 0; j < i; ++j) {
            if (data[i][j] != 0) {
                isUpperTriangular = false;
                break;
            }
        }
    }
    cout << "Matrix is " << (isUpperTriangular ? "upper triangular." : "not upper triangular.") << endl;
}

// Helper function to check if matrix is lower triangular
void Matrix::checkLowerTriangular() {
    bool isLowerTriangular = true;
    for (int i = 0; i < rows && isLowerTriangular; ++i) {
        for (int j = i + 1; j < cols; ++j) {
            if (data[i][j] != 0) {
                isLowerTriangular = false;
                break;
            }
        }
    }
    cout << "Matrix is " << (isLowerTriangular ? "lower triangular." : "not lower triangular.") << endl;
}
void Matrix::isSymmetric() {
    bool isSymmetric = true;
    for (int i = 0; i < rows && isSymmetric ; i++) {
        for (int j = i + 1; j < cols; j++) {
            if (data[i][j] != data[j][i]) {
                isSymmetric =  false;
                break;
            }
        }
    }
    cout  << (isSymmetric ? "Matrix is Symmetric." : "not Symmetric.") << endl;

}
void Matrix::ident(){
    bool id = true;
 for (int i = 0; i <  rows && id; i++) {
        for (int j = 0; j < cols; j++) {
            if ((i == j && data[i][j] != 1) || (i != j && data[i][j] != 0)) {
                id =false;
            }
        }
    }
  cout << (id ? "It is identity matrix." : "not Identity.") << endl;
}
void Matrix::square(){
    Matrix D = *this * *this;
    cout<<"Square of A = ";
    D.print();
}
// Helper function to calculate trace
void Matrix::calculateTrace() {
    if (rows != cols) {
        cout << "Trace is undefined for a non-square matrix." << endl;
        return;
    }
    int trace = 0;
    for (int i = 0; i < rows; ++i) {
        trace += data[i][i];
    }
    cout << "Trace of the matrix: " << trace << endl;
}

// Helper function to calculate determinant
int Matrix::calculateDeterminant(int** matrix, int n) {
    if (n == 1) return matrix[0][0];

    int determinant = 0;
    int sign = 1;
    for (int f = 0; f < n; f++) {
        int** subMatrix = new int*[n - 1];
        for (int i = 0; i < n - 1; i++)
            subMatrix[i] = new int[n - 1];
        
        for (int i = 1; i < n; i++) {
            int colIndex = 0;
            for (int j = 0; j < n; j++) {
                if (j != f) {
                    subMatrix[i - 1][colIndex] = matrix[i][j];
                    colIndex++;
                }
            }
        }
        determinant += sign * matrix[0][f] * calculateDeterminant(subMatrix, n - 1);
        sign = -sign;

        for (int i = 0; i < n - 1; i++)
            delete[] subMatrix[i];
        delete[] subMatrix;
    }
    return determinant;
}



// Helper function to calculate cofactor matrix
Matrix Matrix::calculateCofactor() {
    Matrix cofactor(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int** subMatrix = new int*[rows - 1];
            for (int k = 0; k < rows - 1; ++k)
                subMatrix[k] = new int[cols - 1];
            
            int p = 0, q = 0;
            for (int x = 0; x < rows; x++) {
                for (int y = 0; y < cols; y++) {
                    if (x != i && y != j) {
                        subMatrix[p][q++] = data[x][y];
                        if (q == cols - 1) {
                            q = 0;
                            p++;
                        }
                    }
                }
            }
            cofactor.data[i][j] = pow(-1, i + j) * calculateDeterminant(subMatrix, rows - 1);
            
            for (int k = 0; k < rows - 1; k++)
                delete[] subMatrix[k];
            delete[] subMatrix;
        }
    }
    return cofactor;
}

// Helper function to calculate inverse matrix
Matrix Matrix::calculateInverse() {
    int det = calculateDeterminant(data, rows);
    Matrix cofactor = calculateCofactor();
    cofactor.trans(); // Transpose of cofactor to get adjoint
    Matrix inverse(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            inverse.data[i][j] = cofactor.data[i][j] / static_cast<double>(det);
    return inverse;
}
