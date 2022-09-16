/* Code By kosnoa
GitHub: kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

queue<pair<ll, ll>> qp;
bool check[100005];
ll arr[100005];
vector<ll> v;
ll n, k;

int bfs(int x)
{
    qp.push({x, 0});

    while (!qp.empty())
    {
        pair<ll, ll> cur = qp.front();
        check[cur.first] = true;
        qp.pop();

        if (cur.first == k)
        {
            while (cur.first != n)
            {
                v.push_back(cur.first);
                cur.first = arr[cur.first];
            }
            return cur.second;
        }

        int x1 = cur.first - 1;
        int x2 = cur.first + 1;
        int x3 = cur.first * 2;

        if (x1 >= 0 && !check[x1])
        {
            check[x1] = true;
            qp.push({x1, cur.second + 1});
            arr[x1] = cur.first;
        }

        if (x2 <= k && !check[x2])
        {
            check[x2] = true;
            qp.push({x2, cur.second + 1});
            arr[x2] = cur.first;
        }

        if (x3 <= k + 1 && !check[x3])
        {
            check[x3] = true;
            qp.push({x3, cur.second + 1});
            arr[x3] = cur.first;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> k;

    cout << bfs(n) << '\n';
    cout << n << ' ';
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i] << ' ';
    }

    return 0;
}