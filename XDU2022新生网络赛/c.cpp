#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
int xx[4]={-1,1,0,0};
int yy[4]={0,0,-1,1};
void solve()
{
    map<pair<int,int>,int>mp;
    int n,t;
    cin>>n>>t;
    deque<pair<int,int>>q;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        mp[{x,y}]=1;
        q.push_back({x,y});
    }
    for(int i=1;i<=t;i++)
    {
        int op;
        cin>>op;
        mp[q.back()]--;
        int x=q.front().first,y=q.front().second;
        if(mp[{x+xx[op],y+yy[op]}])
        {
            cout<<i-1<<'\n';
            return;
        }
        mp[{x+xx[op],y+yy[op]}]++;
        q.push_front({x+xx[op],y+yy[op]});
        q.pop_back();
    }
    cout<<t<<'\n';
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