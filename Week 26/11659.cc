/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n, m;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;
    vector<int> v(n);
    vector<int> sum(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sum[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        sum[i] += v[i - 1] + sum[i - 1];
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << sum[b] - sum[a - 1] << '\n';
    }

    return 0;
}