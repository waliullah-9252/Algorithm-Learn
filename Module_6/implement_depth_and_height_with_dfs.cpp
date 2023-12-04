#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> adjList[N];
bool visited[N];
int depth[N];
int height[N];
void dfs(int u)
{
    visited[u] = true;
    cout << "Visiting Node: " << u << endl;
    for (int val : adjList[u])
    {
        if (visited[val])
            continue;
        // count depth
        depth[val] = depth[u] + 1;
        dfs(val);
        // count height
        // if (height[val] + 1 > height[u])
        //     height[u] = height[val] + 1;
        height[u] = max(height[u],height[val]+1);
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
    cout << endl;
    // calling dfs function
    dfs(1);
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "Depth of a Nodes " << i << ": " << depth[i] << endl;
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "Height of a Nodes " << i << ": " << height[i] << endl;
    }
    return 0;
}