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
    int res = n + m + k;
    
    if (res < 100)
    {

        if (n < m && n < k)
        {
            cout << "Soongsil" << '\n';
        }
        else if (m < n && m < k)
        {
            cout << "Korea" << '\n';
        }
        else if (k < n && k < m)
        {
            cout << "Hanyang" << '\n';
        }
    }
    else
    {
        cout << "OK" << '\n';
    }

    return 0;
}