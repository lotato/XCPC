#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
void solve()
{
    ll n,v;
    cin>>n>>v;
    ll ans=0,res=0;
    for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        if((v-res)<x)
        {
            ans++;
            res=x;
        }
        else res+=x;
    }
    cout<<ans+1<<'\n';
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