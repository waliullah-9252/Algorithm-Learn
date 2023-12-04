#include <bits/stdc++.h>
using namespace std;
int findValue(int arr[], int l, int r, int k)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == k)
            return mid;
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
    int result = findValue(arr, 0, n - 1, k);
    if (result != -1)
        cout << result<<endl;
    else
        cout << "Not Found"<<endl;
    return 0;
}