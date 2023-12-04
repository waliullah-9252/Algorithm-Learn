#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 6;
vector<int> adjList[N];
int dis[N];
bool visited[N];
int par[N];

void bfsPath(int source)
{
    queue<int> q;
    q.push(source);
    visited[source] = true;
    dis[source] = 0;
    par[source] = -1;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int child : adjList[parent])
        {
            if (!visited[child])
            {
                q.push(child);
                par[child] = parent;
                dis[child] = dis[parent] + 1;
                visited[child] = true;
            }
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

    // calling bfs
    bfsPath(1);

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "Node " << i << " : " << par[i] << endl;
    // }

    int d;
    cin >> d;

    if (visited[d])
    {
        int x = d;
        vector<int> path;
        while (x != -1)
        {
            path.push_back(x);
            x = par[x];
        }
        reverse(path.begin(), path.end());
        for (int val : path)
        {
            cout << val << " ";
        }
    }
    else
    {
        cout << "Path Not Found!" << endl;
    }
    return 0;
}