#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
int a[110][110];
vector<int>e[110];
set<int>s[110];
int d[110];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        s[i].clear();
        e[i].clear();
        d[i]=0;
        string s;
        cin>>s;
        s='$'+s;
        for(int j=1;j<=n;j++)
        {
            if(s[j]=='1')
            {
                // cout<<i<<' '<<j<<'\n';
                e[i].push_back(j);
                d[j]++;
            }
        }
    }
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        s[i].insert(i);
        if(d[i]==0)
        {
            // cout<<i<<'\n';
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:e[u])
        {
            // cout<<u<<' '<<v<<'\n';
            for(auto x:s[u])
            {
                s[v].insert(x);
            }
            d[v]--;
            if(d[v]==0)
            {
                q.push(v);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<s[i].size()<<' ';
        for(auto x:s[i])
        {
            cout<<x<<' ';
        }
        cout<<'\n';
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