/* Code By kosnoa
GitHub : kosnoa */


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int l, a, b, c, d, tmp1, tmp2;
    cin >> l >> a >> b >> c >> d;

    tmp1 = a/c;
    a %=c;

    if (a>0)
    {
        tmp1++;
    }

    tmp2 = b/d;
    b %= d;

    if (b>0)
    {
        tmp2++;
    }

    cout << (tmp1 < tmp2 ? l - tmp2 : l - tmp1) << '\n';

    return 0;
}