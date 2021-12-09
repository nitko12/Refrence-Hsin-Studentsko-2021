// Binomial coefficient
//
// Calculating ncr (n choose r).
//
// Variables:
// - mod is the modulo
// - maxn is the largest possible n
// - f[n] = n!
// - fi[n] = inverse of n! modulo mod
//
// Functions:
// - pwr(a, p) calculates a ^ k % mod
// - inv(a) calculates inverse of a modulo mod
// - precompute() precomputes factorials and inverse factorials up to maxn
// - ncr_single(n, r) calculates n choose r
//
// Time complexities:
// - pwr: O(log(p))
// - inv: O(log(mod))
// - ncr: O(1)
// - precompute: O(maxn)
//
// Note: before using ncr call precompute() to precompute factorials

#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

const int mod = 1000000009;
const int maxn = 1000000;

int f[maxn + 1], fi[maxn + 1];

int add(int a, int b) { return (a += b) < mod ? a : a - mod; }
int sub(int a, int b) { return (a -= b) >= 0 ? a : a + mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }
void adds(int &a, int b) { a = add(a, b); }
void subs(int &a, int b) { a = sub(a, b); }
void muls(int &a, int b) { a = mul(a, b); }
void maxs(int &a, int b) { a = max(a, b); }
void mins(int &a, int b) { a = min(a, b); }

int pwr(int a, ll p)
{
    if (p == 0)
        return 1;
    if (p & 1)
        return mul(a, pwr(a, p - 1));
    return pwr(mul(a, a), p / 2);
}

int inv(int a) { return pwr(a, mod - 2); }
int ncr_single(int n, int r) { return mul(f[n], mul(fi[r], fi[n - r])); }

void precompute()
{
    f[0] = 1;
    for (int i = 1; i <= maxn; ++i)
        f[i] = mul(f[i - 1], i);

    fi[maxn] = inv(f[maxn]);
    for (int i = maxn - 1; i >= 0; --i)
        fi[i] = mul(fi[i + 1], i + 1);
}

int ncr_dp[2500][2500];

int ncr(int n, int r)
{
    if (r == 0)
        return 1;
    if (n == r)
        return 1;
    if (ncr_dp[n][r] != -1)
        return ncr_dp[n][r];
    return ncr_dp[n][r] = ncr(n - 1, r) + ncr(n - 1, r - 1);
}

int main()
{
    precompute();

    cout << inv(1231241) << endl; // 603580458
    // 603580458 * 1231241 = 743153006688378, mod = 1

    memset(ncr_dp, -1, sizeof ncr_dp);

    cout << ncr(5, 2) << endl; // 10

    return 0;
}
