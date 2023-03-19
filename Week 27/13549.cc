/* Code By kosnoa
GitHub: kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

priority_queue<pair<ll, ll>> pq;
bool check[200005];
ll n, k;

int bfs(int x)
{
    pq.push({0, x});

    while (!pq.empty())
    {
        pair<ll, ll> cur = pq.top();
        pq.pop();

        if (abs(cur.second) == k)
        {
            if (x == 0 || x == 1)
            {
                if (k == 0 || k == 1)
                {
                    return abs(cur.first);
                }
                else
                {
                    return abs(cur.first) - 1;
                }
            }
            else
            {
                return abs(cur.first);
            }
        }

        int x1 = abs(cur.second) - 1;
        int x2 = abs(cur.second) + 1;
        int x3 = abs(cur.second) * 2;

        if (x1 >= 0 && !check[x1])
        {
            check[x1] = true;
            pq.push({-1 * (abs(cur.first) + 1), -1 * abs(x1)});
        }

        if (x2 <= k && !check[x2])
        {
            check[x2] = true;
            pq.push({-1 * (abs(cur.first) + 1), -1 * abs(x2)});
        }

        if (x3 <= k + 1 && !check[x3])
        {
            check[x3] = true;
            pq.push({-1 * abs(cur.first), -1 * abs(x3)});
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