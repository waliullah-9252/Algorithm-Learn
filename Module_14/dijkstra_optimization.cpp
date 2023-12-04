#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<pair<int, int>> adjList[N];
int dis[N];
bool visited[N];

void dijkstra(int source)
{
    dis[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dis[source], source});

    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();

        int parentNode = parent.second;

        if (visited[parentNode])
            continue;
        visited[parentNode] = true;

        int parentCost = parent.first;

        for (int i = 0; i < adjList[parentNode].size(); i++)
        {
            pair<int, int> child = adjList[parentNode][i];

            int childNode = child.first;
            int childCost = child.second;

            if (parentCost + childCost < dis[childNode])
            {
                dis[childNode] = parentCost + childCost;
                pq.push({dis[childNode], childNode});
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adjList[a].push_back({b, w});
        adjList[b].push_back({a, w});
    }

    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }

    // calling dijkstra optimaization version
    dijkstra(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "Distance " << i << " : " << dis[i] << endl;
    }
    return 0;
}