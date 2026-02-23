#include <iostream>
#include <chrono>
#include <random>

using namespace std;

void mrg(int* a,int l,int mid,int r)
{
    int b[mid-l+1],c[r-mid];
    for(int i=l;i<=mid;i++)b[i-l]=a[i];
    for(int i=mid+1;i<=r;i++)c[i-mid-1]=a[i];
    int x=0,y=0,idx=l;
    while(x<=mid-l&&y<r-mid)
    {
        if(b[x]<=c[y])
        {
            a[idx]=b[x];
            x++;
        }
        else
        {
            a[idx]=c[y];
            y++;
        }
        idx++;
    }
    while(x<=mid-l)a[idx++]=b[x++];
    while(y<r-mid)a[idx++]=c[y++];
    return;
}

void merge_sort(int* a,int l,int r)
{
    if(l>=r)return;
    if(r-l==1)
    {
        if(a[r]<a[l])swap(a[r],a[l]);
        return;
    }
    int mid=(l+r)/2;
    merge_sort(a,l,mid);
    merge_sort(a,mid+1,r);
    mrg(a,l,mid,r);
    return;
}

int main()
{
    int n=1e5;
    int a[n];

    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> dist(0,1e9);
    for(int i=0;i<n;i++)
    {
        a[i]=dist(rng);
    }

    auto t1=chrono::steady_clock::now();

    merge_sort(a,0,n-1);

    auto t2=chrono::steady_clock::now();

    int t=chrono::duration_cast<chrono::milliseconds>(t2-t1).count();
    cout<<"Potrebni bea "<<t<<" milisekundi."<<endl;

    for(int i=1;i<n;i++)
    {
        if(a[i]<a[i-1])
        {
            cout<<"GRESHKA"<<endl;
            break;
        }
    }
    cout<<"PODREDENO"<<endl;

    /*int b[n];
    for(int i=0;i<n;i++)b[i]=n-i;
    t1=chrono::steady_clock::now();
    merge_sort(b,0,n-1);
    t2=chrono::steady_clock::now();
    t=chrono::duration_cast<chrono::milliseconds>(t2-t1).count();
    cout<<"Potrebni bea "<<t<<" milisekundi."<<endl;*/

    return 0;
}
