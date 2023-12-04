#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> adjList[N];
int visited[N];
int depth[N];

// dfs function
void dfs(int parent)
{
    visited[parent] = 1;
    for (int child : adjList[parent])
    {
        if (visited[child] == 0)
        {
            depth[child] = depth[parent] + 1;
            dfs(child);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int d;
    cin >> d;

    int src = 1;

    // calling dfs function
    dfs(src);

    // print depth
    cout << "Depth of " << d << " = " << depth[d];
    return 0;
}