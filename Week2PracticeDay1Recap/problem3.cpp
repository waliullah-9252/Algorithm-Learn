#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> adjList[N];
const int M = 1e3 + 5;
int adjMatrix[M][M];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    // convert adjacency list to adjacency matrix
    for (int i = 1; i <= n; i++)
    {
        for (int child : adjList[i])
        {
            adjMatrix[i][child] = 1;
        }
    }

    // printing adjacency matrix
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}