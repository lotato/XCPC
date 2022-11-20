#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
int a[maxn];
void solve()
{
    int n,p;
    cin>>n>>p;
    map<int,int>mp;
    a[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    int end=a[n]+p-1;
    int cnt=0;
    for(int i=end;i>a[n];i--)
    {
        if(i>=p)
        {
            if(mp[i-p])
            {
                cnt+=1;
            }
            else
            {
                break;
            }
        }
        else
        {
            if(mp[i])
            {
                cnt+=1;
            }
            else
            {
                break;
            }
        }
    }
    a[n-1]+=1;
    for(int i=n-1;i>=0;i--)
    {
        mp[a[i]%p]++;
        if(a[i]>=p)
        {
            a[i-1]++;
        }
    }
    int cnt2=0;
    // cout<<end<<'\n';
    if(end>=p)
    {
        for(int i=end;i>=p;i--)
        {
            if(i>=p)
            {
                if(mp[i-p])
                {
                    cnt2+=1;
                }
                else
                {
                    break;
                }
            }
        }
    }
    cout<<min(p-cnt-1,max(p-a[n],p-cnt2-1))<<'\n';
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