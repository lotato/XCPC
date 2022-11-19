#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
ll res[maxn];
queue<pair<int,int>>p[maxn];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>res[i];
        p[i].push({res[i],0});
    }
    int q;
    cin>>q;
    ll bs=0,ts=0;
    for(int i=1;i<=q;i++)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            ll x;
            cin>>x;
            bs=x;
            ts=i;
        }
        if(op==2)
        {
            ll x,id;
            cin>>id>>x;
            res[id]+=x;
            p[id].push({x,i});
        }
        if(op==3)
        {
            ll id;
            cin>>id;
            while(p[id].size()&&p[id].front().second<ts)
            {
                res[id]-=p[id].front().first;
                p[id].pop();
            }
            cout<<bs+res[id]<<'\n';
        }
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