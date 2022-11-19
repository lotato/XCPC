#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
void solve()
{
    int n,q;
    cin>>n>>q;
    map<int,map<int,int>>mp;
    for(int i=1;i<=q;i++)
    {
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1)
        {
            mp[x][y]=1;
        }
        if(op==2)
        {
            mp[x][y]=0;
        }
        if(op==3)
        {
            if(mp[x][y]==1&&mp[y][x]==1)
            {
                cout<<"Yes\n";
            }
            else
            {
                cout<<"No\n";
            }
        }
    }
    return ;
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