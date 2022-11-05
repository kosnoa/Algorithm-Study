/* Code By kosnoa
GitHub : kosnoa */


#pragma GCC optimize("Ofast")
#pragma GCC ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
ll n, l=1, r=1, sum, cnt;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;


    while (l <= n)
    {
        if (sum > n)
        {
            sum -= l;
            l++;
        }
        else if (sum < n)
        {
            if (r <= n)
            {
                sum += r;
                r++;
            }
            else
            {
                sum -= l;
                l++;
            }
        }
        else
        {;
            cnt++;
            sum -= l;
            l++;
        }
    }

    cout << cnt << '\n';

    return 0;
}