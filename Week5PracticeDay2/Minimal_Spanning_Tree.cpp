#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

const int N = 1e5 + 6;
vector<pii> adjList[N];
bool vis[N];

class Edge
{
public:
    int a, b, w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

class cmp
{
public:
    bool operator()(Edge a, Edge b)
    {
        return a.w > b.w;
    }
};

void prims(int s)
{
    priority_queue<Edge, vector<Edge>, cmp> pq;
    pq.push(Edge(s, s, 0));
    vector<Edge> edgeList;
    while (!pq.empty())
    {
        Edge parnet = pq.top();
        pq.pop();
        int a = parnet.a;
        int b = parnet.b;
        int w = parnet.w;
        if (vis[b])
            continue;
        vis[b] = true;
        edgeList.push_back(parnet);

        for (auto child : adjList[b])
        {
            if (!vis[child.first])
            {
                pq.push(Edge(b, child.first, child.second));
            }
        }
    }
    edgeList.erase(edgeList.begin());

    int sum = 0;

    for (auto v : edgeList)
    {
        sum += v.w;
    }
    cout << sum;
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

    // calling prim's algorithm
    prims(1);
    return 0;
}