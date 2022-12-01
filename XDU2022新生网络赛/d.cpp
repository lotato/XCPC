#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=2000010;
const ll mod=1e9+7;
int a[maxn];
int vis[maxn];
int dis[maxn];
void solve()
{
    int n,m;
    // n=1000000,m=1000000;
    cin>>n>>m;
    for(int i=1;i<=n+m;i++)
    {
        a[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n+m;i++)
    {
        dis[i]=2e9;
    }
    deque<int>q;
    q.push_front(0);
    dis[0]=0;
    int mi=1e9,mx=0;
    // while(!q.empty())
    // {
    //     int u=q.front();
    //     // cout<<u<<' '<<dis[u]<<' '<<a[u]<<'\n';
    //     q.pop_front();
    //     if(vis[u])
    //     {
    //         continue;
    //     }
    //     vis[u]=1;
    //     if(u>=n)
    //     {
    //         mi=min(mi,dis[u]);
    //         continue;
    //     }
    //     if(a[u]>0)
    //     {
    //         dis[u+a[u]]=min(dis[u],dis[u+a[u]]);
    //         q.push_front(u+a[u]);
    //     }
    //     else
    //     {
    //         for(int i=1;i<=m;i++)
    //         {
    //             dis[u+i]=min(dis[u+i],dis[u]+1);
    //             q.push_back(u+i);
    //         }
    //     }
    // }
    for(int i=1;i<=n+m;i++)
    {
        dis[i]=-1;
    }
    dis[0]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>>q1;
    for(int i=0;i<=n+m;i++)
    {
        while(!q1.empty()&&q1.top().second<i)
        {
            q1.pop();
        }
        if(!q1.empty())
        {
            dis[i]=max(dis[i],q1.top().first);
        }
        if(dis[i]==-1)
        {
            continue;
        }
        if(i>=n)
        {
            mx=max(mx,dis[i]);
            continue;
        }
        if(a[i]==0)
        {
            q1.push({dis[i]+1,i+m});
        }
        else
        {
            dis[i+a[i]]=max(dis[i+a[i]],dis[i]);
        }
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q2;
    for(int i=1;i<=n+m;i++)
    {
        dis[i]=2e9;
    }
    for(int i=0;i<=n+m;i++)
    {
        while(!q2.empty()&&q2.top().second<i)
        {
            q2.pop();
        }
        if(!q2.empty())
        {
            dis[i]=min(dis[i],q2.top().first);
        }
        if(dis[i]==2e9)
        {
            continue;
        }
        if(i>=n)
        {
            mi=min(mi,dis[i]);
            continue;
        }
        if(a[i]==0)
        {
            q2.push({dis[i]+1,i+m});
        }
        else
        {
            dis[i+a[i]]=min(dis[i+a[i]],dis[i]);
        }
    }
    cout<<mx<<' '<<mi<<'\n';
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