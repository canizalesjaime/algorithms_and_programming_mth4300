#include "problem2.h"

Matrix33::Matrix33(double matrix[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            matrix_[i][j] = matrix[i][j];
        }
    }
}

Matrix33::Matrix33() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            matrix_[i][j] = 0.0;
        }
    }
}

Matrix33 Matrix33::operator*(const Matrix33& other) const {
    Matrix33 result;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            result.matrix_[i][j] = 0;
            for(int k = 0; k < 3; k++) {
                result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
            }
        }
    }
    return result;
}

Matrix33 Matrix33::operator*(double scalar) const {
    Matrix33 result;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            result.matrix_[i][j] = matrix_[i][j] * scalar;
        }
    }
    return result;
}

Matrix33 Matrix33::operator+(const Matrix33& other) const {
    Matrix33 result;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            result.matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
        }
    }
    return result;
}

double Matrix33::operator()(int row, int col) const {
    return matrix_[row][col];
}

ostream& operator<<(ostream& os, const Matrix33& matrix) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            os << matrix.matrix_[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

istream& operator>>(istream& in, Matrix33& matrix) {
    for(int i = 0; i < 3; i++) {
        cout << "Enter the elements of the row " << i + 1 << ": ";
        for(int j = 0; j < 3; j++) {
            in >> matrix.matrix_[i][j];
        }
    }
    return in;
}

double Matrix33::determinant() const {
    double det = 0.0;
    for(int i = 0; i < 3; i++) {
        det += matrix_[0][i] * (matrix_[1][(i+1)%3] * matrix_[2][(i+2)%3] - matrix_[1][(i+2)%3] * matrix_[2][(i+1)%3]);
    }
    return det;
}