#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
int a[maxn];
void solve()
{
    int n;
    cin>>n;
    map<int,int>mp;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]]=i;
    }
    vector<pair<int,int>>ans;
    for(int i=1;i<=n;i++)
    {
        int pos=mp[i];
        if(pos==i) continue;
        ans.push_back({pos,i});
        mp[a[i]]=pos;
        mp[i]=i;
        swap(a[pos],a[i]);
    }
    cout<<3*ans.size()<<'\n';
    for(auto x:ans)
    {
        int a=x.first,b=x.second;
        cout<<1<<' '<<a<<' '<<b<<'\n';
        cout<<3<<' '<<b<<' '<<a<<'\n';
        cout<<2<<' '<<a<<' '<<b<<'\n';
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