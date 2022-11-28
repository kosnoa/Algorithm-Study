/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

int modInverse(int a, int m)
{
    for (int i=1; i<m; i++)
    {
        if((a*i) % m == 1)
        {
            return i;
        }
    }
}

int flt(int base, int exp, int mod)
{
    int res = 1;
    while(exp)
    {
        if (exp & 1)
        {
            res = (res * base) % mod;
        }
    }

    return res;
}

tuple<int, int, int> xGCD(int a, int b)
{
    if (b == 0)
    {
        return make_tuple(a, 1, 0);
    }

    int g, x, y;
    tie(g, x, y) = xGCD(b, a % b);
    return make_tuple(g, y, x - (a / b) * y);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    return 0;
}