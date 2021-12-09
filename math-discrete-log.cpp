#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

int gcd(int a, int b) // basic gcd
{
    return (b == 0 ? a : gcd(b, a % b));
}

// Returns minimum x for which a ^ x % m = b % m.
int discrete_log(int a, int b, int m)
{
    a %= m, b %= m;

    int k = 1, add = 0, g;
    while ((g = gcd(a, m)) > 1)
    {
        if (b == k)
            return add;
        if (b % g)
            return -1;
        b /= g, m /= g, ++add;
        k = (k * 1ll * a / g) % m;
    }

    int n = sqrt(m) + 1;
    int an = 1;
    for (int i = 0; i < n; ++i)
        an = (an * 1ll * a) % m;

    unordered_map<int, int> vals;
    for (int q = 0, cur = b; q <= n; ++q)
    {
        vals[cur] = q;
        cur = (cur * 1ll * a) % m;
    }

    for (int p = 1, cur = k; p <= n; ++p)
    {
        cur = (cur * 1ll * an) % m;
        if (vals.count(cur))
        {
            int ans = n * p - vals[cur] + add;
            return ans;
        }
    }
    return -1;
}

int main()
{
    cout << discrete_log(2, 7, 13) << endl; // 11, 2^11 = 7 mod 13
    return 0;
}
