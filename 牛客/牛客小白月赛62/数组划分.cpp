#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
int a[maxn],b[maxn];
void solve()
{
    int n;
    cin>>n;
    vector<int>p;
    map<int,int>mp;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=2;j*j<=a[i];j++)
        {
            if(a[i]%j!=0)
            {
                continue;
            }
            p.push_back(j);
            while(a[i]%j==0)
            {
                a[i]/=j;
            }
        }
        if(a[i]>1)
        {
            p.push_back(a[i]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        for(int j=2;j*j<=b[i];j++)
        {
            if(b[i]%j!=0)
            {
                continue;
            }
            mp[j]++;
            while(b[i]%j==0)
            {
                b[i]/=j;
            }
        }
        if(b[i]>1)
        {
            mp[b[i]]++;
        }
    }
    // for(auto x:mp)
    // {
    //     cout<<x.first<<' ';
    // }
    bool flag=1;
    for(auto x:p)
    {
        if(mp.count(x))
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