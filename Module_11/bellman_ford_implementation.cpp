#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9 + 6;
vector<pair<int, int>> adjList[N];
vector<pair<pair<int, int>, int>> edgesList;
int d[N];

int n, m;

void bellman_ford(int source)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }

    d[source] = 0;

    for (int i = 1; i < n; i++)
    {
        // all relaxation
        // for (int u = 1; u <= n; u++)
        // {
        //     for (pair<int, int> childPair : adjList[u])
        //     {
        //         int v = childPair.first;
        //         int w = childPair.second;

        //         if (d[v] > d[u] + w)
        //         {
        //             d[v] = d[u] + w;
        //         }
        //     }
        // }
        for (auto edge : edgesList)
        {
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;

            if (d[u] != INF && d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // adjList[u].push_back({v, w});
        edgesList.push_back({{u, v}, w});
    }

    int src = 1;

    bellman_ford(src);

    for (int i = 1; i <= n; i++)
    {
        cout << "Distance of " << i << " : " << d[i] << endl;
    }
    return 0;
}