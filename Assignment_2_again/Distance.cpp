#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adjList[N];
bool visited[N];
int level[N];

void bfs(int parent)
{
    queue<int> q;
    q.push(parent);
    visited[parent] = true;
    while (!q.empty())
    {
        int val = q.front();
        q.pop();
        for (int child : adjList[val])
        {
            if (visited[child])
                continue;
            q.push(child);
            visited[child] = true;
            level[child] = level[val] + 1;
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

    int q;
    cin >> q;
    while (q--)
    {
        int f, d;
        cin >> f >> d;
        for (int i = 0; i < N; i++)
        {
            level[i] = 0;
            visited[i] = 0;
        }
        bfs(f);

        if (visited[d] == false)
            cout << -1 << endl;
        else
            cout << level[d] << endl;
    }

    return 0;
}
