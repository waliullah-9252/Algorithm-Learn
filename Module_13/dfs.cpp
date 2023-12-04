#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 6;
bool visited[N];
vector<int> adjList[N];

void dfs(int source)
{
    visited[source] = true;
    cout << source << endl;
    // for (int i = 0; i < adjList[source].size(); i++)
    // {
    //     int child = adjList[source][i];
    //     if (!visited[child])
    //     {
    //         dfs(child);
    //     }
    // }
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

    // calling dfs
    dfs(1);
    return 0;
}