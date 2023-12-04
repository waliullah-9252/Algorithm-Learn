#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int r, int mid)
{
    int lS = mid - l + 1;
    int L[lS + 1];

    int rS = r - mid;
    int R[rS + 1];

    for (int i = l, j = 0; i <= mid; i++, j++)
        L[j] = arr[i];
    for (int i = mid + 1, j = 0; i <= r; i++, j++)
        R[j] = arr[i];

    L[lS] = INT_MIN;
    R[rS] = INT_MIN;

    int lp = 0, rp = 0;
    for (int i = 0; i <= r; i++)
    {
        if (L[lp] >= R[rp])
        {
            arr[i] = L[lp];
            lp++;
        }
        else
        {
            arr[i] = R[rp];
            rp++;
        }
    }
}

// merge sort funtion
void mergeSort(int arr[], int l, int r)
{
    // base case
    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, r, mid);
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
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}