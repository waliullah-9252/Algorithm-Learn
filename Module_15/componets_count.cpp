#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> adjList[N];
bool visited[N];
vector<int> com;

void dfs(int source)
{
    visited[source] = true;
    com.push_back(source);
    for (int child : adjList[source])
    {
        if (!visited[child])
        {
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cnt++;
            dfs(i);
            cout<<"Componets "<<i<<" value : ";
            for(int val: com)
            {
                cout<<val<<" ";
            }
            cout<<endl;
            com.clear();
        }
    }
    cout<<"Total Components : "<<cnt;
    return 0;
}