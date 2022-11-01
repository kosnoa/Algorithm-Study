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

    int n, f;
    cin >> n >> f;
    n = n - n % 100;
    for (int i=n;; i++)
    {
        if(i%f == 0)
        {
            if (i%100 < 10)
            {
                cout << "0";
            }
            cout << i%100 << '\n';
            break;
        }
    }

    return 0;
}