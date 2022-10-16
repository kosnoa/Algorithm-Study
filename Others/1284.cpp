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

    int n;

    while (1)
    {
        cin >> n;

        int k = 2;

        if (n == 0)
        {
            break;
        }

        while (1)
        {
            if (n % 10 == 1)
            {
                k += 2;
            }
            else if (n % 10 == 0)
            {
                k += 4;
            }
            else
            {
                k += 3;
            }

            if (n < 10)
            {
                break;
            }

            n /= 10;
            k += 1;
        }

        cout << k << '\n';
    }

    return 0;
}