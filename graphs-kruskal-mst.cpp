#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, weight;
} typedef Edge;

bool operator<(const Edge &a, const Edge &b)
{
    return a.weight < b.weight;
}

int main()
{
    int n = 3;
    vector<Edge> edges = {{1, 2, 1}, {1, 2, 3}, {2, 3, 1}};

    int cost = 0;
    vector<int> tree_id(n);
    vector<Edge> result;
    for (int i = 0; i < n; i++)
        tree_id[i] = i;

    sort(edges.begin(), edges.end());

    for (Edge e : edges)
    {
        if (tree_id[e.u] != tree_id[e.v])
        {
            cost += e.weight;
            result.push_back(e);

            int old_id = tree_id[e.u], new_id = tree_id[e.v];
            for (int i = 0; i < n; i++)
            {
                if (tree_id[i] == old_id)
                    tree_id[i] = new_id;
            }
        }
    }

    for (auto i : result)
        cout << i.u << " " << i.v << endl;

    return 0;
}
