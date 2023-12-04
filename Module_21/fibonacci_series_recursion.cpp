#include <bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    // base case
    if (n == 0 || n == 1)
        return 1;
    int ans1 = fibo(n - 1);
    int ans2 = fibo(n - 2);
    return ans1 + ans2;
}

int main()
{
    int n;
    cin >> n;
    int result = fibo(n);
    cout << result;
    return 0;
}