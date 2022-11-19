/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
ll n, m, l, r, sum, len;
ll arr[100005];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    len = n + 1;

    while (r <= n)
    {
        if (sum < m)
        {
            sum += arr[r];
            r++;
        }
        else
        {
            if (len >= r - l)
            {
                len = r - l;
            }

            sum -= arr[l];
            l++;
        }
    }

    if (len == n + 1)
    {
        cout << 0 << '\n';
    }
    else
    {
        cout << len << '\n';
    }

    return 0;
}