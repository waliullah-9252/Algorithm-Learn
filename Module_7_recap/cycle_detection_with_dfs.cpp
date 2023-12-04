#include<bits/stdc++.h>
using namespace std;
const int n = 1e6+5;
vector<int> adjList[n];
int visited[n];

//cycle detected dfs function
int dfsCycle(int parent,int p=-1)
{
    int cycleExsits = 0;
    visited[parent] = 1;
    for(int child: adjList[parent])
    {
        if(child == p) continue;
        if(visited[child]) return 1;
        cycleExsits = cycleExsits | dfsCycle(child,parent);
    }
    return cycleExsits;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // int src = dfsCycle(1);
    // if(src == 1) cout<<"Cycle Detected!"<<endl;
    // else cout<<"No Cycle!"<<endl;

    int isCycle = 0;
    for(int i=1;i<=n;i++)
    {
        if(visited[i] == 0)
        {
            isCycle = isCycle | dfsCycle(i);
        }
    }
    if(isCycle == 1) cout<<"Cycle Detected!"<<endl;
    else cout<<"No Cycle!"<<endl;

    return 0;
}