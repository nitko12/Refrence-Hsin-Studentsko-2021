#include <iostream>
using namespace std;

double f(double x)
{
    return -((x - 2.3) * (x - 2.3)) + 5;
}

double ternary_search(double l, double r)
{
    double eps = 1e-9; // set the error limit here
    while (r - l > eps)
    {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1); // evaluates the function at m1
        double f2 = f(m2); // evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return f(l); // return the maximum of f(x) in [l, r]
}

int main()
{
    cout << ternary_search(0, 5) << endl;
}
