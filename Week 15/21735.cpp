/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

queue<tuple<ll, ll, ll>> q;
vector<ll> tmp;
vector<ll> v;
ll n, m;

void bfs()
{
    q.push(make_tuple(1, 0, 0)); // 눈덩이 사이즈, 현재 위치, 시간

    while (!q.empty())
    {
        tuple<ll, ll, ll> cur = q.front();
        q.pop();

        ll loc1 = get<1>(cur) + 1;
        ll loc2 = get<1>(cur) + 2;

        if (loc1 >= n || loc2 > n || get<2>(cur) >= m)
        {
            if (loc1 <= n && loc2 > n && get<2>(cur) >= m)
            {
                ll x1 = get<0>(cur) + v[loc1 - 1];
                tmp.push_back(x1);
                q.push(make_tuple(x1, loc1, get<2>(cur) + 1));
            }
            else
            {
                continue;
            }
        }
        else
        {
            ll x1 = get<0>(cur) + v[loc1 - 1];
            ll x2 = (get<0>(cur) / 2) + v[loc2 - 1];

            tmp.push_back(x1);
            tmp.push_back(x2);
            q.push(make_tuple(x1, loc1, get<2>(cur) + 1));
            q.push(make_tuple(x2, loc2, get<2>(cur) + 1));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        v.push_back(a);
    }

    bfs();

    sort(tmp.rbegin(), tmp.rend());

    cout << tmp[0] << '\n';

    return 0;
}