#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<string> adj;
bool visited[N][N];
int level[N][N];
vector<pair<int, int>> direction = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

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

        for (auto child : direction)
        {
            int ni = i + child.first;
            int nj = j + child.second;

            if (isValid(ni, nj) && !visited[ni][nj] && adj[ni][nj] != 'x')
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
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
                si = i;
                sj = j;
            }
            if (x[j] == 'e')
            {
                di = i;
                dj = j;
            }
        }
        adj.push_back(x);
    }

    bfs(si, sj);

    if (!visited[n])
    {
        cout << -1 << endl;
        return 0;
    }

    if (level[di][dj] != 0)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
