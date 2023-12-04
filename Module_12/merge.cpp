#include <bits/stdc++.h>
using namespace std;

void mergeSort(int a[], int l, int m, int r)
{
    int leftSize = m - l + 1;
    int rightSize = r - m;
    int L[leftSize], R[rightSize];
    int k = 0;
    for (int i = l; i <= m; i++)
    {
        L[k] = a[i];
        k++;
    }
    k = 0;
    for (int i = m + 1; i <= r; i++)
    {
        R[k] = a[i];
        k++;
    }
    int i = 0, j = 0;
    int curr = l;
    while (i < leftSize && j < rightSize)
    {
        if (L[i] <= R[j])
        {
            a[curr] = L[i];
            i++;
        }
        else
        {
            a[curr] = R[j];
            j++;
        }
        curr++;
    }

    while (i < leftSize)
    {
        a[curr] = L[i];
        i++;
        curr++;
    }

    while (j < rightSize)
    {
        a[curr] = R[j];
        j++;
        curr++;
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergeSort(a, 0, 3, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}