#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> adjList[N];
int visited[N];
int level[N];
int parentG[N];

void bfs(int parent)
{
    queue<int> q;
    q.push(parent);
    visited[parent] = 1;
    parentG[parent] = -1;
    while (!q.empty())
    {
        int val = q.front();
        q.pop();

        for (int child : adjList[val])
        {
            if (visited[child] == 0)
            {
                q.push(child);
                visited[child] = 1;
                level[child] = level[val] + 1;
                parentG[child] = val;
            }
        }
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

    int s, d;
    cin >> s >> d;

    bfs(s);

    cout<<endl;

    cout <<"Distance: "<< level[d] << endl;

    // for(int i=1;i<=n;i++)
    // {
    //     cout<<"Parent of"<<i<<" : "<<parentG[i]<<endl;
    // }

    vector<int> path;
    int current = d;
    while(current != -1)
    {
        path.push_back(current);
        current = parentG[current];
    }

    reverse(path.begin(),path.end());

    cout<<"Path: ";
    for(int p: path)
    {
        cout<<p<<" ";
    }


    return 0;
}