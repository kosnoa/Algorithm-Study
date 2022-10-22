/* Code By kosnoa
GitHub : kosnoa */

#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

bool prime[7368788];
vector<int> v;
int k;

void primeNum()
{
    for (int i = 2; i <= 7368787; i++)
    {
        if (prime[i])
        {
            continue;
        }

        for (int j = i + i; j <= 7368787; j += i)
        {
            prime[j] = true;
        }
    }

    for (int i = 2; i <= 7368787; i++)
    {
        if (!prime[i])
        {
            v.push_back(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cin >> k;

    primeNum();

    cout << v[k - 1] << '\n';

    return 0;
}