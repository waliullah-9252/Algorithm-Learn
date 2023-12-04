#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int INF = 1e9 + 7;
int adjMatrix[N][N];

int n, m;

void print_matrix()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adjMatrix[i][j] == INF)
                cout << "X"
                     << " ";
            else
                cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void dist_initialize()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                adjMatrix[i][j] = INF;
            }
        }
    }
}
int main()
{
    cin >> n >> m;

    dist_initialize();

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjMatrix[u][v] = w;
        // adjMatrix[v][u] = w;
    }

    print_matrix();

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
            }
        }
    }

    cout<<endl<<"After implement floyd warshall algorithm"<<endl;
    print_matrix();
    return 0;
}