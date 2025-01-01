class Matrix {
private:
    int rows, cols;
    int** data;

public:
    
    // Constructor declaration
    Matrix(int r, int c);

    // Destructor declaration
    ~Matrix();
     int** getData() const { return data; }
     void getDimensions(int &r, int &c) const;
     void readMatrix();
     void rowmatrix();
     void colmatrix();
     void squarematrix();
     void rectmatrix();
    int equalDimensions(int &r, int &c, int &p, int &q) const;
    friend Matrix operator*( Matrix &A, Matrix &B);
    friend Matrix operator+( const Matrix &A, const Matrix &B);
    friend Matrix operator-( const Matrix &A, const Matrix &B);
    friend Matrix operator*(double c, const Matrix &A);
    void trans();
    void trans_mult1();
    void trans_mult2();
    bool isEqual(const Matrix& other);
    void square();
    void matrix_op();
    void isSymmetric();
    void ident();
    void checkDiagonal() ;
    void checkUpperTriangular();
    void checkLowerTriangular();
    void calculateTrace();
    int calculateDeterminant(int** matrix, int n);
    Matrix calculateCofactor();
    Matrix calculateInverse();
    void print() const;
    
};
