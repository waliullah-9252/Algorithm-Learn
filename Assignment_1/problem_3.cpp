#include <bits/stdc++.h>
using namespace std;
int findFirstValue(int arr[], int l, int r, int k)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == k)
            return arr[mid];
        else if (arr[mid] < k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}
int findSecondValue(int arr[], int l, int r, int k)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == k)
            return arr[mid + 1];
        else if (arr[mid] < k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;

    int first = findFirstValue(arr, 0, n - 1, k);
    int second = findSecondValue(arr, 0, n - 1, k);
    if (first == second)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
