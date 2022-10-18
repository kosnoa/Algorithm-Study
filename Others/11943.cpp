/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int ans = (b + c) < (a + d) ? (b + c) : (a + d);
    cout << ans << '\n';

    return 0;
}