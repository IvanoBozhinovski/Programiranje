#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct hash_len
{
    vector<vector<string>> m;
    int n,s,buckets;

    hash_len(int s=200)
    {
        m.resize(s);
        this->s=s;
        this->n=0;
        this->buckets=0;
    }

    void insert(string& s)
    {
        int sz=static_cast<int>(s.size());
        if(m[sz].size()==0)buckets++;
        m[sz].push_back(s);
        n++;
    }

    float loadfactor()
    {
        return static_cast<float>(n)/static_cast<float>(buckets);
    }
};

struct hash_sum
{
    vector<vector<string>> m;
    int n,s,buckets;

    hash_sum(int s=10000)
    {
        m.resize(s);
        this->s=s;
        this->n=0;
        this->buckets=0;
    }

    int getsum(string& s)
    {
        int sum=0;
        for(int i=0;i<s.size();i++)sum+=s[i]-'a';
        return sum;
    }

    void insert(string& s)
    {
        int sum=getsum(s);
        if(m[sum].size()==0)buckets++;
        m[sum].push_back(s);
        n++;
    }

    float loadfactor()
    {
        return static_cast<float>(n)/static_cast<float>(buckets);
    }

};

struct hash_first_letter
{
    vector<vector<string>> m;
    int n,s,buckets;

    hash_first_letter(int s=56)
    {
        m.resize(s);
        this->s=s;
        this->n=0;
        this->buckets=0;
    }

    void insert(string& s)
    {
        int val=tolower(s[0])-'a';
        if(m[val].size()==0)buckets++;
        m[val].push_back(s);
        n++;
    }

    float loadfactor()
    {
        return static_cast<float>(n)/static_cast<float>(buckets);
    }

};

struct hash_two_letters
{
    vector<vector<string>> m;
    int n,s,buckets;

    hash_two_letters(int s=900)
    {
        m.resize(s);
        this->s=s;
        this->n=0;
        this->buckets=0;
    }

    int value(string& s)
    {
        if(s.size()==1)return tolower(s[0])-'a';
        return 26*(tolower(s[0])-'a'+1)+tolower(s[1])-'a';
    }

    void insert(string& s)
    {
        int val=value(s);
        if(m[val].size()==0)buckets++;
        m[val].push_back(s);
        n++;
    }

    float loadfactor()
    {
        return static_cast<float>(n)/static_cast<float>(buckets);
    }

};

int main()
{
    freopen("../Words.txt", "r", stdin);
    vector<string> v;
    string s;
    while(cin>>s)
    {
        v.push_back(s);
    }
    hash_len m1;
    hash_sum m2;
    hash_first_letter m3;
    hash_two_letters m4;
    for(auto& x:v)
    {
        m1.insert(x);
        m2.insert(x);
        m3.insert(x);
        m4.insert(x);
    }
    cout<<"Load factors:"<<endl;
    cout<<"-Length: "<<m1.loadfactor()<<endl;
    cout<<"-Sum: "<<m2.loadfactor()<<endl;
    cout<<"-First letter: "<<m3.loadfactor()<<endl;
    cout<<"-First two letters: "<<m4.loadfactor()<<endl;
}