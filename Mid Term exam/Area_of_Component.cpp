#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

const int N = 1e3 + 5;
char a[N][N];
bool visited[N][N];
int n, e;
vector<pii> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int cnt;

bool isValid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < e)
        return true;
    else
        return false;
}

void dfs(int si, int sj)
{
    visited[si][sj] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        pii p = moves[i];

        int ci = si + p.first;
        int cj = sj + p.second;

        if (isValid(ci, cj) && !visited[ci][cj] && a[ci][cj] == '.')
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    int mn = INT_MAX;
    cin >> n >> e;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < e; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < e; j++)
        {
            if (!visited[i][j] && a[i][j] == '.')
            {
                cnt = 0;
                dfs(i, j);
                mn = min(cnt, mn);
            }
        }
    }
    if (cnt == 0)
        cout << -1;
    else
        cout << mn;

    return 0;
}