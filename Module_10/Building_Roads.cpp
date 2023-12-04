#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<int> adjList[N];
int visited[N];

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

    vector<int> k;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            k.push_back(i);
            dfs(i);
        }
    }

    cout << k.size() - 1 << endl;

    for (auto i = 1; i < k.size(); i++)
    {
        cout << k[i] - 1 << " " << k[i] << endl;
    }

    return 0;
}