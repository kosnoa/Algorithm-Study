/* Code By kosnoa
GitHub: kosnoa */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll n, count = 0;
    cin >> n;

    vector<pair<ll, ll>> v;

    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        v.push_back({b, a});
    }

    sort(v.begin(), v.end());

    if (v[0].first == v[1].first)
    {
        count = v[1].second - v[0].second;
    }

    for (ll i = 1; i < n; i++)
    {
        if (i != n - 1 && v[i].first != v[i + 1].first)
        {
            if (v[i - 1].first != v[i].first)
            {
                i++;
            }
            else
            {
                count += v[i].second - v[i - 1].second;
                i++;

                if (i == n - 1)
                {
                    if (v[i - 1].first != v[i].first)
                    {
                        continue;
                    }
                    else
                    {
                        count += v[i].second - v[i - 1].second;
                    }
                }
                else
                {
                    if (v[i + 1].first == v[i].first)
                    {
                        count += v[i + 1].second - v[i].second;
                    }
                }
            }
        }
        else if (i == n - 1)
        {
            if (v[i - 1].first != v[i].first)
            {
                continue;
            }
            else
            {
                count += v[i].second - v[i - 1].second;
            }
        }
        else
        {
            if (v[i - 1].first != v[i].first || v[i + 1].first != v[i].first)
            {
                if (v[i - 1].first == v[i].first && v[i + 1].first != v[i].first)
                {
                    count += v[i].second - v[i - 1].second;
                }
                else if (v[i + 1].first == v[i].first && v[i - 1].first != v[i].first)
                {
                    count += v[i + 1].second - v[i].second;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                count += min(v[i].second - v[i - 1].second, v[i + 1].second - v[i].second);
            }
        }
    }

    cout << count << '\n';

    return 0;
}