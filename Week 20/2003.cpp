/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
ll arr[10005];
ll n, m, l, r, sum, cnt;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    while (l < n)
    {

        if (sum > m)
        {
            sum -= arr[l];
            l++;
        }
        else if (sum < m)
        {
            if (r < n)
            {
                sum += arr[r]; 
                r++;
            }
            else
            {
                sum -= arr[l];
                l++;
            }
            
        }
        else
        {
           cnt++;
           sum -= arr[l];
           l++; 
        }
    }

    cout << cnt << '\n';

    return 0;
}