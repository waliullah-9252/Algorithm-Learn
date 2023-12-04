// #include <bits/stdc++.h>
// using namespace std;

// int dp[1005][1005];

// bool subset_sum(int n, int arr[], int s)
// {
//     // base case
//     if (n == 0)
//     {
//         if (s == 0)
//             return true;
//         else
//             return false;
//     }
//     if (dp[n][s] != -1)
//         return dp[n][s];
//     if (arr[n - 1] <= s)
//     {
//         bool op1 = subset_sum(n, arr, s - arr[n - 1]);
//         bool op2 = subset_sum(n - 1, arr, s);
//         return dp[n][s] = op1 || op2;
//     }
//     else
//     {
//         return dp[n][s] = subset_sum(n - 1, arr, s);
//     }
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, m;
//         cin >> n >> m;
//         int arr[n];
//         int s = 1000 - m;
//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//         }

//         for (int i = 0; i <= n; i++)
//         {
//             for (int j = 0; j <= m; j++)
//             {
//                 dp[i][j] = -1;
//             }
//         }

//         bool result = subset_sum(n, arr, s);
//         if (result)
//             cout << "YES" << endl;
//         else
//             cout << "NO" << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
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
        bool dp[n + 1][s + 1];
        dp[0][0] = true;
        for (int i = 1; i <= s; i++)
        {
            dp[0][i] = false;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                if (a[i - 1] <= j)
                {
                    dp[i][j] = dp[i][j - a[i - 1]] || dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        if (dp[n][s])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}