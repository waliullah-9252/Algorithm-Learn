#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int coin_change_2(int n, int w[], int s)
{
    // base case
    if (n == 0)
    {
        if (s == 0)
            return 0;
        else
            return INT_MAX - 1;
    }
    if(dp[n][s] != -1) return dp[n][s];
    if (w[n - 1] <= s)
    {
        int ch1 = coin_change_2(n, w, s - w[n - 1]) + 1;
        int ch2 = coin_change_2(n - 1, w, s);
        return dp[n][s] = min(ch1, ch2);
    }
    else
    {
        return dp[n][s] = coin_change_2(n - 1, w, s);
    }
}

int main()
{
    int n;
    cin >> n;
    int w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    int s;
    cin >> s;
    memset(dp,-1,sizeof(dp));
    int result = coin_change_2(n, w, s);
    if (result == INT_MAX - 1)
        cout << -1 << endl;
    else
        cout << result << endl;
    return 0;
}