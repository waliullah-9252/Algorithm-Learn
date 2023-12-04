#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

const int N = 110;
int level[N][N];
bool vis[N][N];
vector<pii> moves = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};

bool isValid(int ci, int cj, int n, int m)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < m)
        return true;
    else
        return false;
}

void bfs(int ki, int kj, int n, int m)
{
    queue<pii> q;
    q.push({ki, kj});
    vis[ki][kj] = true;
    level[ki][kj] = 0;

    while (!q.empty())
    {
        pii p = q.front();
        q.pop();

        int pi = p.first;
        int pj = p.second;

        for (int i = 0; i < 8; i++)
        {
            pii child = moves[i];
            int ci = pi + child.first;
            int cj = pj + child.second;

            if (isValid(ci, cj, n, m) && level[ci][cj] == -1)
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[pi][pj] + 1;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int ki, kj, qi, qj;
        cin >> ki >> kj >> qi >> qj;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                level[i][j] = -1;
            }
        }
        // calling bfs
        bfs(ki, kj, n, m);
        if (!vis[qi][qj])
            cout << -1 << endl;
        cout << level[qi][qj] << endl;
    }
    return 0;
}