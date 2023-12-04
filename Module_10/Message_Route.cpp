#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 6;
vector<int> adjList[N];
int visited[N];
int level[N];
vector<int> parent(N, -1);

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    visited[source] = 1;

    while (!q.empty())
    {
        int val = q.front();
        q.pop();

        for (int child : adjList[val])
        {
            if (visited[child] == 0)
            {
                q.push(child);
                visited[child] = 1;
                parent[child] = val;
                level[child] = level[val] + 1;
            }
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

    int src = 1;

    bfs(src);

    if (!visited[n])
        cout << "IMPOSSIBLE" << endl;

    else
    {
        cout << level[n] + 1 << endl;
        int curr = n;
        vector<int> path;
        while (curr != -1)
        {
            path.push_back(curr);
            curr = parent[curr];
        }

        reverse(path.begin(), path.end());

        for (auto p : path)
        {
            cout << p << " ";
        }
    }
    return 0;
}