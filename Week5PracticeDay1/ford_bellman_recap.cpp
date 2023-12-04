#include <bits/stdc++.h>
using namespace std;

const int INF = 30000;

class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> v;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        v.push_back(ed);
    }

    int dis[n + 1];

    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }

    dis[1] = 0;

    // apply bellman ford algorithm
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            Edge ed = v[j];
            if (dis[ed.u] < INF && dis[ed.u] + ed.w < dis[ed.v])
            {
                dis[ed.v] = dis[ed.u] + ed.w;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    return 0;
}