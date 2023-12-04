#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> adjList[N];
int visited[N];
int height[N];

// dfs function
void dfs(int parent)
{
    visited[parent] = 1;
    for (int child : adjList[parent])
    {
        if (visited[child] == 0)
        {
            dfs(child);
            height[parent] = max(height[child] + 1, height[parent]);
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
    int h;
    cin >> h;

    int src = 1;
    // calling dfs function
    dfs(src);

    // printing height
    cout << "height of " << h << " = " << height[h];
    return 0;
}