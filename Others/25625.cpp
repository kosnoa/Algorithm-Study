/* Code By kosnoa
GitHub : kosnoa */


#pragma GCC optimize("Ofast")
#pragma GCC ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int x, y;
    cin >> x >> y;

    if (y >= x)
    {
        cout << y-x << '\n';
    }
    else
    {
        cout << x+y << '\n';
    }

    return 0;
}