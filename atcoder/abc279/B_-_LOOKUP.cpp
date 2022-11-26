#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
void solve()
{
    string s,t;
    cin>>s>>t;
    bool flag=0;
    for(int i=0;i<s.size();i++)
    {
        bool f1=1;
        for(int j=0;j<t.size();j++)
        {
            if(i+j>=s.size()||s[i+j]!=t[j])
            {
                f1=0;
                break;
            }
        }
        if(f1)
        {
            flag=1;
            break;
        }
    }
    if(flag)
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
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