#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define pii pair<int,int>
#define pb push_back

struct Point
{
    float x,y,z;
};

bool comp(Point& a,Point& b)
{
    return a.x<b.x;
}


bool comp2(const Point& a, const Point& b)
{
    if(a.y!=b.y) return a.y<b.y;
    return a.z<b.z;
}

float dist2(Point& a,Point& b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
}

float solve(vector<Point> &v)
{
    int n=v.size();
    if (n<=3)
    {
        float d=1e9;
        for (int i=0;i<n;i++)
        {
            for (int j=i+1;j<n;j++)
            {
                d=min(d, dist2(v[i],v[j]));
            }
        }
        return d;
    }
    vector<Point> v1,v2;
    float l=(v[n/2].x+v[n/2+1].x)/2;
    for (int i=0;i<=n/2;i++)
    {
        v1.pb(v[i]);
    }
    for (int i=n/2+1;i<n;i++)
    {
        v2.pb(v[i]);
    }

    float d=min(solve(v1),solve(v2));

    vector<Point> strip;
    for (auto &p : v)
    {
        if ((p.x-l)*(p.x-l) < d) strip.push_back(p);
    }

    sort(strip.begin(), strip.end(), comp2);
    for (int i=0;i<strip.size();i++)
    {
        for (int j=i+1;j<strip.size();j++)
        {
            if ((strip[j].y - strip[i].y)*(strip[j].y - strip[i].y)>=d) break;
            d=min(d, dist2(strip[i], strip[j]));
        }
    }
    return d;

}


int main()
{
    vector<Point> v={{2,3,5},{1,2, 7}};
    sort(v.begin(),v.end(),comp);
    for (auto x:v) cout<<x.x<<' '<<x.y<<' '<<x.z<<endl;
    cout<<endl;
    cout<<sqrt(solve(v))<<endl;
}