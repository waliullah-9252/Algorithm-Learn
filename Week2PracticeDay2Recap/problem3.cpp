#include <bits/stdc++.h>
using namespace std;
const int n = 1e6 + 5;
vector<int> adjList[n];
int visited[n];

int dfsCycle(int parent, int p = -1)
{
    visited[parent] = 1;
    int cycleExists = 0;
    for (int child : adjList[parent])
    {
        if (child == p)
            continue;
        if (visited[child])
            return 1;
        cycleExists = cycleExists | dfsCycle(child, parent);
    }
    return cycleExists;
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

    // int isCycle = dfsCycle(1);
    // if (isCycle == 1)
    //     cout << "YES" << endl;
    // else
    //     cout << "NO" << endl;

    int isCycle = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            isCycle = isCycle | dfsCycle(i);
        }
    }
    if (isCycle == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}