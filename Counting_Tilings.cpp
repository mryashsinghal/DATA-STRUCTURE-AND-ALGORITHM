#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v vector<ll>
#define inf 1e9
#define linf 1e18
#define F(n) for (ll i = 0; i < n; i++)
#define pb push_back

int dp[1000][1 << 10];

void generate_next_masks(int curr_mask, int i, int next_mask, int n, vector<int> &next_masks)
{
    if (i == n)
    {
        next_masks.push_back(next_mask);
        return;
    }
    if ((curr_mask & (1 << i)) != 0)
    {
        generate_next_masks(curr_mask, i + 1, next_mask, n, next_masks);
    }
    if (i < n - 1)
    {
        if (((curr_mask & (1 << i)) == 0) && ((curr_mask & (1 << (i + 1))) == 0))
        {
            generate_next_masks(curr_mask, i + 2, next_mask, n, next_masks);
        }
    }
    if ((curr_mask & (1 << i)) == 0)
    {
        generate_next_masks(curr_mask, i + 1, (next_mask ^ (1 << i)), n, next_masks);
    }
}
int solve(int col, int mask, const int n, const int m)
{
    int mod = 1e9 + 7;
    if (col == m)
    {
        if (mask == 0)
        {
            return 1;
        }
        return 0;
    }
    if (dp[col][mask] != -1)
    {
        return dp[col][mask];
    }
    int answer = 0;
    vector<int> next_masks;
    generate_next_masks(mask, 0, 0, n, next_masks);
    for (int next_mask : next_masks)
    {
        answer = (answer + solve(col + 1, next_mask, n, m)) % mod;
    }

    return dp[col][mask] = answer;
}

void sol()
{
    memset(dp, -1, sizeof(dp));
    ll n, m;
    cin >> n >> m;
    int ans = solve(0, 0, n, m);
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sol();
    return 0;
}
