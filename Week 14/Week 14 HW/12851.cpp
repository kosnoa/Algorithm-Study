/* Code By kosnoa
GitHub: kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

queue<pair<ll, ll>> qp;
bool check[100005];
ll n, k, m = 1000000000, cnt = 0;

void bfs(int x)
{
    qp.push({x, 0});

    while (!qp.empty())
    {
        pair<ll, ll> cur = qp.front();
        qp.pop();
        check[cur.first] = true;

        if (cur.first == k && cur.second <= m)
        {
            if (cur.second < m)
            {
                m = cur.second;
                cnt = 1;
                continue;
            }

            if (cur.second == m)
            {
                m = cur.second;
                cnt++;
                continue;
            }
        }

        int x1 = cur.first - 1;
        int x2 = cur.first + 1;
        int x3 = cur.first * 2;

        if (x1 >= 0 && !check[x1])
        {
            qp.push({x1, cur.second + 1});
        }

        if (x2 <= k && !check[x2])
        {
            qp.push({x2, cur.second + 1});
        }

        if (x3 <= k + 1 && !check[x3])
        {
            qp.push({x3, cur.second + 1});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> k;

    bfs(n);

    cout << m << '\n';
    cout << cnt << '\n';

    return 0;
}