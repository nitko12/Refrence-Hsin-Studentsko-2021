#include <iostream>
using namespace std;

// x_n = x_{n-1} - f(x_{n-1}) / f'(x_{n-1})

double sqrt_newton(double n)
{
    const double eps = 1E-15;
    double x = 1;
    for (;;)
    {
        double nx = (x + n / x) / 2;
        if (abs(x - nx) < eps)
            break;
        x = nx;
    }
    return x;
}

int isqrt_newton(int n)
{
    int x = 1;
    bool decreased = false;
    for (;;)
    {
        int nx = (x + n / x) >> 1;
        if (x == nx || nx > x && decreased)
            break;
        decreased = nx < x;
        x = nx;
    }
    return x;
}

int main()
{
    cout << sqrt_newton(17) << endl;
    return 0;
}
