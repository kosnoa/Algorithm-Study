/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int n, c;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> c;
    int x = n, y = n;

    for (int i = 0; i < c; i++)
    {
        int a, b;
        cin >> a >> b;
        if(x <= a || y <= b)
        {
            continue;
        }

        if (x * b > y * a)
        {
            y = b;
        }
        else
        {
            x = a;
        }
    }

    cout << x * y;

    return 0;
}