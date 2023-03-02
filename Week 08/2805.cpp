/* Code By kosnoa
GitHub : kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
ll n, m;

ll BinarySearch(vector<ll> v)
{
    ll low = 0;
    ll high = v[n - 1];
    ll mid;
    ll res1 = 0;
    ll tmp1 = -1;
    ll res2 = 0;
    ll tmp2 = 1e9;
    
    while (low < high)
    {
        ll sum = 0;
        mid = (low + high) / 2;

        for (ll i = 0; i < n; i++)
        {
            if (v[i] > mid)
            {
                sum += (v[i] - mid);
            }
        }

        if (sum < m)
        {
            if (tmp1 < sum)
            {
                res1 = mid;
                tmp1 = sum;
            }
            high = mid - 1;
        }
        else if (sum > m)
        {
            if (tmp2 > sum)
            {
                res2 = mid;
                tmp2 = sum;
            }
            low = mid + 1;
        }
        else
        {
            return mid;   
        }
    }

    if (m - tmp1 > tmp2 - m)
    {
        return res2;
    }
    else if(m - tmp1 < tmp2 - m)
    {
        return res1;
    }
    else
    {
        return res2;
    }

}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;

    vector<ll> v(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    cout << BinarySearch(v) << '\n';

    return 0;
}