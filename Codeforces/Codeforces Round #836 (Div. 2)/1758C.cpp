#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
int ans[maxn];
set<int>q[maxn];
void solve()
{
    int n,x;
    cin>>n>>x;
    ans[1]=x;
    ans[n]=1;
    for(int i=2;i<n;i++)
    {
        if(i==x)
        {
            continue;
        }
        ans[i]=i;
    }
    if(x==n)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
        return ;
    }
    ans[x]=-1;
    bool flag=0;
    for(int i=x+1;i<=n-1;i++)
    {
        if(i%x==0)
        {
            if(n%i==0)
            {
                ans[x]=i;
                ans[i]=n;
                x=i;
                flag=1;
            }
        }
    }
    if(!flag)
    {
        if(n%x==0)
        {
            ans[x]=n;
            flag=1;
        }
    }
    if(!flag)
    {
        cout<<-1<<'\n';
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<' ';
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