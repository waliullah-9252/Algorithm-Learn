#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
vector<int> adjList[N];
int visited[N];

//dfs function
void dfs(int par)
{
    visited[par] = 1;
    for(int child: adjList[par])
    {
        if(visited[child] == 0)
        {
            dfs(child);
        }
    }
}

//bfs function
void bfs(int parent)
{
    queue<int> q;
    q.push(parent);
    visited[parent] = 1;

    while (!q.empty())
    {
        int val = q.front();
        q.pop();

        for(int child: adjList[val])
        {
            if(visited[child] == 0)
            {
                q.push(child);
                visited[child] = 1;
            }
        }
        cout<<"List Of Nodes: "<<val<<endl;
    }
    
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int cc = 0;

    for(int i=1;i<=n;i++)
    {
        if(visited[i] == 0)
        {
            bfs(i);
            cc++;
        }
    }

    cout<<"Number of connected components: "<<cc<<endl;


    return 0;
}