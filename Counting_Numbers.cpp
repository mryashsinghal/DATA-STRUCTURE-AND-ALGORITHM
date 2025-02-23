#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v vector<ll>
#define mod 1e9 + 7
#define inf 1e9
#define linf 1e18
#define F(n) for (ll i = 0; i < n; i++)
#define pb push_back

ll dp[201][10][2][2];

ll solve(string &num, int n, int prev, bool lead, bool tight)
{

    if (n == 0)
    {
        return 1;
    }
    if (prev != -1 && dp[n][prev][lead][tight] != -1)
    {
        return dp[n][prev][lead][tight];
    }
    int ub = tight ? (num[num.length() - n] - '0') : 9;
    ll answer = 0;
    for (int i = 0; i <= ub; i++)
    {
        if (i != prev || lead == 1)
        {
            answer += solve(num, n - 1, i, (lead && i == 0), (tight && i == ub));
        }
    }
    return dp[n][prev][lead][tight] = answer;
}

void sol()
{
    ll a;
    string b;
    cin >> a;
    cin >> b;
    a = a - 1;
    string a2 = to_string(a);
    memset(dp, -1, sizeof(dp));
    ll ans = solve(a2, a2.length(), -1, 1, 1);
    memset(dp, -1, sizeof(dp));
    ll ans2 = solve(b, b.length(), -1, 1, 1);
    cout << ans2 - ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sol();
    return 0;
}
