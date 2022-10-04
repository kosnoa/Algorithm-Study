/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

ll mod = 45678;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    ll sum = 5;

    if (n > 1)
    {
        sum = 5 + (7 % mod + (n - 1 * 3) % mod) % mod;
    }

    cout << sum << '\n';

    return 0;
}