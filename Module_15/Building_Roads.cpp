#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> adjList[N];
bool visited[N];

void dfs(int source)
{
    visited[source] = true;
    for (int child : adjList[source])
    {
        if (!visited[child])
        {
            dfs(child);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    vector<int> path;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            path.push_back(i);
        }
    }
    cout << path.size() - 1 << endl;
    for (int i = 0; i < path.size() - 1; i++)
    {
        cout << path[i] << " " << path[i + 1] << endl;
    }

    return 0;
}