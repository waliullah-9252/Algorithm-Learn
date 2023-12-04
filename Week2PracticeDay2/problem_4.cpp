#include <bits/stdc++.h>
using namespace std;
const int n = 1e6 + 5;
vector<int> adjList[n];
int visited[n];

void bfs(int parent)
{
    queue<int> q;
    q.push(parent);
    visited[parent] = 1;

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

    int cc = 0;
    for(int i=1;i<=n;i++)
    {
        if(visited[i] == 0)
        {
            bfs(i);
            cc++;
        }
    }
    cout<<cc;
    
    return 0;
}