#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int nums[N];

// merge sort inplementation function
void mergeSortImplementation(int l, int r, int mid)
{
    int leftSize = mid - l + 1;
    int L[leftSize + 1];

    int rightSize = r - mid;
    int R[rightSize + 1];

    for (int i = l, j = 0; i <= mid; i++, j++)
        L[j] = nums[i];

    for (int i = mid + 1, j = 0; i <= r; i++, j++)
        R[j] = nums[i];

    L[leftSize] = INT_MAX;
    R[rightSize] = INT_MAX;

    int lp = 0, rp = 0;
    for (int i = l; i <= r; i++)
    {
        if (L[lp] <= R[rp])
        {
            nums[i] = L[lp];
            lp++;
        }
        else
        {
            nums[i] = R[rp];
            rp++;
        }
    }
}

// merge sort function
void mergeSort(int l, int r)
{
    // base case
    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    mergeSortImplementation(l, r, mid);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    mergeSort(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}