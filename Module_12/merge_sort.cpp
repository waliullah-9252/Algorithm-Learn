#include <bits/stdc++.h>
using namespace std;

void merge_sort(int a[], int l, int m, int r)
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
    int cur = l;

    while (i < leftSize && j < rightSize)
    {
        if (L[i] <= R[j])
        {
            a[cur++] = L[i++];
        }
        else
        {
            a[cur++] = R[j++];
        }
    }

    while (i < leftSize)
    {
        a[cur++] = L[i++];
    }

    while (j < rightSize)
    {
        a[cur++] = R[j++];
    }
}

void divide(int a[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        divide(a, l, mid);
        divide(a, mid + 1, r);

        merge_sort(a, l, mid, r);

        // cout<<"This"<<endl;
        // for(int i=l;i<=mid;i++)
        // {
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=mid+1;i<=r;i++)
        // {
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
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
    divide(a, 0, n - 1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}