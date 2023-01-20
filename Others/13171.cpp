/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
ll a, x, ans;
ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> a >> x;
    ans = 1L;
    a %= mod;

    while (x > 0)
    {
        if ((x & 1) == 1)
        {
            ans = ans * a % mod;
        }

        x >>= 1;
        a = a * a % mod;
    }

    cout << ans << '\n';

    return 0;
}