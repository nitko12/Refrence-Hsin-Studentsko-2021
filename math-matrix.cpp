// Matrix multiplication and exponentiation
//
// Fast matrix exponentiation and multiplication.
//
// Attributes:
// - dim is the dimension of the matrix.
// - A is the vector representing the matrix.
//
// Time complexities:
// - operator *: O(N ^ 3)
// - operator ^: O(N ^ 3 * log k)

#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1000000007;
int add(int a, int b) { return (a += b) < mod ? a : a - mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }
void adds(int &a, int b) { a = add(a, b); }

int pwr(int a, ll p)
{
    if (p == 0)
        return 1;
    if (p & 1)
        return mul(a, pwr(a, p - 1));
    return pwr(mul(a, a), p / 2);
}

int inv(int a) { return pwr(a, mod - 2); }

struct Matrix
{
    vvi A;
    Matrix() {}
    Matrix(int n) { A.assign(n, vi(n)); }
    vi &operator[](int n) { return A[n]; }
};

int operator*(vi &a, vi &b)
{
    return inner_product(a.begin(), a.end(), b.begin(), 0, add, mul);
}

Matrix operator*(Matrix A, Matrix B)
{
    int n = A.A.size();
    Matrix C(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                adds(C[i][j], mul(A[i][k], B[k][j]));

    return C;
}

Matrix operator^(Matrix A, ll k)
{
    int n = A.A.size();
    Matrix R(n);
    for (int i = 0; i < n; ++i)
        R[i][i] = 1;

    while (k > 0)
    {
        if (k % 2)
            R = R * A;

        A = A * A;
        k /= 2;
    }
    return R;
}

int main()
{
    Matrix a;
    a.A = {
        {0, 1},
        {1, 1},
    };

    vector<int> v = {0, 1};

    a = (a ^ 10);

    cout << a[0][1] * v[1] + a[1][1] * v[1] << endl; // 144, fibonacci

    return 0;
}
