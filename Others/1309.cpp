/* Code By kosnoa
GitHub : kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

llu dp[1000002] = {3, 7};

int main()
{

    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        dp[i + 2] = (2 * dp[i + 1] + dp[i]) % 9901;
    }

    cout << dp[n-1] << '\n';

    return 0;
}