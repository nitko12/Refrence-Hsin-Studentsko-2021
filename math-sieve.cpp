// Sieve of Eratosthenes
//
// Computes all primes less than a given bound
//
// Variables:
// - P is a list of all primes less than a given bound
// - maxn is the upper bound of primes
// - n is the number of primes less than the upper bound
// - maxN ~ number of primes less than maxn
//
// Functions:
// - SimpleSieve() stores all primes less than sqrt(maxn)
// - SegSieve() stores all primes less than maxn
//
// Time complexity: O(N(log(log N)))
// Space complexity:
// - O(N / log(N)) - if all primes are stored
// - O(sqrt(N)) - if only first sqrt(N) primes are stored

#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

const ll maxN = 60000000;
const ll maxn = 100000000;
constexpr ll fn = 10002; //(ll)(sqrtl(maxn)) + 2;

ll Prime[fn],
    IsNotPrime[fn], p, n, P[maxN];

void SimpleSieve()
{
    for (ll i = 2; i < fn; ++i)
    {
        if (!IsNotPrime[i])
        {
            for (ll j = i * i; j < fn; j += i)
                IsNotPrime[j] = 1;

            P[n++] = Prime[p++] = i;
        }
    }
}

void SegSieve() // upto n
{
    SimpleSieve();
    ll lo = fn, hi = 2 * fn;
    while (lo < maxn)
    {
        if (hi >= maxn)
            hi = maxn;

        memset(IsNotPrime, 0, sizeof(IsNotPrime));
        for (ll i = 0; i < p; ++i)
        {
            int lolim = ll(lo / Prime[i]) * Prime[i];
            if (lolim < lo)
                lolim += Prime[i];

            for (ll j = lolim; j < hi; j += Prime[i])
                IsNotPrime[j - lo] = 1;
        }

        for (ll i = lo; i < hi; ++i)
            if (!IsNotPrime[i - lo])
                P[n++] = i;

        lo += fn, hi += fn;
    }
}

vector<char> segmentedSieve(long long L, long long R)
{
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i)
    {
        if (!mark[i])
        {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

int main()
{
    auto a = segmentedSieve(1e12, 1e12 + 100);

    for (ll i = 1e12; i < 1e12 + 100; ++i)
        if (a[i - 1e12])
            cout << i << " ";
    cout << endl;

    return 0;
}
