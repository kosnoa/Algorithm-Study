/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
vector<ll> v;
ll n, l, r, val = 2000000002;
pair<ll, ll> p;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;

    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());


    r = n-1;

    while (l < r)
    {
        ll sum = v[l] + v[r];

        if (val > abs(sum))
        {
            val = abs(sum);
            p = make_pair(v[l], v[r]);
        }

        if (sum == 0)
        {
            break;
        }   

        if (sum < 0)
        {
            l++;
        }
        else
        {
            r--;
        }
    }


    cout << p.first << ' ' << p.second << '\n';

    return 0;
}