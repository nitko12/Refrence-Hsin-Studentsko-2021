#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj = {
    // adjacency list representation
    {1},
    {2},
    {0},
};
int n = 3; // number of vertices

vector<bool> visited(n);

void dfs(int v)
{
    visited[v] = true;
    for (int u : adj[v])
    {
        if (!visited[u])
            dfs(u);
    }
}

// vector<int> color(n);

// vector<int> time_in(n), time_out(n);
// int dfs_timer = 0;

// void dfs(int v)
// {
//     time_in[v] = dfs_timer++;
//     color[v] = 1;
//     for (int u : adj[v])
//         if (color[u] == 0)
//             dfs(u);
//     color[v] = 2;
//     time_out[v] = dfs_timer++;
// }

int main()
{
    dfs(0);

    return 0;
}
