/* Code By kosnoa
GitHub: kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
ll dp[10001];
ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        if (n % 3)
        {
            cout << "0" << '\n';
            continue;
        }

        dp[0] = 1;
        dp[3] = 3;
        dp[6] = 13;

        for (int i = 9; i <= n; i += 3)
        {
            dp[i] = (((5 * dp[i - 3]) % mod) + mod - ((3 * dp[i - 6]) % mod) + dp[i - 9]) % mod;
        }
        cout << dp[n] << '\n';

        memset(dp, 0, sizeof(dp));
    }

    return 0;
}