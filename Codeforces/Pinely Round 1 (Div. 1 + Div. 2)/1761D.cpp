#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll mod=1e9+7;
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
ll fac[1000010];
ll inv[1000010];
void Init()
{
    fac[0]=1;
    for(int i=1;i<=1000000;i++)
    {
        fac[i]=fac[i-1]*i%mod;
    }
    inv[1000000]=getInv(fac[1000000],mod);
    for(int i=999999;i>=0;i--)
    {
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}
ll C(ll n,ll m)
{
    if(n<m) return 0;
    if(n==m||m==0) return 1;
    else
    {
        return fac[n]*inv[m]%mod*inv[n-m]%mod;
    }
}
void solve()
{
    Init();
    int n,k;
    cin>>n>>k;
    ll ans=0;
    for(int i=0;i<=n;i++)
    {
        ans=(ans+qkpow(3,n-i,mod)%mod*C(k-1,(i+1)/2-1)%mod*C(n-k,i/2)%mod)%mod;
        // cout<<i<<' '<<qkpow(3,n-i,mod)<<' '<<C(k-1,(i+1)/2-1)<<' '<<C(n-k,i/2)<<'\n';
    }
    cout<<ans<<'\n';
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