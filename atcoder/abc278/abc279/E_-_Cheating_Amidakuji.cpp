#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
int a[maxn],b[maxn];
void solve()
{
    int n,m;
    cin>>n>>m;
    map<int,int>posn;
    for(int i=1;i<=n;i++)
    {
        b[i]=i;
        posn[b[i]]=i;
    }

    //求出终点
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
        posn[b[a[i]]]=a[i]+1;
        posn[b[a[i]+1]]=a[i];
        swap(b[a[i]],b[a[i]+1]);
        // for(int i=1;i<=n;i++)
        // {
        //     cout<<b[i]<<' ';
        // }
        // cout<<'\n';
    }

    map<int,int>pos;
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<posn[i]<<' ';
    // }
    // cout<<'\n';
    for(int i=1;i<=n;i++)
    {
        b[i]=i;
        pos[b[i]]=i;
    }
    for(int i=1;i<=m;i++)
    {
        if(b[a[i]]==1)
        {
            cout<<posn[b[a[i]+1]]<<'\n';
        }
        else if(b[a[i]+1]==1)
        {
            cout<<posn[b[a[i]]]<<'\n';
        }
        else
        {
            cout<<posn[1]<<'\n';
        }
        swap(b[a[i]],b[a[i]+1]);
    }
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