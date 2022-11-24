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

    int t = 1;

    while (1)
    {
        int n;
        cin >> n;

        if (n == 0)
        {
            break;
        }

        int n1 = n * 3;
        int n2 = 0;
        int n3 = 0;
        int n4 = 0;

        if (n1 % 2 == 0)
        {
            n2 = n1 / 2;
        }
        else
        {
            n2 = (n1 + 1) / 2;
        }

        n3 = 3 * n2;
        n4 = n3 / 9;

        if (n1 % 2 == 0)
        {
            cout << t << ". "
                 << "even " << n4 << '\n';
        }
        else
        {
            cout << t << ". "
                 << "odd " << n4 << '\n';
        }

        t++;
    }

    return 0;
}