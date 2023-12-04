#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e3 + 5;
const int INF = 1e9 + 6;
vector<pii> adjList[N];
vector<int> dist(N, INF);
vector<bool> visited(N);

// implement dijkstra algorithm function
void dijkstra(int source)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[source] = 0;
    pq.push({dist[source], source});

    while (!pq.empty())
    {
        int val = pq.top().second;
        pq.pop();

        visited[val] = true;

        for (pii childPair : adjList[val])
        {
            int v = childPair.first;
            int w = childPair.second;

            if (visited[v])
                continue;

            if (dist[v] > dist[val] + w)
            {
                dist[v] = dist[val] + w;
                pq.push({dist[v], v});
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
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    // calling dijkstra algorithm function
    dijkstra(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "Distance of node " << i << " : " << dist[i] << endl;
    }
    return 0;
}