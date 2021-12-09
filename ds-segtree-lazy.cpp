#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

class SegTree
{
    vector<int> tree;
    vector<int> lazy;
    int n;

    void build_tree(const vector<int> &v, int node, int a, int b)
    {
        if (a > b)
            return;

        if (a == b)
        {
            tree[node] = v[a];
            return;
        }

        build_tree(v, node * 2, a, (a + b) / 2);
        build_tree(v, node * 2 + 1, 1 + (a + b) / 2, b);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }

    void update_lazy(int node, int a, int b)
    {
        tree[node] += lazy[node];

        if (a != b)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }

        lazy[node] = 0;
    }

    void update_tree(int node, int a, int b, int i, int j, int value)
    {
        if (lazy[node] != 0)
            update_lazy(node, a, b);

        if (a > b || a > j || b < i)
            return;

        if (a >= i && b <= j)
        {
            tree[node] += value;
            if (a != b)
            {
                lazy[node * 2] += value;
                lazy[node * 2 + 1] += value;
            }
            return;
        }

        update_tree(node * 2, a, (a + b) / 2, i, j, value);
        update_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j, value);

        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }

    int query_tree(int node, int a, int b, int i, int j)
    {
        if (a > b || a > j || b < i)
            return 2100000000;

        if (lazy[node] != 0)
            update_lazy(node, a, b);

        if (a >= i && b <= j)
            return tree[node];

        int q1 = query_tree(node * 2, a, (a + b) / 2, i, j);
        int q2 = query_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j);

        return min(q1, q2);
    }

public:
    SegTree(const vector<int> &v)
    {
        n = v.size();

        int s = 2 * pow(2, ceil(log2(v.size())));

        tree.resize(s);
        lazy.resize(s);

        build_tree(v, 1, 0, n - 1);
    }

    void update(int idx1, int idx2, int add)
    {
        update_tree(1, 0, n - 1, idx1, idx2, add);
    }

    int query(int idx1, int idx2)
    {
        return query_tree(1, 0, n - 1, idx1, idx2);
    }
};

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    SegTree s(a);

    s.update(1, 3, 10);

    for (int i = 0; i < a.size(); ++i)
        cout << s.query(i, i) << " ";
    cout << endl;

    return 0;
}
