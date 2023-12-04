#include <bits/stdc++.h>
using namespace std;

const long long int N = 1e6 + 5;
long long int dp[N];

bool subset_sum(long long int cur,long long int n)
{
    if (cur == n)
        return true;
    if (n < cur)
        return false;
    if (dp[cur] != -1)
        return dp[cur];
    bool op1 = subset_sum(cur * 10, n);
    bool op2 = subset_sum(cur * 20, n);
    return dp[cur] = op1 || op2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;

        for (long long int i = 1; i <= n; i++)
        {
            dp[i] = -1;
        }

        long long int cur = 1;

        if (subset_sum(cur, n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}