#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 500010;
const ll mod = 1e9 + 7;
int dp[(1 << 16)][26];
string w[20];
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    for (int s = 0; s < (1 << n); s++)
    {
        for (int c = 0; c < 26; c++)
        {
            for (int i = 0; i < n; i++)
            {
                if (((s >> i) & 1) && ((w[i][0] - 'a') == c))
                {
                    dp[s][c] |= (dp[s ^ (1 << i)][w[i].back() - 'a'] == 0);
                }
            }
        }
    }
    for (int c = 0; c < 26; c++)
    {
        if (dp[(1 << n) - 1][c] == 1)
        {
            cout << "First\n";
            return;
        }
    }
    cout << "Second\n";
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