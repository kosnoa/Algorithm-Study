/* Code By kosnoa
GitHub: kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

queue<pair<ll, ll>> qp;
ll n;

int bfs(ll x)
{
    qp.push({x, 1});

    while (!qp.empty())
    {
        pair<ll, ll> cur = qp.front();
        qp.pop();

        if (cur.first == 1)
        {
            return cur.second-1;
        }

        if (cur.first % 3 == 0 && cur.first > 1)
        {
            qp.push({cur.first / 3, cur.second+1});
        }

        if (cur.first % 2 == 0 && cur.first > 1)
        {
            qp.push({cur.first / 2, cur.second+1});
        }

        qp.push({cur.first-1, cur.second+1});
        
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    cout << bfs(n) << '\n';

    return 0;
}