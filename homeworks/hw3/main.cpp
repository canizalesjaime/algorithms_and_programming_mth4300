#include "Vector3.h"
#include "problem2.h"

using namespace std;

Vector3 product(const Matrix33& A, const Vector3& x)
{
    double b0 = A(0, 0) * x(0) + A(0, 1) * x(1) + A(0, 2) * x(2);
    double b1 = A(1, 0) * x(0) + A(1, 1) * x(1) + A(1, 2) * x(2);
    double b2 = A(2, 0) * x(0) + A(2, 1) * x(1) + A(2, 2) * x(2);
    
    return Vector3(b0, b1, b2);
}
int main()
{
    Matrix33 A;
    cin >> A;
    Vector3 x;
    cin >> x;
    Vector3 b = product(A, x);
    cout << "Ax = " << b << endl;
    return 0;
}