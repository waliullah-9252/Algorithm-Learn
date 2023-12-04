#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int level[N];
bool visited[N];
vector<int> adjList[N];

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    visited[source] = true;
    level[source] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        cout << parent << endl;
        for (int i = 0; i < adjList[parent].size(); i++)
        {
            int child = adjList[parent][i];
            if (visited[child] == false)
            {
                q.push(child);
                level[child] = level[parent] + 1;
                visited[child] = true;
            }
        }
        // for (int child : adjList[parent])
        // {
        //     if (visited[child] == false)
        //     {
        //         q.push(child);
        //         visited[child] = true;
        //         level[child] = level[parent] + 1;
        //     }
        // }
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

    // calling bfs traversal
    bfs(1);
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "Node Level " << i << " : " << level[i] << endl;
    }
    return 0;
}