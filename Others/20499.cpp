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

    int k,d,a;
    char no;
    cin >> k >> no >> d >> no >> a;

    if (d == 0)
    {
        cout << "hasu" << '\n';
    }
    else
    {
        if (k+a < d)
        {
            cout << "hasu" << '\n';
        }
        else
        {
            cout << "gosu" << '\n';
        }
    }


    return 0;
}