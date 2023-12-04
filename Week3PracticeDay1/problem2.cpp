#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long int INF = 1e18;
vector<pair<int, int>> adjList[N];
long long int d[N];
bool visited[N];

int n, m;

void dijkstra(int source)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }

    d[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({d[source], source});

    while (!pq.empty())
    {
        pair<int, int> f = pq.top();
        pq.pop();

        int selectedNodes = f.second;

        if (visited[selectedNodes])
            continue;
        visited[selectedNodes] = true;

        for (auto childPair : adjList[selectedNodes])
        {
            int costEdge = childPair.first;
            int v = childPair.second;

            if (d[selectedNodes] + costEdge < d[v])
            {
                d[v] = d[selectedNodes] + costEdge;
                pq.push({d[v], v});
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
        adjList[u].push_back({w, v});
    }

    int source, distance;
    cin >> source >> distance;
    dijkstra(source);
    cout<<d[distance];
    return 0;
}