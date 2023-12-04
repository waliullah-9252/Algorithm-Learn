#include <bits/stdc++.h>
using namespace std;
const int n = 1e6 + 5;
vector<int> adjList[n];
int visited[n];

// bfs function
void bfs(int parent)
{
    queue<int> q;
    q.push(parent);
    visited[parent] = 1;
    stack<int> st;

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
            }
        }
        st.push(val);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
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

    int src = 1;
    //calling bfs function
    bfs(src);
    return 0;
}