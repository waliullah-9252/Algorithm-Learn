#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

// implement knapsack function
int knapSack(int n, int s, int w[], int v[])
{
    // base case
    if (n == 0 || s == 0)
        return 0;
    if (dp[n][s] != -1)
        return dp[n][s];
    if (w[n - 1] <= s)
    {
        int op1 = knapSack(n - 1, s - w[n - 1], w, v) + v[n - 1];
        int op2 = knapSack(n - 1, s, w, v);
        return dp[n][s] = max(op1, op2);
    }
    else
    {
        return dp[n][s] = knapSack(n - 1, s, w, v);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        int w[n], v[n];
        for (int i = 0; i < n; i++)
        {
            cin >> w[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                dp[i][j] = -1;
            }
        }

        // calling knapsack function
        int result = knapSack(n, s, w, v);
        cout << result << endl;
    }
    return 0;
}