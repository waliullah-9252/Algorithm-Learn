#include <bits/stdc++.h>
using namespace std;
int main()
{
    int e;
    cin >> e;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        pq.push({a, b});
    }

    while (!pq.empty())
    {
        pair<int, int> ass = pq.top();
        pq.pop();
        cout << ass.first << " " << ass.second << endl;
    }
    return 0;
}