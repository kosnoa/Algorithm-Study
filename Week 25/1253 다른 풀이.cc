/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
vector<ll> v;
int n, res;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    v = vector<ll>(n);
    for (auto &i : v)
    {
        cin >> i;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        ll find = v[i];
        int left = 0;
        int right = n - 1;
        while (left != right)
        {
            if (v[left] + v[right] == find)
            {
                if (left != i && right != i)
                {
                    res++;
                    break;
                }
                else if (left == i)
                {
                    left++;
                }
                else if (right == i)
                {
                    right--;
                }
            }
            else if (v[left] + v[right] < find)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    cout << res << '\n';

    return 0;
}