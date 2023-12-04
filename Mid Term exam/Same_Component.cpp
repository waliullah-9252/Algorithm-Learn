#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

const int N = 1e3 + 7;
char a[N][N];
bool visited[N][N];
int n, e;
vector<pii> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

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
    for (int i = 0; i < 4; i++)
    {
        pii pi = moves[i];

        int ci = si + pi.first;
        int cj = sj + pi.second;

        if (isValid(ci, cj) && !visited[ci][cj] && a[ci][cj] == '.')
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    int si, sj, di, dj;
    cin >> n >> e;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < e; j++)
        {
            cin >> a[i][j];
        }
    }

    cin >> si >> sj >> di >> dj;
    dfs(si, sj);

    if (visited[si][sj] == visited[di][dj])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}