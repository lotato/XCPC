#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 500010;
const ll mod = 1e9 + 7;
void solve()
{
    ll a, b;
    cin >> a >> b;
    if (b * 2 >= a)
    {
        double ans = 1.0 * a;
        printf("%.10f\n", ans);
    }
    else
    {
        double c = (1.0 * a) / (2.0 * b);
        c *= c;
        double x = floor(cbrt(c)) - 1;
        double ans = min(x * b + a / pow(x + 1, 1.0 / 2), (x + 1) * b + a / pow(x + 2, 1.0 / 2));
        printf("%.10f\n", ans);
    }
}
int main()
{
    // ios::sync_with_stdio(false);
    int t = 1;
    // cin>>t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}