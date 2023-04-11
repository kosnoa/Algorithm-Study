/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
ll n, point;
vector<int> vec[50001];
vector<int> level[50001];

void find_level(int a, int i)
{
    level[a].push_back(i);

    for (int j = 0; j < vec[a].size(); j++)
    {
        find_level(vec[a][j], i + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    find_level(1, 1);
    for (int i = 1; i <= n; i++)
    {
        cout << level[i][0] << ' ';
    }

    // int T;
    // cin >> T;
    // while (T--)
    // {
    //     point = 0;
    //     int a, b;
    //     cin >> a >> b;
    // }

    return 0;
}