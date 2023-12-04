#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18 + 5;

class Edge
{
public:
    long long int a, b, w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
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
        long long int a, b, w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        v.push_back(ed);
    }

    long long int dis[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }

    int s;
    cin >> s;
    dis[s] = 0;

    // Bellman Ford algorithm
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            Edge ed = v[j];
            if (dis[ed.a] != INF && dis[ed.a] + ed.w < dis[ed.b])
            {
                dis[ed.b] = dis[ed.a] + ed.w;
            }
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int d;
        cin >> d;

        // Cycle detection
        bool cycleDetect = false;
        for (int j = 0; j < v.size(); j++)
        {
            Edge ed = v[j];
            if (dis[ed.a] != INF && dis[ed.a] + ed.w < dis[ed.b])
            {
                cycleDetect = true;
            }
        }

        if (cycleDetect)
        {
            cout << "Negative Cycle Detected" << endl;
            break;
        }
        else if (dis[d] != INF)
        {
            cout << dis[d] << endl;
        }
        else
        {
            cout << "Not Possible" << endl;
        }
    }

    return 0;
}
