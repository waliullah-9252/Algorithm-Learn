#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e3 + 7;
vector<string> adjMatrix;
bool visited[N][N];
vector<pii> direc = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int n, m;

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void dfs(int i, int j)
{
    if (!isValid(i, j))
        return;
    if (visited[i][j])
        return;
    if (adjMatrix[i][j] == '#')
        return;

    visited[i][j] = true;

    for (auto d : direc)
    {
        dfs(i + d.first, i + d.second);
    }

    // dfs(i, j - 1);
    // dfs(i, j + 1);
    // dfs(i - 1, j);
    // dfs(i + 1, j);
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        adjMatrix.push_back(x);
    }

    int room = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j])
                continue;
            if (adjMatrix[i][j] == '#')
                continue;
            dfs(i, j);
            room++;
        }
    }

    cout << room << endl;
    return 0;
}