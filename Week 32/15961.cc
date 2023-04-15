/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n, d, k, c;
int check[3000001];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> d >> k >> c;

    vector<int> sushi(n);

    for (auto &i : sushi)
    {
        cin >> i;
    }

    int l = 0;
    int r = 0;
    int res = 0;
    int flag = 0;
    int coupon = 1;

    while (l < n)
    {
        if (r - l == k)
        {
            int t = r % n;
            if (check[sushi[l]] > 1)
            {
                flag--;
                check[sushi[l]]--;
            }

            if (sushi[l] == c)
            {
                coupon = 1;
            }

            l++;

            check[sushi[t]]++;

            if (check[sushi[t]] > 1)
            {
                flag++;
            }

            if (sushi[t] == c)
            {
                coupon = 0;
            }
            r++;
        }
        else
        {
            check[sushi[r]]++;
            if (check[sushi[r]] > 1)
            {
                flag++;
            }

            if (sushi[r] == c)
            {
                coupon = 0;
            }

            r++;
        }

        res = max(res, k - flag + coupon);
    }

    cout << res << '\n';

    return 0;
}