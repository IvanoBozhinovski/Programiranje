#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const int INF=1e9;
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    int u,v,w;
    vector<vector<int>> d(n,vector<int>(n,INF));
    for(int i=0;i<n;i++)d[i][i]=0;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        d[u][v]=d[v][u]=w;
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(d[i][k]<INF&&d[k][j]<INF)
                {
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }
    }

    //Finding negative cycles
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            for (int t=0;t<n;t++)
            {
                if(d[i][t]<INF&&d[t][t]<0&&d[t][j]<INF)
                    d[i][j] = - INF;
            }
        }
    }

}