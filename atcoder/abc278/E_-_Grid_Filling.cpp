#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
int a[310][310],ans[310][310];
void solve()
{
    int H,W,N,h,w;
    cin>>H>>W>>N>>h>>w;
    map<int,int>mp;
    int tot=0;
    for(int i=1;i<=H;i++)
    {
        for(int j=1;j<=W;j++)
        {
            cin>>a[i][j];
            mp[a[i][j]]++;
            if(mp[a[i][j]]==1)
            {
                tot++;
            }
        }
    }
    // cout<<tot<<'\n';
    for(int i=1;i+h-1<=H;i++)
    {
        for(int j=1;j<=w;j++)
        {
            for(int k=0;k<h;k++)
            {
                mp[a[i+k][j]]--;
                if(mp[a[i+k][j]]==0)
                {
                    tot--;
                }
            }
        }
        ans[i][1]=tot;
        for(int j=2;j+w-1<=W;j++)
        {
            for(int k=0;k<h;k++)
            {
                mp[a[i+k][j-1]]++;
                if(mp[a[i+k][j-1]]==1)
                {
                    tot++;
                }
            }
            for(int k=0;k<h;k++)
            {
                mp[a[i+k][j+w-1]]--;
                if(mp[a[i+k][j+w-1]]==0)
                {
                    tot--;
                }
            }
            ans[i][j]=tot;
        }
        for(int j=W-w+1;j<=W;j++)
        {
            for(int k=0;k<h;k++)
            {
                mp[a[i+k][j]]++;
                if(mp[a[i+k][j]]==1)
                {
                    tot++;
                }
            }
        }
    }
    for(int i=1;i+h-1<=H;i++)
    {
        for(int j=1;j+w-1<=W;j++)
        {
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
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