/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int val = 1e9;
int res;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    vector<int> v(10);
    vector<int> sum(11);

    for (auto &i : v)
    {
        cin >> i;
    }

    sum[0] = 0;

    for (int i = 1; i <= 10; i++)
    {
        sum[i] += v[i - 1] + sum[i - 1];

        if (abs(sum[i] - 100) <= val)
        {
            if (sum[i] > res)
            {
                res = sum[i];
            }

            val = abs(sum[i] - 100);
        }
    }

    cout << res << '\n';

    return 0;
}