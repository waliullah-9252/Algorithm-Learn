#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n];
        int s = 1000 - m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int dp[n + 1][s + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= s; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                if (a[i - 1] <= j)
                {
                    dp[i][j] = (dp[i][j - a[i - 1]] + dp[i - 1][j]) % MOD;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] % MOD;
                }
            }
        }
        if (dp[n][s] == 0)
            cout << 0 << endl;
        else
            cout << dp[n][s] << endl;
    }
    return 0;
}