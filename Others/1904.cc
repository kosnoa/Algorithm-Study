/* Code By kosnoa
GitHub : kosnoa */


#pragma GCC optimize("Ofast")
#pragma GCC ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
ll dp[1000001];
int mod = 15746;
int n;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    dp[0] = 1;
    dp[1] = 2;

    for (int i=2; i<=n; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2])%mod;
    }

    cout << dp[n-1] << '\n';


    return 0;
}