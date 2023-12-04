#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 6;
int parent[N];
int parentSize[N];

void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}

int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}

void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);

    if (leaderA != leaderB)
    {
        if (parentSize[leaderA] > parentSize[leaderB])
        {
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}

int main()
{
    int n;
    cin >> n;
    dsu_set(n);
    vector<pair<int, int>> cycleDetect;
    vector<pair<int, int>> new_roads;
    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA == leaderB)
            cycleDetect.push_back({a, b});
        else
        {
            dsu_union(a, b);
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (dsu_find(1) != dsu_find(i))
        {
            new_roads.push_back({1, i});
            dsu_union(1, i);
        }
    }

    int noEdge = new_roads.size();
    cout << noEdge << endl;

    for (int i = 0; i < noEdge; i++)
    {
        cout << cycleDetect[i].first << " " << cycleDetect[i].second << " " << new_roads[i].first << " " << new_roads[i].second << endl;
    }

    return 0;
}
