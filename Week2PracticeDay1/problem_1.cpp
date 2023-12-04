#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
vector<int> ajdList[N];
int visited[N];

//dfs function
void dfs(int par)
{
    visited[par] = 1;
    for(int child: ajdList[par])
    {
        if(visited[child] == 0)
        {
            dfs(child);
        }
    }
    cout<<par<<" ";
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        ajdList[u].push_back(v);
        ajdList[v].push_back(u);
    }

    int src = 1;

    //calling dfs function
    dfs(src);





    // for(int i=0;i<n;i++)
    // {
    //     cout<<"List "<<i<<": ";
    //     for(int v: ajdList[i])
    //     {
    //         cout<<v<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}