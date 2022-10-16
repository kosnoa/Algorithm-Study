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

    int a, b;

    while(1)
    {
        cin >> a >> b;

        if (a==0 && b==0)
        {
            break;
        }
        
        cout << a+b << '\n';
    }

    return 0;
}