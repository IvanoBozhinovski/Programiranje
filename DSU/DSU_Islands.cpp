#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct DSU
{
    vector<int> dad,sz,rank;
    vector<bool> open;
    int x,y,n;

    DSU(int x,int y)
    {
        this->x=x;
        this->y=y;
        this->n=x*y;
        dad.resize(n+1);
        sz.resize(n+1);
        rank.resize(n+1);
        open.resize(n+1);
        for(int i=0;i<n;i++)
        {
            dad[i]=i;
            sz[i]=1;
            rank[i]=1;
        }
        for(int i=0;i<n;i++)open[i]=false;
        for(int i=0;i<x;i++)open[i]=open[(y-1)*x+i]=true;
        for(int i=0;i<y;i++)open[i*x]=open[(i+1)*x-1]=true;
    }

    int get(int v)
    {
        if(v==dad[v])return v;
        return get(dad[v]); //no path compression
        //return dad[v]=get(dad[v]); //path compression
    }

    bool same(int u,int v)
    {
        return get(u)==get(v);
    }

    bool join(int u,int v)
    {
        return union_by_size(u,v);
        //return union_by_rank(u,v);
    }

    bool union_by_size(int u,int v)
    {
        u=get(u);
        v=get(v);
        if(u==v)return false;
        //if(sz[u]<sz[v])swap(u,v);
        dad[v]=u;
        sz[u]+=sz[v];
        if(open[v]==true)open[u]=true;
        return true;
    }

    bool union_by_rank(int u,int v)
    {
        u=get(u);
        v=get(v);
        if(u==v)return false;
        if(rank[u]<rank[v])swap(u,v);
        dad[v]=u;
        if(rank[u]==rank[v])rank[u]++;
        if(open[v]==true)open[u]=true;
        return true;
    }
};

class Solution
{
public:
    int closedIsland(vector<vector<int>>& grid)
    {
        const int c[4]={0,0,1,-1},d[4]={-1,1,0,0};
        int y=grid.size(),x=grid[0].size();
        DSU dsu(x,y);

        bool visited[x*y];
        memset(visited,false,sizeof(visited));
        queue<int> q;
        for(int j=0;j<y;j++)
        {
            for(int i=0;i<x;i++)
            {
                int pos=j*x+i;
                if(!visited[pos])
                {
                    visited[pos]=true;
                    if(grid[j][i]==0)
                    {
                        q.push(pos);
                        while(!q.empty())
                        {
                            int v=q.front();
                            q.pop();
                            for(int idx=0;idx<4;idx++)
                            {
                                int vi=v%x,vj=v/x,vpos=vj*x+vi;
                                int ni=vi+c[idx],nj=vj+d[idx],npos=nj*x+ni;
                                if(ni<x&&ni>=0&&nj<y&&nj>=0&&grid[nj][ni]==0)
                                {
                                    if(!visited[npos])
                                    {
                                        visited[npos]=true;
                                        dsu.join(v,npos);
                                        q.push(npos);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        memset(visited,false,sizeof(visited));
        int ans=0;
        for(int i=0;i<x*y;i++)
        {
            if(grid[i/x][i%x]==1)continue;
            int p=dsu.get(i);
            if(!visited[p])
            {
                visited[p]=true;
                if(!dsu.open[p])ans++;
            }
        }
        return ans;
    }
};
