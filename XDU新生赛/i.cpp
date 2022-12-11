#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=100010;
const int mod=1e9+7;
const int m=1e9+6;
ll a[maxn];
ll qkpow(ll a,ll p,ll mod)
{
    ll t=1,tt=a%mod;
    while(p)
    {
        if(p&1)t=t*tt%mod;
        tt=tt*tt%mod;
        p>>=1;
    }
    return t;
}
ll getInv(ll a,ll mod)
{
    return qkpow(a,mod-2,mod);
}

void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
    }
    ll bs=1;
    bool flag=0;
    for(int i=1;i<=k;i++)
    {
        if(!flag&&a[i]%2==1)
        {
            bs=bs*((a[i]+1)/2)%m;
            flag=1;
        }
        else
        {
            bs=bs*(a[i]+1)%m;
        }
    }
    cout<<qkpow(n,bs+m,mod)%mod<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
    return 0;
}