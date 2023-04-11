/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
ll n, point;
bool check[10001];

void dfs(ll a, vector<int> vec[])
{
    if (check[a])
    {
        point = a;
        return;
    }

    check[a] = true;

    for (int i = 0; i < vec[a].size(); i++)
    {
        dfs(vec[a][i], vec);
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        vector<int> vec[10001];
        fill(check, check + 10001, false);
        point = 0;
        cin >> n;
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            vec[v].push_back(u);
        }
        ll a, b;
        cin >> a >> b;

        dfs(a, vec);
        dfs(b, vec);

        cout << point << '\n';
    }

    return 0;
}