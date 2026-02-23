#include <algorithm>
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
            sz[i]=i;
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
        sz[u]+=sz[v];
    }
};
class Solution
{
public:
    bool gcdSort(vector<int>& nums)
    {
        int n=nums.size();
        bool b[int(1e5)+1];
        vector<int> p;
        for(int i=0;i<=1e5;i++)b[i]=true;
        for(long long i=2;i<1e5;i++)
        {
            if(b[i])
            {
                p.push_back(i);
                for(long long j=i*i;j<=1e5;j+=i)
                {
                    b[j]=false;
                }
            }
        }
        DSU dsu(1e5+1);
        for(auto x:nums)
        {
            int y=x;
            for(int i=2;i*i<=x;i++)
            {
                if(x%i==0)
                {
                    dsu.join(y,i);
                    while(x%i==0)x/=i;
                }
            }
            if(x>1)dsu.join(y,x);
        }
        vector<int> v=nums;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            if(!dsu.same(v[i],nums[i]))return false;
        }
        return true;
    }
};
