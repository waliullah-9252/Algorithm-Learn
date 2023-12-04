#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u;
    int v;
    int w;

    // constructor
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
    vector<Edge> edgeList;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        edgeList.push_back(ed);
    }

    int dis[n + 1];

    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }

    dis[1] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < edgeList.size(); j++)
        {
            Edge ed = edgeList[j];
            if (dis[ed.u] + ed.w < dis[ed.v])
            {
                dis[ed.v] = dis[ed.u] + ed.w;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "Nodes " << i << " : " << dis[i] << endl;
    }
    return 0;
}