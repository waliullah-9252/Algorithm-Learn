#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int adjMatrix[N][N];
const int M = 1e6+1;
vector<int> adjList[M];

int main()
{
    //input adjacency matrix
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>adjMatrix[i][j];
        }
    }
    
    //converted adjacency matrix to adjacency list
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

    //printing adjacency list
    for(int i=1;i<=n;i++)
    {
        cout<<"List "<<i<<" : ";
        for(int val: adjList[i])
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}