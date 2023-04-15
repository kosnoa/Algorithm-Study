/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n, d, k, c, ans;
bool check[30001];
int arr[30001];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> d >> k >> c;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        memset(check, false, sizeof(check));
        int multi = 0;
        int coupon = 1;
        for (int j = i; j < k + i; j++)
        {
            int t = j % n;
            if (!check[arr[t]])
            {
                check[arr[t]] = true;
            }
            else
            {
                multi++;
            }

            if (arr[t] == c)
            {
                coupon = 0;
            }
        }

        if (ans < k - multi + coupon)
        {
            ans = k - multi + coupon;
        }
    }

    cout << ans << '\n';

    return 0;
}