#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
void solve()
{
    int h,w;
    cin>>h>>w;
    vector<vector<int>>a,b;
    a.resize(h+1);
    b.resize(h+1);
    for(int i=1;i<=h;i++)
    {
        a[i].resize(w+1);
        b[i].resize(w+1);
    }
    for(int i=1;i<=h;i++)
    {
        string s;
        cin>>s;
        s='$'+s;
        for(int j=1;j<=w;j++)
        {
            a[i][j]=s[j];
        }
    }
    for(int i=1;i<=h;i++)
    {
        string s;
        cin>>s;
        s='$'+s;
        for(int j=1;j<=w;j++)
        {
            b[i][j]=s[j];
        }
    }
    map<string,int>mp1,mp2;
    for(int i=1;i<=w;i++)
    {
        string t;
        for(int j=1;j<=h;j++)
        {
            t.push_back(a[j][i]);
        }
        mp1[t]++;
    }
    for(int i=1;i<=w;i++)
    {
        string t;
        for(int j=1;j<=h;j++)
        {
            t.push_back(b[j][i]);
        }
        mp2[t]++;
    }
    bool flag=1;
    for(auto x:mp1)
    {
        if(mp2[x.first]!=x.second)
        {
            flag=0;
        }
    }
    if(flag)
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t=1;
    // cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
    return 0;
}