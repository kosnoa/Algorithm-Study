/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
vector<ll> neg;
vector<ll> pos;
bool zero;
int n, ans;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a > 0)
        {
            if (a == 1)
            {
                ans += a;
            }
            else
            {
                pos.push_back(a);
            }
        }
        else if (a < 0)
        {
            neg.push_back(a);
        }
        else
        {
            zero = true;
        }
    }

    sort(pos.rbegin(), pos.rend());
    sort(neg.begin(), neg.end());

    if (neg.size() % 2 == 1)
    {
        if (!zero)
        {
            ans += neg.back();
            neg.pop_back();
        }
        else
        {
            neg.pop_back();
        }
    }

    if (pos.size() % 2 == 1)
    {
        ans += pos.back();
        pos.pop_back();
    }

    for (int i = 1; i < pos.size(); i += 2)
    {
        ans += pos[i - 1] * pos[i];
    }

    for(int i = 1; i < neg.size(); i += 2)
    {
        ans += neg[i - 1] * neg[i];
    }

    cout << ans;

    return 0;
}