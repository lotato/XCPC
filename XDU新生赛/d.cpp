#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll mod=1e9+7;
int a[maxn];
void solve()
{
    string s;
    cin>>s;
    ll id=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='3'&&s[i]!='4') continue;
        id*=2;
        if(s[i]=='4') id++;
        s[i]='3';
    }
    // cout<<id<<'\n';
    if(id==0)
    {
        cout<<s<<'\n';
        return;
    }
    string t;
    while(id>0)
    {
        if(id%26==0) t.push_back('Z');
        else t.push_back((id%26)-1+'A');
        id--;
        id/=26;
    }
    reverse(t.begin(),t.end());
    cout<<s+t<<'\n';
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