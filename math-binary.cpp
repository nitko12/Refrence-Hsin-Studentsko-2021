#include <iostream>
#include <vector>

using namespace std;

int bsrch_it(vector<int> &A, int p, int q, int x)
{
    while (p < q)
    {
        int mid = (p + q) / 2;
        if (A[mid] == x)
            return mid;
        else if (x < A[mid])
            q = mid - 1;
        else
            p = mid + 1;
    }
    return -1;
}

int a[] = {1, 1, 1, 0, 0, 0};

int f(int x)
{
    return a[x];
}

//           o
// 0 0 0 0 0 1 1 1 1 1
template <typename func>
int bsrch_a(func f, int lo, int hi)
{
    while (lo < hi)
    {
        int mid = (lo + hi) / 2; // pod
        if (f(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

//         o
// 1 1 1 1 1 0 0 0 0 0 0
template <typename func>
int bsrch_b(func f, int lo, int hi)
{
    while (lo < hi)
    {
        int mid = (lo + hi + 1) / 2; // strop
        if (f(mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    return lo;
}

int main()
{
    cout << bsrch_b(f, 0, 5) << endl;
    return 0;
}
