#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll mod=1e9+7;
int a[maxn];
void solve()
{
    ll n,m;
    cin>>n>>m;
    ll bs=m,c=1;;
    ll ans=0;
    while(bs<=n)
    {
        ll cnt=n/bs;
        ans+=cnt;
        bs*=m,c++;
    }
    cout<<ans<<'\n';
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