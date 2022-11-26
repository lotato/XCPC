#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
ll h[maxn];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
    }
    ll a,k,b;
    cin>>a>>k>>b;
    ll m;
    cin>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(h[i]>k)
            {
                h[i]=b;
            }
            h[i]+=a;
        }
        if(h[i]>k)
        {
            h[i]=b;
        }
        cout<<h[i]<<' ';
    }
    cout<<'\n';
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