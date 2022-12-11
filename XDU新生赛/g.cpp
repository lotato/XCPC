#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 5010;
const ll mod = 1e9 + 7;
int a[maxn];
int v[maxn][maxn];
int sum[maxn][2];
int dp[maxn][maxn];
int mp[200];
void solve()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    s = '$' + s;
    int len1 = n / k, len2 = n / k + (n % k > 0);
    for(int len=1;len<=n;len++)
    {
        int res=0;
        for(int i=1;i<=len;i++)
        {
            if(mp[s[i]]==0)
            {
                res++;
            }
            mp[s[i]]++;
        }
        v[1][len]=res;
        for(int st=2;st+len-1<=n;st++)
        {
            mp[s[st-1]]--;
            if(mp[s[st-1]]==0)
            {
                res--;
            }
            if(mp[s[st+len-1]]==0)
            {
                res++;
            }
            mp[s[st+len-1]]++;
            v[st][st+len-1]=res;
        }
        for(int i=n-len+1;i<=n;i++)
        {
            mp[s[i]]--;
        }
    }
    // for(int l=1;l<=n;l++)
    // {
    //     for(int r=1;r<=n;r++)
    //     {
    //         cout<<v[l][r]<<' ';
    //     }
    //     cout<<'\n';
    // }
    for(int l=1;l<=n;l++)
    {
        for(int r=l;r<=n;r++)
        {
            v[l][r]+=v[l][r-1];
        }
    }
    for(int r=1;r<=n;r++)
    {
        for(int l=r;l>=1;l--)
        {
            v[l][r]+=v[l+1][r];
        }
    }
    // for(int l=1;l<=n;l++)
    // {
    //     for(int r=1;r<=n;r++)
    //     {
    //         cout<<v[l][r]<<' ';
    //     }
    //     cout<<'\n';
    // }
    int cnt=n%k;
    for(int i=1;i<=k;i++)
    {
        dp[i][0]=dp[i-1][0]+v[i*len1-len1+1][i*len1];
        for(int j=1;j<=min(i,cnt);j++)
        {
            dp[i][j]=max(dp[i-1][j]+v[(i-j)*len1+j*len2-len1+1][(i-j)*len1+j*len2],
                        dp[i-1][j-1]+v[(i-j)*len1+j*len2-len2+1][(i-j)*len1+j*len2]);
        }
    }
    cout<<dp[k][cnt]<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    int t = 1;
    // cin>>t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}