/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n + 1);
    vector<int> sum(n + 1);
    fill(sum.begin(), sum.end(), 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        sum[i] = v[i] + sum[i - 1];
    }

    int val = 0;
    int x = 2;
    while (x < n) // A벌 B벌 꿀
    {
        int tmp = (sum[n] - v[x] - v[1]) + (sum[n] - sum[x]);
        if (tmp > val)
        {
            val = tmp;
        }
        x++;
    }

    int y = n - 1;
    while (y > 1) // 꿀 B벌 A벌
    {
        int tmp = (sum[n] - v[y] - v[n]) + sum[y - 1];
        if (tmp > val)
        {
            val = tmp;
        }
        y--;
    }

    int z = 2;
    while (z < n) // A벌 꿀 B벌
    {
        int tmp = (sum[z] - v[1]) + (sum[n - 1] - sum[z - 1]);
        if (tmp > val)
        {
            val = tmp;
        }
        z++;
    }

    cout << val << '\n';

    return 0;
}