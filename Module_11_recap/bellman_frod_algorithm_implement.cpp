#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9 + 7;
vector<pair<int, int>> adjList[N];
vector<pair<pair<int, int>, int>> edgeList;
int d[N];

int n, m;

// implemnet bellman ford algorihtm
void bellmanFord(int source)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }

    d[source] = 0;

    for (int i = 1; i < n; i++)
    {
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

        for (auto childPair : edgeList)
        {
            int u = childPair.first.first;
            int v = childPair.first.second;
            int w = childPair.second;

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
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // adjList[u].push_back({v, w});
        edgeList.push_back({{u, v}, w});
    }

    int src = 1;
    // calling bellman ford algorithm
    bellmanFord(src);

    for (int i = 1; i <= n; i++)
    {
        cout << "Distance " << i << " : " << d[i] << endl;
    }
    return 0;
}