/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return n != 1;
}

ll flt(ll base, ll exp, ll mod)
{
    ll res = 1;
    while (exp)
    {
        if (exp & 1) // n%2 == 1 in bitwise, which is faster
        {
            res = (res * base) % mod;
        }
        base = base * base % mod;
        exp /= 2; // can also be written as n>>=1;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    while (1)
    {
        llu p, a;
        cin >> p >> a;

        if (p == 0 && a == 0)
        {
            break;
        }

        if (isPrime(p))
        {
            cout << "no\n";
        }
        else
        {
            if (flt(a, p, p) == a)
            {
                cout << "yes\n";
            }
            else
            {
                cout << "no\n";
            }
        }
    }

    return 0;
}
