#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
ll a[maxn];
void solve()
{
    ll n;
    cin>>n;
    if(n%2==0)
    {
        for(int i=1;i<=n/2;i++)
        {
            cout<<n-n/2+(i-1)<<' ';
        }
        for(int i=1;i<=n/2;i++)
        {
            cout<<n+n/2-(i-1)<<' ';
        }
        cout<<'\n';
    }
    else
    {
        ll bs=4*n;
        cout<<bs-n<<' ';
        for(int i=1;i<=n-2;i++)
        {
            cout<<bs-(n/2-i)*2<<' ';
        }
        cout<<bs+n<<'\n';
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