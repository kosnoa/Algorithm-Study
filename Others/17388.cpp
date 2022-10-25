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

    int a, b, c;
    cin >> a >> b >> c;
    
    if (a+b+c < 100)
    {
        int tmp = min(a, b, c);

        if (tmp == a)
        {
            cout << "Soongsil" << '\n';
        }
        else if (tmp == b)
        {
            cout << "Korea" << '\n';
        }
        else
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