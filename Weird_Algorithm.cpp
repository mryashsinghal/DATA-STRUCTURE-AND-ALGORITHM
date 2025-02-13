#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector<ll>
#define mod 1e9 + 7
#define inf 1e9
#define linf 1e18

void sol()
{
    long long n;
    cin >> n;
    cout << n << " ";
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            cout << n / 2 << " ";
            n /= 2;
        }
        else
        {
            cout << n * 3 + 1 << " ";
            n = n * 3 + 1;
        }
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    //{
    sol();
    //}
    return 0;
}
