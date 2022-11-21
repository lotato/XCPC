#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
int b[maxn];
void solve()
{
    int n;
    cin>>n;
    map<int,int>mp;
    for(int i=1;i<=n/2;i++)
    {
        cin>>b[i];
        mp[b[i]]=i;
    }
    int cnt=0;
    for(int i=n;i>=1;i--)
    {
        if(mp.count(i))
        {
            cnt++;
        }
        if(!mp.count(i))
        {
            if(cnt==0)
            {
                cout<<-1<<'\n';
                return;
            }
            else
            {
                cnt--;
            }
        }
    }
    vector<int>ans;
    ans.resize(n+1);
    priority_queue<int,vector<int>,less<int>>q;
    priority_queue<int,vector<int>,less<int>>p;
    for(int i=n;i>=1;i--)
    {
        if(mp.count(i))
        {
            while(p.size())
            {
                int idx=q.top();
                q.pop();
                ans[2*idx]=b[idx];
                ans[2*idx-1]=p.top();
                p.pop();
            }
            q.push(mp[i]);
        }
        else
        {
            p.push(i);
        }
    }
    while(p.size())
    {
        int idx=q.top();
        q.pop();
        ans[2*idx]=b[idx];
        ans[2*idx-1]=p.top();
        p.pop();
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