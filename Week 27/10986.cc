/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
ll n, m, cnt;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    // (save[j] - save[i]) ≡ 0 (mod m)  (j >= i)
    // save[j] % m == save[i] % m

    cin >> n >> m;
    vector<ll> v(m);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        sum += tmp;
        v[sum % m]++;
    }

    for (auto i : v)
    {
        cnt += i * (i - 1) / 2;
    }

    cout << v[0] + cnt << '\n';

    return 0;
}