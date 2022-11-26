#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
void solve()
{
    ll l,r;
    cin>>l>>r;
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        ll x;
        cin>>x;
        ll ri=(r-l+1)*(r+l)/2;
        ri%=x;
        if(ri%x==0)
        {
            cout<<0<<'\n';
        }
        else
        {
            cout<<1<<'\n';
        }
    }
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