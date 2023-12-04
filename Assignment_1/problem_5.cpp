#include <bits/stdc++.h>
using namespace std;
void mergeSort(int arr1[], int arr2[], int n, int m, int result[])
{
    int i = 0, j = 0, k = 0;
    while (i < n && i < m)
    {
        if (arr1[i] >= arr2[j])
        {
            result[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            result[k] = arr2[j];
            j++;
            k++;
        }
    }

    while (i < n)
    {
        result[k++] = arr1[i++];
    }

    while (j < m)
    {
        result[k++] = arr2[j++];
    }
}
int main()
{
    int n;
    cin >> n;
    int arr1[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    int m;
    cin >> m;
    int arr2[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    int result[n + m];
    mergeSort(arr1, arr2, n, m, result);
    for (int i = 0; i < n + m; i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}