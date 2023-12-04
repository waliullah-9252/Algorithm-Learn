#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<pair<int, int>> adjList[N];
int dis[N];

void dijkstra_naive(int source)
{
    queue<int> q;
    q.push(source);
    dis[source] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int i = 0; i < adjList[parent].size(); i++)
        {
            pair<int, int> child = adjList[parent][i];

            int childNode = child.first;
            int childCost = child.second;

            if (dis[parent] + childCost < dis[childNode])
            {
                dis[childNode] = dis[parent] + childCost;
                q.push(childNode);
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

    // calling dijkstra naive
    dijkstra_naive(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "Distance " << i << " : " << dis[i] << endl;
    }
    return 0;
}