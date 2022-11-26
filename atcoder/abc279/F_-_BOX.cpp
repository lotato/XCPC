#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=600010;
const ll mod=1e9+7;
int fa[maxn];
int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int box[maxn];
void solve()
{
    int n,q;
    cin>>n>>q;
    map<int,int>mp,id;
    for(int i=1;i<=n+q;i++)
    {
        fa[i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        mp[i]=i;
        id[i]=i;
        box[i]=i;
    }
    int res=n,k=n;
    for(int i=1;i<=q;i++)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x,y;
            cin>>x>>y;
            int fax=find(mp[x]),fay=find(mp[y]);
            fa[fay]=fax;
            mp[y]=++res;
            id[res]=y;
        }
        if(op==2)
        {
            int x;
            cin>>x;
            box[++k]=mp[x];
        }
        if(op==3)
        {
            int x;
            cin>>x;
            cout<<id[find(box[x])]<<'\n';
        }
        // for(int i=1;i<=k;i++)
        // {
        //     cout<<id[box[i]]<<' ';
        // }
        // cout<<'\n';
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