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

    ll n, cnt = 0;
    cin >> n;

    for (ll i = 2023; i <= n; i++)
    {
        deque<char> dq;
        string str = to_string(i);

        for (ll j = 0; j < str.size(); j++)
        {
            if (str[j] == '2')
            {
                if (dq.empty())
                {
                    dq.push_back(str[j]);
                }
                else
                {
                    if (dq.back() == '0' && dq.size() == 2)
                    {
                        dq.push_back(str[j]);
                    }
                }
            }
            else if (str[j] == '0'  && dq.size() == 1)
            {
                if (dq.back() == '2')
                {
                    dq.push_back(str[j]);
                }
            }
            else if (str[j] == '3' && dq.size() == 3)
            {
                if (dq.back() == '2')
                {
                    dq.push_back(str[j]);
                }
            }
        }

        if (dq.size() == 4)
        {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}