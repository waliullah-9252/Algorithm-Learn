#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int save[N][N];

// knapsack memoization optimaization
int knapsack(int n, int s, int v[], int w[])
{
    // base case
    if (n == 0 || s == 0)
        return 0;
    if (save[n][s] != -1)
    {
        return save[n][s];
    }
    if (w[n - 1] <= s)
    {
        int op1 = knapsack(n - 1, s - w[n - 1], v, w) + v[n - 1];
        int op2 = knapsack(n - 1, s, v, w);
        return save[n][s] = max(op1, op2);
    }
    else
    {
        return save[n][s] = knapsack(n - 1, s, v, w);
    }
}

int main()
{
    int n;
    cin >> n;
    int v[n], w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    int s;
    cin >> s;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            save[i][j] = -1;
        }
    }

    int result = knapsack(n, s, v, w);
    cout << result << endl;
    return 0;
}