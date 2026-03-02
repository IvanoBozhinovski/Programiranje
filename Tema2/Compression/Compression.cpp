#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct CompressionTable
{
    int cnt[256]={0};
    string code[256]={""};
    char id[2000];

    CompressionTable(string s)
    {
        for (unsigned char c:s) cnt[c]++;

        vector<pair<int,char>> v;
        for (int i = 0; i < 256; i++)
        {
            if (cnt[i]) v.push_back({cnt[i], (unsigned char)i});
        }

        sort(v.rbegin(), v.rend());
        string t = "0";
        int num=0;
        for (auto &p : v)
        {
            code[(unsigned char)p.second] = t;
            id[num]=(unsigned char)p.second;
            t = "1" + t;
            num++;
        }
    }

    string compress(string s)
    {
        string ans="";
        for (unsigned char c : s)ans += code[c];
        return ans;
    }

    void decompress(string &s)
    {
        int cnt=0;
        for(auto &c:s)
        {
            if(c=='1')cnt++;
            else
            {
                cout<<id[cnt];
                cnt=0;
            }
        }
    }
};

int main()
{
    freopen("Anna_Karenina.txt","r",stdin);
    freopen("compressed.txt","w",stdout);
    string s,t;
    while (getline(cin,t))s+=t+"\n";
    CompressionTable T(s);
    cout<<T.compress(s);
    freopen("compressed.txt","r",stdin);
    freopen("decompressed.txt","w",stdout);
    cin>>s;
    T.decompress(s);

}
