#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> adjList[N];
bool visited[N];
// dfs function implementation
void dfs(int u)
{
    // 1st actions just after entering node u
    visited[u] = true;
    cout << "Visiting Node: " << u << endl;

    for (int val : adjList[u])
    {
        // 2nd actions before entering new neighbor
        if (visited[val] == true)
            continue;
        dfs(val);
        // 3rd actions after exiting a neighbor
    }

    // 4th actions before exiting node
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

    // calling the dfs funciton
    dfs(1);

    cout<<endl<<"visiting array"<<endl;

    for(int i=1;i<=n;i++)
    {
        cout<<"Visiting array "<<i<<" Status: "<<visited[i]<<endl;
    }
    return 0;
}