/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
ll dp[100001];
int n;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 2;
    dp[5] = 1;
    dp[6] = 2;
    dp[7] = 1;

    for (int i=8; i<=n; i++)
    {
        dp[i] = min(dp[i-1], min(dp[i-2], min(dp[i-5], dp[i-7]))) + 1;
    }

    cout << dp[n] << '\n';

    return 0;
}