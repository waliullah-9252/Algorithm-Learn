#include <bits/stdc++.h>
using namespace std;
int arr[21];
int n, x;

bool check_result(long long sum, int i)
{
    // base case
    if (i == n)
    {
        return sum == x;
    }
    bool op1 = check_result(sum + arr[i], i + 1);
    bool op2 = check_result(sum - arr[i], i + 1);
    return op1 || op2;
}

int main()
{

    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (check_result(arr[0], 1))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}