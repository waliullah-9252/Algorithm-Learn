#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

const int N = 1e3 + 5;
vector<pii> adjList[N];
bool visited[N];
long long int dis[N];
long long int n, e;

// implement bellman ford algorithm
void bellman_ford(int source)
{
    dis[source] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (pii childPair : adjList[u])
            {
                int v = childPair.first;
                int w = childPair.second;

                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> e;
    while (e--)
    {
        long long int a, b, w;
        cin >> a >> b >> w;
        adjList[a].push_back({b, w});
    }

    for (long long int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }

    long long int source;
    cin >> source;

    // calling belman ford function
    bellman_ford(source);

    long long int t;
    cin >> t;
    while (t--)
    {
        long long int d, dc;
        cin >> d >> dc;
        if (dis[d] <= dc)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}