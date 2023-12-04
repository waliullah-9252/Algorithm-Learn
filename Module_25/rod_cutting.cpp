#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int unbounded_knapsack(int n, int s, int val[], int weight[])
{
    // base case
    if (n == 0 || s == 0)
        return 0;
    if (dp[n][s] != -1)
        dp[n][s];
    if (weight[n - 1] <= s)
    {
        return dp[n][s] = max(unbounded_knapsack(n, s - weight[n - 1], val, weight) + val[n - 1], unbounded_knapsack(n - 1, s, val, weight));
    }
    else
    {
        return unbounded_knapsack(n - 1, s, val, weight);
    }
}

int main()
{
    int n;
    cin >> n;
    int val[n], weight[n];
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
        weight[i] = i + 1;
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
    int result = unbounded_knapsack(n, n, val, weight);
    cout << result << endl;
    return 0;
}