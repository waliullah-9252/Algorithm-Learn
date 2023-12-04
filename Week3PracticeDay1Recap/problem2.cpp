#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 6;
const int INF = 1e9 + 7;
vector<pair<int, int>> adjList[N];
int direction[N];
bool visited[N];

int n, m;

void dijkstra(int source)
{
    for (int i = 1; i <= n; i++)
    {
        direction[i] = INF;
    }

    direction[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({direction[source], source});

    while (!pq.empty())
    {
        pair<int, int> f = pq.top();
        pq.pop();

        int selectedNodes = f.second;

        if (visited[selectedNodes])
            continue;
        visited[selectedNodes] = true;

        for (pair<int, int> childPair : adjList[selectedNodes])
        {
            int costEdge = childPair.first;
            int v = childPair.second;

            if (direction[selectedNodes] != INF && direction[v] > direction[selectedNodes] + costEdge)
            {
                direction[v] = direction[selectedNodes] + costEdge;
                pq.push({direction[v], v});
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

    // calling dijkstra algorithm
    dijkstra(source);

    cout << direction[distance];
    return 0;
}