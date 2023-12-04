#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int adjMatrix[N][N];
const int M = 1e6+5;
vector<int> adjList[M];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> adjMatrix[i][j];
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(adjMatrix[i][j] == 1)
            {
                adjList[i].push_back(j);
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        cout<<"List "<<i<<" : ";
        for(int v: adjList[i])
        {
            cout<<v<<" ";
        }
        cout<<endl;
    }

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         cout<<adjMatrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}