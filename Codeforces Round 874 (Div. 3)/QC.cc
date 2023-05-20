/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
ll arr[200001];
ll n;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        ll min_even = 1e16, min_odd = 1e16;
        ll cnt1 = 0, cnt2 = 0;
        bool check1 = false, check2 = false;
        cin >> n;
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] % 2 == 1)
            {
                cnt1++;
                min_odd = min(min_odd, arr[i]);
            }
            else
            {
                cnt2++;
                min_even = min(min_even, arr[i]);
            }
        }

        if (min_even == 1e16)
        {
            check1 = true;
        }

        if (min_odd == 1e16)
        {
            check2 = true;
        }

        if(cnt1 != 0 && cnt2 == 0)
        {
            cout << "yes\n";
            continue;
        }
        

        if(cnt1 == 0 && cnt2 != 0)
        {
            cout << "yes\n";
            continue;
        }

        vector<int> evens(n);
        vector<int> odds(n);

        if (!check2)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i] % 2 == 0)
                {
                    evens[i] = arr[i];
                }
                else
                {
                    evens[i] = arr[i] - min_odd;
                }
            }
        }

        if (!check1)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i] % 2 == 1)
                {
                    odds[i] = arr[i];
                }
                else
                {
                    odds[i] = arr[i] - min_odd;
                }
            }
        }

        sort(evens.begin(), evens.end());
        sort(odds.begin(), odds.end());

        if(evens[0] <= 0 && odds[0] <= 0)
        {
            cout << "no\n";
        }
        else
        {
            cout << "yes\n";
        }
    }

    return 0;
}