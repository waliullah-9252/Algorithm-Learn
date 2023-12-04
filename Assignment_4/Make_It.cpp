#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 6;
int dp[N];

bool subset_sum(int cur, int n)
{
    if (n < cur)
        return false;
    if (n == cur)
        return true;
    if (dp[cur] != -1)
        return dp[cur];
    bool op1 = subset_sum(cur + 3, n);
    bool op2 = subset_sum(cur * 2, n);
    return dp[cur] = op1 || op2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i <= n; i++)
        {
            dp[i] = -1;
        }
        int cur = 1;
        if (subset_sum(cur, n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
