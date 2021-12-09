#include <iostream>
using namespace std;

const int maxn = 200005;
int p[maxn];

void make_set()
{
    for (int i = 0; i < maxn; ++i)
        p[i] = i;
}

int find_set(int v)
{
    if (v == p[v])
        return v;
    return p[v] = find_set(p[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        p[b] = a;
}

int main()
{
    make_set();
    union_sets(1, 2);
    union_sets(3, 4);

    cout << find_set(1) << " " << find_set(3) << endl;

    union_sets(2, 4);

    cout << find_set(1) << " " << find_set(3) << endl;

    return 0;
}
