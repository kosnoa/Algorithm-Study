/* Code By kosnoa
GitHub: kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

queue<pair<ll, ll>> qp;
bool check[100005];
ll n, k;

int bfs(int x)
{
    qp.push({x, 1});

    while (!qp.empty())
    {
        pair<ll, ll> cur = qp.front();
        qp.pop();

        if (cur.first == k)
        {
            return cur.second - 1;
        }

        int x1 = cur.first - 1;
        int x2 = cur.first + 1;
        int x3 = cur.first * 2;

        if (x1 >= 0 && !check[x1])
        {
            check[x1] = true;
            qp.push({x1, cur.second+1});
        }

        if (x2 <= k && !check[x2])
        {
            check[x2] = true;
            qp.push({x2, cur.second+1});
        }

        if (x3 <= k + 1 && !check[x3])
        {
            check[x3] = true;
            qp.push({x3, cur.second+1});
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