#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> adjList[N];
bool visited[N];
int cc = 0;

void dfs(int parent)
{
    visited[parent] = true;
    cc++;
    for (int child : adjList[parent])
    {
        if (visited[child])
            continue;
        dfs(child);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        if (visited[i])
            continue;
        dfs(i);
        if(cc>1)
        v.push_back(cc);
        cc=0;
    }

    sort(v.begin(),v.end());
    for(int s: v)
    {
        cout<<s<<" ";
    }

    return 0;
}