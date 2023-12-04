#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
int visited[N];
int level[N];

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
    int l;
    cin >> l;
    if(l == 0)
    {
        cout<<0;
        return 0;
    }
    int src = 0;
    bfs(src);
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (level[i] == l)
        {
            v.push_back(i);
        }
    }
    if (v.size() == 0)
    {
        cout << -1;
    }
    else
    {
        sort(v.begin(), v.end());
        for (int val : v)
        {
            cout << val << " ";
        }
    }
    return 0;
}
