#include <iostream>
#include <chrono>
#include <random>

using namespace std;

void insertion_sort(int* a,int n)
{
    for(int i=1;i<n;i++)
    {
        int x=a[i],j;
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>x)a[j+1]=a[j];
            else break;
        }
        a[j+1]=x;
    }
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

    insertion_sort(a,n);

    auto t2=chrono::steady_clock::now();

    double t=chrono::duration_cast<chrono::milliseconds>(t2-t1).count();
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
    insertion_sort(b,n);
    t2=chrono::steady_clock::now();
    t=chrono::duration_cast<chrono::milliseconds>(t2-t1).count();
    cout<<"Potrebni bea "<<t<<" milisekundi."<<endl;*/

    return 0;
}
