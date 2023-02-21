/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n, m, cnt;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    // (save[j] - save[i]) ≡ 0 (mod m)  (j >= i)
    // save[j] % m == save[i] % m

    cin >> n >> m;
    vector<ll> v(n);
    vector<ll> save(n + 1);

    for (auto& i : v)
    {
        cin >> i;
    }

    for (int i = 1; i <= n; i++)
    {
        save[i] = v[i - 1] + save[i - 1];
    }

    



    cout << cnt << '\n';

    return 0;
}