#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long int INF = 1e18;
vector<pair<int, int>> adjList[N];
long long int d[N];
bool visited[N];
int parent[N];

int nodes, edges;

void dijkstra(int source)
{
    for (int i = 1; i <= nodes; i++)
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

        int slectedNodes = f.second;

        if (visited[slectedNodes])
            continue;
        visited[slectedNodes] = true;

        for (auto childPair : adjList[slectedNodes])
        {
            int edgeCost = childPair.first;
            int v = childPair.second;

            if (d[slectedNodes] + edgeCost < d[v])
            {
                d[v] = d[slectedNodes] + edgeCost;
                pq.push({d[v], v});
                parent[v] = slectedNodes;
            }
        }
    }
}
int main()
{
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({w, v});
        adjList[v].push_back({w, u});
    }

    int src = 1;
    dijkstra(src);

    if(!visited[nodes])
    {
        cout<<-1<<endl;
        return 0;
    }

    int current = nodes;
    vector<int> path;

    while (true)
    {
        path.push_back(current);
        if (current == src)
        {
            break;
        }
        current = parent[current];
    }

    reverse(path.begin(), path.end());

    for (auto val : path)
    {
        cout << val << " ";
    }
    cout << endl;

    // for(int i=1;i<=nodes;i++)
    // {
    //     cout<<d[i]<<" ";
    // }
    return 0;
}