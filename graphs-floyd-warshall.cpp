// Floyd Warshall's algorithm
//
// Calculates APSP (all-pairs shortest path) on a weighted graph.
//
// Variables:
// - G is the adjecency matrix of the graph.
// - N is the number of vertices of the graph.
// - MAX is the maximum numbers of vertices (needs to be configurated).
//
// Note: G[i][j] represents the shortest path from vertex i to vertex j.
// If G[i][j] = inf then vertex j is unreachable from vertex i.

#include <iostream>

using namespace std;

const int inf = 1e9;

const int MAX = 10000;

int G[MAX][MAX] = {
    {0, inf, 3},
    {1, 0, inf},
    {2, 2, 0},
},
    N = 3;

int main()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            G[i][j] = (i == j ? 0 : G[i][j]); //  : inf); usually

    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cout << G[i][j] << " ";
        cout << endl;
    }

    return 0;
}
