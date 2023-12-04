#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> adjList[N];
int visited[N];
int level[N];

// bfs function
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
        cout << "Visiting Node: " << val << endl;
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

    int src = 1;

    // calling bfs function
    bfs(src);
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "Level of Nodes " << i << " : " << level[i] << endl;
    }

    return 0;
}

/*
12
11
1 2
1 3
1 10
2 4
2 5
3 9
10 11
10 12
5 6
5 7
7 8



7
8
1 2
1 3
2 4
2 5
2 7
3 4
4 6
7 6
*/