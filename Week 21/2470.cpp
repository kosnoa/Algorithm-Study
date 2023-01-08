/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
vector<ll> v;
ll n, l, r = 1, val = 2000000002;
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

    r = v.size()-1;

    while (l != r)
    {
        if (abs(abs(v[r]) - abs(v[l])) < val)
        {
            val = abs(abs(v[r]) - abs(v[l]));
            
            p = make_pair(v[r], v[l]);
        }
        else
        {
            r--;
        }
        
    }

    cout << p.first << ' ' << p.second << '\n';

    return 0;
}