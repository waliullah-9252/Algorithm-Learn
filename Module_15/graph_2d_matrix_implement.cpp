#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

const int N = 1e3 + 7;
bool visited[N][N];
int dis[N][N];
vector<pii> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool isValid(int childI, int childJ)
{
    if (childI >= 0 && childI < n && childJ >= 0 && childJ < m)
        return true;
    else
        return false;
}

void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    visited[si][sj] = true;
    dis[si][sj] = 0;
    while (!q.empty())
    {
        pii parent = q.front();
        q.pop();

        int pi = parent.first;
        int pj = parent.second;

        for (int i = 0; i < 4; i++)
        {
            pii m = moves[i];
            int childI = pi + m.first;
            int childJ = pj + m.second;

            if (isValid(childI, childJ) && !visited[childI][childJ])
            {
                visited[childI][childJ] = true;
                q.push({childI, childJ});
                dis[childI][childJ] = dis[pi][pj] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    char arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj;
    // calling bfs algorithm
    bfs(si, sj);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}