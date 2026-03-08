#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int,int>>>&adj,int d[],int s)
{
    int n=adj.size();
    for (int i=0;i<n;i++)d[i]=1e9;
    d[s]=0;
    priority_queue<pair<int,int>> q;
    q.push({0,s});
    while (!q.empty())
    {
        auto p=q.top();
        q.pop();
        int l=-p.first,v=p.second;
        if (l!=d[v])continue;
        for (auto f:adj[v])
        {
            int m=f.first,z=f.second;
            if (d[m]>l+z)
            {
                q.push({-l-z,m});
                d[m]=l+z;
            }
        }
    }

}

int main()
{
    vector<vector<pair<int,int>>> adj;
    int n,m;
    cin>>n>>m;
    adj.resize(n);
    for (int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    int d[n];
    dijkstra(adj,d,0);
    cout<<d[2];
}