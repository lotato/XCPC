#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
int val[20000000],lazy[20000000];
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int op,x;
        cin>>op>>x;
        if(op==1)
        {
            lazy[x]++;
        }
        if(op==2)
        {
            lazy[1]++;
            lazy[x]--;
        }
        if(op==3)
        {
            while(x>=1)
            {
                val[x]++;
                x/=2;
            }
        }
        if(op==4)
        {
            lazy[1]++;
            while(x>=1)
            {
                val[x]--;
                x/=2;
            }
        }
    }
    map<int,int>mp;
    for(int i=1;i<=n;i++)
    {
        val[i]+=lazy[i];
        lazy[2*i]+=lazy[i];
        lazy[2*i+1]+=lazy[i];
        mp[val[i]]++;
    }
    for(int i=0;i<=m;i++)
    {
        cout<<mp[i]<<' ';
    }
    cout<<'\n';
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