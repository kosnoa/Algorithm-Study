/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

queue<pair<ll, ll>> qp;
bool check[1000005];
ll n, k;

ll bfs(int x)
{
    qp.push({x, 0});

    while (!qp.empty())
    {
        pair<ll, ll> cur = qp.front();
        qp.pop();

        if (cur.first == k)
        {
            return cur.second;
        }

        ll x1 = cur.first + 1;
        ll x2 = cur.first * 2;

        if (x1 <= 1000000 && !check[x1])
        {
            check[x1] = true;
            qp.push({x1, cur.second + 1});
        }

        if (x2 <= 1000000 && !check[x2])
        {
            check[x2] = true;
            qp.push({x2, cur.second + 1});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> k;

    cout << bfs(n) << '\n';

    return 0;
}