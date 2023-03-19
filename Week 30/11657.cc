/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

struct cities
{
    int a;
    int b;
    int c;
};
vector<cities> v;
ll arr[501];
int n, m;

void bellman_ford()
{
    arr[1] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            int start = v[j].a;
            int finish = v[j].b;
            int cost = v[j].c;

            if (arr[start] == 1e9)
                continue;

            if (arr[finish] > arr[start] + cost)
            {
                arr[finish] = arr[start] + cost;
            }
        }
    }

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            int start = v[j].a;
            int finish = v[j].b;
            int cost = v[j].c;

            if (arr[start] == 1e9)
                continue;

            if (arr[finish] > arr[start] + cost)
            {
                cout << -1;
                return;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == 1e9)
            cout << -1 << '\n';
        else
            cout << arr[i] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int p, q, r;
        cin >> p >> q >> r;
        v.push_back({p, q, r});
    }

    fill(arr, arr + 501, 1e9);

    bellman_ford();

    return 0;
}