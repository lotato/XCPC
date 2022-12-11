#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=998244353;
int n=5;
struct matrix{
    long long x[6][6];   
    inline void clear(){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                x[i][j]=0;
            }
        }
    }
}a,one;
inline matrix mul(matrix a,matrix b){
    matrix c;
    c.clear();
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            for (int k=1;k<=n;k++){
                c.x[i][j]=(c.x[i][j]%mod+a.x[i][k]%mod*b.x[k][j]%mod)%mod;
            }
        }
    }
    return c;
}
inline matrix fast_pow(matrix a,long long b){
    matrix t=one;
    while (b){
        if (b&1) t=mul(t,a);
        a=mul(a,a);b/=2;
    }
    return t;
}
inline void init_one(){
    for (int i=1;i<=n;i++){
        one.x[i][i]=1;
    }
    a.x[1][1]=0,a.x[1][2]=1,a.x[1][3]=0,a.x[1][4]=0,a.x[1][5]=0;
    a.x[2][1]=1,a.x[2][2]=1,a.x[2][3]=0,a.x[2][4]=0,a.x[2][5]=0;
    a.x[3][1]=0,a.x[3][2]=0,a.x[3][3]=0,a.x[3][4]=1,a.x[3][5]=0;
    a.x[4][1]=1,a.x[4][2]=2,a.x[4][3]=1,a.x[4][4]=1,a.x[4][5]=0;
    a.x[5][1]=1,a.x[5][2]=2,a.x[5][3]=1,a.x[5][4]=1,a.x[5][5]=1;
}
ll val[6]={0,1,2,1,4,5};
void solve()
{
    ll x;
    cin>>x;
    init_one();
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         cout<<a.x[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    a=fast_pow(a,x-1);
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         cout<<a.x[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    ll ans=0;
    // for(int i=1;i<=n;i++)
    // {
    //     ll sum=0;
    //     for(int j=1;j<=n;j++)
    //     {
    //         sum=(sum+a.x[i][j]*val[j]%mod)%mod;
    //     }
    //     cout<<sum<<'\n';
    // }
    // cout<<'\n';
    for(int i=1;i<=n;i++)
    {
        // cout<<a.x[5][i]<<' '<<val[i]<<'\n';
        ans=(ans+a.x[5][i]*val[i]%mod)%mod;
    }
    cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    // cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
    return 0;
}