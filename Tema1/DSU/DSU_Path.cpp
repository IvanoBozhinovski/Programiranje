#include <iostream>
#include <vector>
using namespace std;

struct DSU
{
    vector<int> dad,sz;
    int n;

    DSU(int n=1)
    {
        this->n=n;
        dad.resize(n);
        sz.resize(n);
        for(int i=0;i<n;i++)
        {
            dad[i]=i;
            sz[i]=1;
        }
    }

    int get(int v)
    {
        if(v==dad[v])return v;
        return dad[v]=get(dad[v]);
    }

    bool same(int u,int v)
    {
        return get(u)==get(v);
    }

    void join(int u,int v)
    {
        u=get(u);
        v=get(v);
        if(u==v)return;
        if(sz[u]<sz[v])swap(u,v);
        dad[v]=u;
        if(sz[u]==sz[v])sz[u]++;
    }
};

class Solution
{
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        DSU dsu(n);
        for(auto p:edges)
        {
            dsu.join(p[0],p[1]);
        }
        return dsu.same(source,destination);
    }
};