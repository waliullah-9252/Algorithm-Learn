#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> adjList[N];
bool visited[N];
int depth[N];
int cnt = 0;
void dfs(int parent)
{
    visited[parent] = true;
    for (int child : adjList[parent])
    {
        if (visited[child] == false)
        {
            cnt++;
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
    }
    int k;
    cin >> k;
    dfs(k);
    cout << cnt;

    return 0;
}