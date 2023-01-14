/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
vector<int> v;
int n, k, l, cnt;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    while (l < n)
    {
        int tmp = 0;
        int r = l;
        bool check = false;
        while (tmp < k)
        {
            if (r >= n)
            {
                check = true;
                break;
            }

            if (tmp + v[r] > n)
            {
                break;
            }
            else
            {
                tmp += v[r];
                r++;
            }
        }

        if (check)
        {
            l++;
            continue;
        }

        if (tmp == k) 
        {
            cnt++, l++;
        }
        else 
        {
            l++;
        }

        
    }

    cout << cnt << '\n';

    return 0;
}