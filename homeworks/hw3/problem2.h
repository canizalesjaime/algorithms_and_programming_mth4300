#ifndef MATRIX33_H
#define MATRIX33_H
#include <iostream>

class Matrix33 {
    private:
        double matrix_[3][3];
    public:
        Matrix33(double matrix[3][3]);
        Matrix33();

        Matrix33 operator*(const Matrix33& other) const;
        Matrix33 operator*(double scalar) const;
        Matrix33 operator+(const Matrix33& other) const;
        double operator()(int row, int col) const;
        friend ostream& operator<<(ostream& os, const Matrix33& matrix);
        friend istream& operator>>(istream& in, Matrix33& matrix);
        double determinant() const;
};
#endif // MATRIX33_H