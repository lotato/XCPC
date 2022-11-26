#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
ll sum[maxn];
ll a[maxn],c[maxn];
ll cnt[2][2];
int prea[maxn],prec[maxn];
void solve()
{
    string s;
    cin>>s;
    ll n=s.size();
    s='$'+s;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]=='a')
        {
            a[i]=a[i-1]+1;
            c[i]=c[i-1];
            sum[i]=sum[i-1];
        }
        else if(s[i]=='c')
        {
            a[i]=a[i-1];
            c[i]=c[i-1]+1;
            sum[i]=sum[i-1]+a[i];
        }
        else
        {
            a[i]=a[i-1];
            c[i]=c[i-1];
            sum[i]=sum[i-1];
        }
        cnt[c[i]%2][sum[i]%2]++;
    }
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<a[i]<<' '<<c[i]<<' '<<sum[i]<<'\n';
    // }
    // cout<<'\n';
    ll ans=cnt[0][0]+cnt[1][0];
    for(int i=1;i<s.size();i++)
    {
        cnt[c[i]%2][sum[i]%2]--;
        for(int j=0;j<(1<<2);j++)
        {
            int x=(j>>0)&1,y=(j>>1)&1;
            int res=(x-sum[i]%2)-(a[i]%2)*(y-c[i]%2);
            if(res%2==0)
            {
                ans+=cnt[y][x];
                // cout<<y<<' '<<x<<' '<<cnt[y][x]<<'\n';
                // cout<<x-sum[i]%2<<' '<<a[i]%2<<' '<<y-c[i]%2<<'\n';
            }
        }
        // cout<<ans<<'\n';
    }
    // cout<<ans<<'\n';
    int pre=0;
    ll tmp=0;
    // cout<<tmp<<'\n';
    for(int i=1;i<s.size();i++)
    {
        prea[i]=prea[i-1];
        prec[i]=prec[i-1];
        if(s[i]=='a')
        {
            prea[i]=i;
        }
        if(s[i]=='c')
        {
            prec[i]=i;
        }
        tmp+=(i-prea[prec[i]]);
        // cout<<(i-prea[prec[i]])<<'\n';
    }
    // cout<<tmp<<'\n';
    ans-=tmp;
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