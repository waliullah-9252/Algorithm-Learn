#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adjList[n + 1];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     cout << "Index" << i << " : ";
    //     for (int j = 0; j < adjList[i].size(); j++)
    //     {
    //         cout << adjList[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for(int i=0;i<=n;i++)
    {
        cout<<"Index "<<i<<" : ";
        for(int val: adjList[i])
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}