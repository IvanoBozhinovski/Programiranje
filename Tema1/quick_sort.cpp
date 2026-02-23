#include <iostream>
#include <chrono>
#include <random>

using namespace std;

int part(int* a, int l, int r)
{
    //int p=a[l];

    int p=a[(l+r)/2];  ///druga implementacija

    int i=l-1,j=r+1;
    while(true)
    {
        do
        {
            i++;
        }
        while(a[i]<p);
        do
        {
            j--;
        }
        while(a[j]>p);
        if(i>=j)return j;
        swap(a[i],a[j]);
    }
}

void quick_sort(int* a,int l,int r)
{
    if(l>=r)return;
    int p=part(a,l,r);
    quick_sort(a,l,p);
    quick_sort(a,p+1,r);
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

    quick_sort(a,0,n-1);

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
    for(int i=0;i<n;i++)b[i]=i;
    t1=chrono::steady_clock::now();
    quick_sort(b,0,n-1);
    t2=chrono::steady_clock::now();
    t=chrono::duration_cast<chrono::milliseconds>(t2-t1).count();
    cout<<"Potrebni bea "<<t<<" milisekundi."<<endl;*/

    return 0;
}
