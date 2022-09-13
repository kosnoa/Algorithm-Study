/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

queue <pair<ll, ll>> qp;
bool check[500005];
ll n, k;

// 무한출력
// 케이스를 나눠서 계산

int bfs(int x)
{
    qp.push({x, 0});

    while (!qp.empty())
    {
        ll tmp = k;
        pair<ll, ll> cur = qp.front();
        qp.pop();

        for (int i = 1; i <= cur.second; i++)
        {
            tmp += i;
        }

        // cout << cur.first << ' ' << cur.second << ' ' << tmp;

        if (cur.first == tmp && tmp > 500000)
        {
            return cur.second;
        }

        if (cur.first > 500000 || cur.first < 0)
        {
            return -1;
        }

        int x1 = cur.first - 1;
        int x2 = cur.first + 1;
        int x3 = cur.first * 2;

        if (x1 >= 0 && !check[x1])
        {
            check[x1] = true;
            qp.push({x1, cur.second + 1});
        }

        if (x2 <= tmp && !check[x2])
        {
            check[x2] = true;
            qp.push({x2, cur.second + 1});
        }

        if (x3 <= 500000 && !check[x3])
        {
            check[x3] = true;
            qp.push({x3, cur.second + 1});
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