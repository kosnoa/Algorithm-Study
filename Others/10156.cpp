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

    int n, m, k;
    cin >> n >> m >> k;

    int tmp = n*m - k;

    if (tmp <= 0)
    {
        cout << "0" << '\n';
    }
    else
    {
        cout << tmp << '\n';
    }

    return 0;
}