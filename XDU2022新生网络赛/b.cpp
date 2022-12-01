#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
void solve()
{
    int t;
    cin>>t;
    cout<<(t-1)/5<<'\n';
    map<int,int>mp;
    mp[1]=1;
    mp[1]=0;
    cout<<mp.count(1)<<'\n';
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