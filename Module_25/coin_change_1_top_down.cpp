#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int coin_change(int s, int w[], int n)
{
    if (n == 0)
    {
        if (s == 0)
            return true;
        else
            return false;
    }
    if (dp[n][s] != -1)
        return dp[n][s];
    if (w[n - 1] <= s)
    {
        int ch1 = coin_change(s - w[n - 1], w, n);
        int ch2 = coin_change(s, w, n - 1);
        return dp[n][s] = ch1 + ch2;
    }
    else
    {
        return dp[n][s] = coin_change(s, w, n - 1);
    }
}

int main()
{
    int s, n;
    cin >> s >> n;
    int w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    memset(dp, -1, sizeof(dp));
    int result = coin_change(s, w, n);
    cout << result << endl;
    return 0;
}