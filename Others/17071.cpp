/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

queue<tuple<ll, ll, ll>> qt;
bool check[500005];
ll n, k;

// 무한출력

int bfs(int x)
{
    qt.push(make_tuple(x, 0, 0));

    while (!qt.empty())
    {
        ll tmp = k;
        tuple<ll, ll, ll> cur = qt.front();
        qt.pop();

        for (int i = 1; i <= get<2>(cur); i++)
        {
            tmp += i;
        }

        cout << get<0>(cur) << ' ' << get<1>(cur) << ' ' << get<2>(cur) << ' ' << tmp << '\n';

        if (get<0>(cur) == tmp)
        {
            return get<1>(cur);
        }

        if (get<0>(cur) > 500000 || get<0>(cur) < 0)
        {
            return -1;
        }

        int x1 = get<0>(cur) - 1;
        int x2 = get<0>(cur) + 1;
        int x3 = get<0>(cur) * 2;

        if (x1 >= 0 && !check[x1])
        {
            check[x1] = true;
            qt.push(make_tuple(x2, get<1>(cur) + 1, get<2>(cur) + 1));
        }

        if (x2 <= tmp && !check[x2])
        {
            check[x2] = true;
            qt.push(make_tuple(x2, get<1>(cur) + 1, get<2>(cur) + 1));
        }

        if (x3 <= tmp + 1 && !check[x3])
        {
            check[x3] = true;
            qt.push(make_tuple(x3, get<1>(cur) + 1, get<2>(cur) + 1));
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> k;

    cout << bfs(n) << '\n';

    return 0;
}