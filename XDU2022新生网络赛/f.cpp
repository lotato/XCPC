#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
int x[30],y[30];
int n,V,q;
int w[1010],v[1010];
int cost[10010];
int c[1010];
void dfs(int cnt,int resw,int resv)
{
    if(cnt==q)
    {
        for(int i=1;i<=q;i++)
        {
            if(c[x[i]]&&c[y[i]])
            {
                return;
            }
        }
        if(resw<=V)
        {
            cost[resw]=max(cost[resw],resv);
        }
        return;
    }   
    dfs(cnt+1,resw,resv);
    if(!c[x[cnt+1]])
    {
        c[x[cnt+1]]=1;
        dfs(cnt+1,resw+w[x[cnt+1]],resv+v[x[cnt+1]]);
        c[x[cnt+1]]=0;
    }
    if(!c[y[cnt+1]])
    {
        c[y[cnt+1]]=1;
        dfs(cnt+1,resw+w[y[cnt+1]],resv+v[y[cnt+1]]);
        c[y[cnt+1]]=0;
    }
}
int vis[1010];
int dp[10010];
void solve()
{
    cin>>n>>V>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>x[i]>>y[i];
        vis[x[i]]=vis[y[i]]=1;
    }   
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
    }
    dfs(0,0,0);
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        for(int j=V;j-w[i]>=0;j--)
        {
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    for(int i=1;i<=V;i++)
    {
        cost[i]=max(cost[i],cost[i-1]);
        dp[i]=max(dp[i],dp[i-1]);
    }
    // for(int i=0;i<=V;i++)
    // {
    //     for(int j=V;j-i>=0;j--)
    //     {
    //         dp[j]=max(dp[j],dp[j-i]+cost[i]);
    //     }
    // }
    int ans=0;
    for(int i=0;i<=V;i++)
    {
        ans=max(ans,dp[i]+cost[V-i]);
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