#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 6;
vector<string> adj;
int level[N][N];
bool visited[N][N];
pair<int, int> parent[N][N];

vector<pair<int, int>> direc = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m;

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> f = q.front();
        q.pop();

        int i = f.first;
        int j = f.second;

        for (pair<int, int> child : direc)
        {
            int ni = i + child.first;
            int nj = j + child.second;

            if (isValid(ni, nj) && !visited[ni][nj] && adj[i][j] != 'x')
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
                parent[ni][nj] = {i, j};
            }
        }
    }
}
int main()
{
    int si, sj, di, dj;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        for (int j = 0; j < m; j++)
        {
            if (x[j] == 's')
            {
                si = i, sj = j;
            }
            if (x[j] == 'e')
            {
                di = i, dj = j;
            }
        }
        adj.push_back(x);
    }

    // calling bfs
    bfs(si, sj);

    if (level[di][dj] != 0)
    {
        cout << level[di][dj];
    }
    else
        cout << -1;
    return 0;
}