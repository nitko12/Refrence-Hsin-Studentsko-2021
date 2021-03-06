// Extended Euclid Algorithm
//
// Solves the Linear Diophantine Equation a * x + b * y = d where
// d = gcd(a, b).
//
// Time complexity: 0(log(min(a, b)))

#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) // basic gcd
{
    return (b == 0 ? a : gcd(b, a % b));
}

int x, y, d;

void Euclid(ll a, ll b)
{
    if (b == 0)
        x = 1, y = 0, d = a;
    else
    {
        Euclid(b, a % b);
        int x1 = y, y1 = x - (a / b) * y;
        x = x1, y = y1;
    }
}

int main()
{
    Euclid(10, 11);
    cout << x << " " << y << endl;

    return 0;
}
