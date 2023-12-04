#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 6;
int save[N];

int frog(int a[], int n)
{
    // base case
    if (n == 1)
    {
        return 0;
    }
    // memoization
    if (save[n] != -1)
    {
        return save[n];
    }
    else if (n == 2)
    {
        return save[n] = abs(a[n] - a[n - 1]);
    }
    else
    {
        int choice1 = frog(a, n - 1) + abs(a[n] - a[n - 1]);
        int choice2 = frog(a, n - 2) + abs(a[n] - a[n - 2]);
        return save[n] = min(choice1, choice2);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        save[i] = -1;
        cin >> a[i];
    }
    cout << frog(a, n) << endl;
    return 0;
}