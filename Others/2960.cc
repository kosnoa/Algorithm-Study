/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
int n, k, cnt;
int arr[1001];

int primeNum()
{
    for (int i = 2; i <= n; i++)
    {
        arr[i] = i;
    }

    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == 0)
        {
            continue;
        }

        arr[i] = 0;
        cnt++;

        for (int j = i * i; j <= n; j += i)
        {
            if (arr[j] == 0)
            {
                continue;
            }
            arr[j] = 0;
            cnt++;
            if (cnt == k)
            {
                return j;
            }
        }

        if (cnt == k)
        {
            return i;
        }
    }



    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> k;

    int ans = primeNum();

    cout << ans << '\n';

    return 0;
}