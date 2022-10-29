/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
vector<tuple<ll, ll, ll, ll, ll>> vt(61);
bool check[61];
int n;

void bfs()
{
    queue<tuple<ll, ll, ll, ll, ll, ll>> qt;
    qt.push({0, 0, 0, 0, 0, 0});

    while (!qt.empty())
    {
        tuple<ll, ll, ll, ll, ll, ll> cur = qt.front();
        qt.pop();

        if (get<5>(cur) < 0 || get<5>(cur) > 60)
        {
            continue;
        }

        if (check[get<5>(cur)])
        {
            continue;
        }
        else
        {
            check[get<5>(cur)] = true;
            vt[get<5>(cur)] = (make_tuple(get<0>(cur), get<1>(cur), get<2>(cur), get<3>(cur), get<4>(cur)));
            qt.push({get<0>(cur), get<1>(cur), get<2>(cur), get<3>(cur), get<4>(cur) + 1, get<5>(cur) - 1});
            qt.push({get<0>(cur), get<1>(cur), get<2>(cur), get<3>(cur) + 1, get<4>(cur), get<5>(cur) + 1});
            qt.push({get<0>(cur), get<1>(cur), get<2>(cur) + 1, get<3>(cur), get<4>(cur), get<5>(cur) - 10});
            qt.push({get<0>(cur), get<1>(cur) + 1, get<2>(cur), get<3>(cur), get<4>(cur), get<5>(cur) + 10});
            qt.push({get<0>(cur) + 1, get<1>(cur), get<2>(cur), get<3>(cur), get<4>(cur), get<5>(cur) + 60});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    bfs();

    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;

        if (n <= 60)
        {
            tuple<ll, ll, ll, ll, ll> tmp = vt[n];

            cout << get<0>(tmp) << ' ' << get<1>(tmp) << ' ' << get<2>(tmp) << ' ' << get<3>(tmp) << ' ' << get<4>(tmp) << '\n';
        }
        else
        {
            int k = n / 60;
            tuple<ll, ll, ll, ll, ll> tmp = vt[n % 60];
            cout << get<0>(tmp) + k << ' ' << get<1>(tmp) << ' ' << get<2>(tmp) << ' ' << get<3>(tmp) << ' ' << get<4>(tmp) << '\n';
        }
        
    }

    return 0;
}