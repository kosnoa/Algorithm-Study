/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
ll n, m, l, r, sum, cnt, len = -1;
vector<ll> v;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;

    for (ll i = 0; i < n; i++)
    {
        ll tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    while (l <= r)
    {
        if (r == n-1)
        {
            sum -= v[l];
            l++;

            if (sum == m && len == r-l)
            {
                cnt++;
            }
            else if (sum == m && len > r-l)
            {
                len = r-l;
                cnt=1;
            }
        }

        if (sum > m)
        {
            sum -= v[l];
            l++;
        }
        else if (sum < m)
        {
            if (r < n)
            {
                sum += v[r];
                r++;
            }
            else
            {
                sum -= v[l];
                l++;
            }
        }
        else
        {
            
        }
    }

    cout << cnt << '\n';

    return 0;
}