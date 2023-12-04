#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
vector<int> adjList[N];
const int M = 1e3+5;
int adjMatrix[M][M];
int main()
{
    int n,m;
    cin>>n>>m;
    //input adjancy list
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
    }

    //convert adjancy list to adjancy matrix
    for(int i=1;i<=n;i++)
    {
        for(int child: adjList[i])
        {
            adjMatrix[i][child] = 1;
        }
    }

    //adjancy matrix print
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}