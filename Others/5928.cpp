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

    int d, h, m;
    cin >> d >> h >> m;

    int time1 = 11 * 60 * 24 + 11 * 60 + 11;
    int time2 = d * 60 * 24 + h * 60 + m;
    int min = time2 - time1;

    cout << (min < 0 ? -1 : min) << '\n';

    return 0;
}