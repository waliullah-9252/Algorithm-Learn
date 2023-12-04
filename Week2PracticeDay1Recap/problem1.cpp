#include <bits/stdc++.h>
using namespace std;
const int n = 1e6 + 5;
vector<int> adjList[n];
int visited[n];

// dfs function
void dfs(int parent)
{
    visited[parent] = 1;
    for (int child : adjList[parent])
    {
        if (visited[child] == 0)
        {
            dfs(child);
        }
    }
    cout << parent << " ";
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

    int src = 1;
    // calling dfs function
    dfs(src);
    return 0;
}