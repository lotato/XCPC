#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
int a[maxn];
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
    int n;
    cin>>n;
    map<int,int>mp;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    ll ans=1,mul=1;
    for(int i=1;i<=n;i++)
    {
        ans=ans*i%mod;
        mul=mul*i%mod;
    }
    ans=ans*getInv(2,mod)%mod;
    ans=ans*n%mod*(n-1)%mod*getInv(2,mod)%mod;
    // cout<<ans<<'\n';
    for(auto x:mp)
    {
        ll cnt=x.second;
        ans=(ans-mul*cnt%mod*(cnt-1+mod)%mod*getInv(2,mod)%mod*getInv(2,mod)%mod+mod)%mod;
    }
    cout<<ans%mod<<'\n';
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