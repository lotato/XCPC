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
    string bs="5";
    bool flag=1;
    if(t[0]!='5')
    {
        flag=0;
    }
    for(int i=1;i<t.size();i++)
    {
        if(t[i]!='0')
        {
            flag=0;
        }
    }
    if(flag)
    {
        if(s.back()=='0'||s.back()=='2'||s.back()=='4'||s.back()=='6'||s.back()=='8')
        {
            cout<<"Happy birthday to YXGG\n";
            return;
        }
        else
        {
            cout<<"Happy birthday to MFGG\n";
            return;  
        }
    }
    if(t=="0")
    {
        cout<<"PLMM\n";
        return;
    }
    if(t>bs)
    {
        cout<<"Happy birthday to MFGG\n";
        return;
    }
    if(t<bs)
    {
        cout<<"Happy birthday to YXGG\n";
        return;
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