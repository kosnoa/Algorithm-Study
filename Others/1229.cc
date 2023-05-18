/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
ll n;
ll d[] = {0, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 6, 2};
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    vector<ll> dp(n + 1);

    if (n < 13)
    {
        cout << d[n];
        exit(0);
    }

    for (ll i = 0; i < 13; i++)
    {
        dp[i] = d[i];
    }

    ll m = 1;
    ll cur = 0;
    vector<ll> vec;

    while (cur <= n)
    {
        cur = m * (2 * m - 1);
        vec.push_back(cur);
        m++;
    }

    vec.pop_back();

    for (ll i = 13; i <= n; i++)
    {
        ll val = 1e9;
        for (int j = 0; j < vec.size(); j++)
        {
            if (vec[j] > i)
            {
                break;
            }
            val = min(val, dp[i - vec[j]]);
        }

        dp[i] = val + 1;
    }

    cout << dp[n];

    return 0;
}