#include <bits/stdc++.h>
using namespace std;
void mergeSortImplementation(int arr[], int l, int r, int mid)
{
    int leftSize = mid - l + 1;
    int L[leftSize + 1];

    int rightSize = r - mid - 1 + 1;
    int R[rightSize + 1];

    for (int i = l, j = 0; i <= mid; i++, j++)
        L[j] = arr[i];

    for (int i = mid + 1, j = 0; i <= r; i++, j++)
        R[j] = arr[i];

    L[leftSize] = INT_MIN;
    R[rightSize] = INT_MIN;

    int lp = 0, rp = 0;
    for (int i = l; i <= r; i++)
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
void mergeSort(int arr[], int l, int r)
{
    // base case
    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    mergeSortImplementation(arr, l, r, mid);
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